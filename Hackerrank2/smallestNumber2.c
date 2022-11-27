#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int id;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value, int id) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int id) {
    if (root == NULL) 
        return __bst__createNode(value, id);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, id);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, id);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int id) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, id);
        bst->_size++;
    }
}

void findMinimum(BSTNode *root, int x) {
	while(root != NULL)
	{
		if(root->key == x) {
			printf("%d", root->id);
			return;
		}
		
        else if(x < root->key) {
			root = root->left;
		} else{
			root = root->right;
		}
	}
}

int main() {
	BST set;
	bst_init(&set);

	int n, x, 
    input;

	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++) {
		scanf("%d", &input);
		bst_insert(&set, input, i);
	}

	if(bst_find(&set, x))
		findMinimum(set._root, x);
}