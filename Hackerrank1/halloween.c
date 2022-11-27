#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) {
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main() {
    int n, a[101];

    /*initialize*/
    Stack myStack;
    stack_init(&myStack);

    while(scanf("%d", &n) && n != 0) {
        int need = 0,
        i = 0;

        for(int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
 
        while(i < n) {
            while (!stack_isEmpty(&myStack) && stack_top(&myStack) == need + 1) {
                need++;
                stack_pop(&myStack);
            }

            if (a[i] != need + 1) {
                stack_push(&myStack, a[i]);
            } else need++;
            
            i++;
        }

        while(!stack_isEmpty(&myStack) && stack_top(&myStack) == need + 1) {
            need++;
            stack_pop(&myStack);
        }

        if(need == n) {
            printf("yes\n");
        } else printf("no\n");
    }

    return 0;
}