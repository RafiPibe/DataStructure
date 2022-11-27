
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
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

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    int N, X, Na, V, sum = 0;
    int count = 0;
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++){
        scanf("%d",  &Na);
        for(int j = 0; j < Na; j++){
            scanf("%d", &V);
            stack_push(&myStack, V);
        }
        if(sum + stack_top(&myStack) < X){
            sum = sum + stack_top(&myStack);
            count++;
        }
        stack_pop(&myStack);
        if(sum + stack_top(&myStack) >= X){
            break;
        }
    }
    while(!stack_isEmpty(&myStack)){
        if(sum + stack_top(&myStack) < X){
            sum = sum + stack_top(&myStack);
            count++;
        }
        stack_pop(&myStack);
        if(sum + stack_top(&myStack) >= X){
            break;
    }
   
    }
    printf("%d", count);
    return 0;
}