#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct AVLNode_t
{
    char data[100];
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(char value[]) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    strcpy(newNode->data, value);
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, char value[]) {
    while (root != NULL) {
        if (strcmp(value, root->data) < 0)
            root = root->left;
        else if (strcmp(value, root->data) > 0)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node, char value[]) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(strcmp(value, node->data) < 0)
        node->left = _insert_AVL(avl,node->left,value);
    else if(strcmp(value, node->data) > 0)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && strcmp(value, node->left->data) < 0) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && strcmp(value, node->left->data) > 0) // 
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) > 0)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(value, node->right->data) < 0)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, char value[]) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (!strcmp(temp->data, value))
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, char value[]){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }
}

int cnt = 1;
void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        if(root->data)
        {
            printf("%d. %s\n", cnt, root->data);
            cnt++;
        }
        preorder(root->right);
    }
}

void _preorder(AVLNode *root, int size) {
    if (root) {
        _preorder(root->left, size);
        if(root->data)
        {
            printf("%s", root->data);
            cnt++;
            if(cnt < size)
            {
                printf("_");
            }
        }
        _preorder(root->right, size);
    }
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    char str[30000], tmp[30000];
    int idx = 0;
    while(scanf(" %s[^\n]", str) != EOF)
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(i == strlen(str) - 1 && str[i] != ' ') 
            {
                tmp[idx] = str[i]; 
                idx++; 
            }
            if(str[i] == ' ' || i == strlen(str) - 1)
            { 
                if(idx) avl_insert(&avlku, tmp); // 
                memset(tmp, 0, sizeof(tmp)); 
                idx = 0; // reset index
            }
            else{
                tmp[idx] = str[i];
                idx++; 
            }
        }
    }
    preorder(avlku._root);
    cnt = 0;
    _preorder(avlku._root, avlku._size);
}