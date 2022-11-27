#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

void stack_init(Stack *stack) 
{
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

void stack_pop(Stack *stack)  {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void nger(Stack *stack, int X){
    StackNode *current = stack->_top;
    while(current != NULL){
        current ->data += X;
        current = current->next;
    }
}

void ngre(Stack *stack, int X){
    StackNode *current = stack->_top;
    while(current != NULL){
        current ->data -= X;
        current = current->next;
    }
}

int main(int argc, char const *argv[]) {
    int n, m, a;
    Stack myStack;
    stack_init(&myStack);

    char command[1001];
    scanf("%d", &n);
    
    while(n--) {
        scanf("%s", &command);
        
        if(!strcmp(command, "hinzufugen")) {
            //add value to stack
            scanf("%d %d", &a, &m);
            for(int i = 0; i < m; i++) {
                stack_push(&myStack, a);
            }
            printf("%d\n", stack_size(&myStack));
        }
        else if(!strcmp(command, "subtrahieren")) {
            //remove value in stack
            scanf("%d", &m);
            printf("%d\n", stack_top(&myStack));
            for(int i = 0; i < m; i++) {
                stack_pop(&myStack);
            }
        }
        else if(!strcmp(command, "ger")) {
            //add
            scanf("&d", &m);
            nger(&myStack, m);
        }
        else if(!strcmp(command, "gre")) {
            //subtract
            scanf("&d", &m);
            ngre(&myStack, m);
        }
    }
}
