#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode_t {
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t {
    AVLNode *_root;
    unsigned int _size;
} AVL;

AVLNode *_avl_createNode(int value) {
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int _max(int a, int b) { return (a > b) ? a : b; }

AVLNode *_rightRotate(AVLNode *pivotNode) {

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height =
        _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height =
        _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode) {

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height =
        _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height =
        _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node) { return _rightRotate(node); }

AVLNode *_rightCaseRotate(AVLNode *node) { return _leftRotate(node); }

AVLNode *_leftRightCaseRotate(AVLNode *node) {
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node) {
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode *node) {
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value) {

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 &&
        value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data) //
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

AVLNode *_findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode *_remove_AVL(AVLNode *node, int value) {
    if (node == NULL)
        return node;
    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else {
        AVLNode *temp;
        if ((node->left == NULL) || (node->right == NULL)) {
        temp = NULL;
        if (node->left == NULL)
            temp = node->right;
        else if (node->right == NULL)
            temp = node->left;

        if (temp == NULL) {
            temp = node;
            node = NULL;
        } else
            *node = *temp;

        free(temp);
    } else {
        temp = _findMinNode(node->right);
        node->data = temp->data;
        node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) { return avl->_root == NULL; }

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value) {
    if (!avl_find(avl, value)) {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl, int value) {
    if (avl_find(avl, value)) {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

void avlGetDistanceRange(AVLNode *root, int *min, int *max, int d) {
    if (root) {
        if (d < *min) {
            *min = d;
        } else if (d > *max) {
            *max = d;
    }

    avlGetDistanceRange(root->left, min, max, d - 1);
    avlGetDistanceRange(root->right, min, max, d + 1);
    }
}

void avlVerticalSum(AVLNode *root, int line, int *sum, int d) {
    if (root) {
        if (d == line) {
        *sum += root->data;
    }

    avlVerticalSum(root->left, line, sum, d - 1);
    avlVerticalSum(root->right, line, sum, d + 1);
    }
}

void avl_count_sum(AVLNode *root) {
    int min = 0, max = 0;
    avlGetDistanceRange(root, &min, &max, 0);

    for (int l = min; l <= max; l++) {
        int sum = 0;
        avlVerticalSum(root, l, &sum, 0);
        printf("%d ", sum);
    }
    printf("\n");
}

int main() {
    
    AVL *avl = malloc(sizeof(*avl));
    avl_init(avl);

    int n;
    scanf("%d", &n);

    while (n--) {
        char *command = (char *) malloc(5 * sizeof(char));
        scanf("%s", command);

    if (!strcmp(command, "insert")) {
        int num;
        scanf("%d", &num);
        avl_insert(avl, num);
    } 
    else if (!strcmp(command, "print")) {
        avl_count_sum(avl->_root);
        }
    }
}
