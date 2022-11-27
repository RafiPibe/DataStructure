#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct queueNode_t {
    char data[20];
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue) {
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char *name) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->data, name);
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

char *queue_front(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main() {
    Queue myQueue;
    queue_init(&myQueue);
    
    char str[20], str1[20];
    int t, cookies = 0, notcookies = 0, n;
    
    scanf("%d", &t);
    
    while(t--) {
        scanf("%s", str);
        if(!strcmp(str, "Cookies")) {
            queue_push(&myQueue, str);
            cookies++;
        } else if(!strcmp(str, "Not")){
            scanf("%s", str1);
            queue_push(&myQueue, str);
            notcookies++;
        }
    }

    scanf("%d", &n);
    
    while(n--) {
        scanf("%s", str);

        if(!strcmp(str, "Out")) {
            if(!strcmp(queue_front(&myQueue), "Cookies"))
                printf("I'm Sorry Kid\n");
            queue_pop(&myQueue);
        } else if(!strcmp(str, "Count")){
            scanf("%s", str1);
            if(cookies >= 5) {
                printf("This is the way\n");
            } else printf("I can bring you in warm, or I can bring you in cold\n");
        }
    }
}