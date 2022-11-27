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


void getMax(Stack *stack) {
	int yaks[101], i, j, max;
	while (!stack_isEmpty(stack))
	{
        yaks[i] = stack_top(stack);
        stack_pop(stack);
        i++;
    }
    for (j=0; j<=i; j++)
    {
    	if (yaks[j] > max)
    	{
    		max = yaks[j];
		}
	}
	printf("%d", max);
}

int main() {

    int i, N, angkanya;
    char yak[101];
    scanf("%d", &N);

    /*initialize*/
    Stack myStack;
    stack_init(&myStack);
    
    
    
    for (i=0; i<N; i++)
    {
    	scanf ("%s", yak);
    	
    	if (strcmp(yak, "push") == 0)
    	{
    		scanf("%d", &angkanya);
    		stack_push(&myStack, angkanya);
		}
		if (strcmp(yak, "pop") == 0)
		{
			stack_pop(&myStack);
		}
		if (strcmp(yak, "top") == 0)
		{
			printf("stack_top(&myStack)");
		}
//		if (strcmp(yak, "min") == 0)
//		{
//			printf()
//		}
		if (strcmp(yak, "max") == 0)
		{
			getMax(&myStack);
		}
	}

    puts("");
    return 0;
}