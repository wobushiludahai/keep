#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct queue
{
    NODE *front;
    NODE *rear;
} QUEUE;

QUEUE *creat_queue(void)
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    if (q == NULL) {
        printf("malloc error");
    }

    q->front = NULL;
    q->rear = NULL;

    return q;
}

int enqueue(QUEUE *q, int data)
{
    NODE *newq = (NODE *)malloc(sizeof(NODE));
    if (newq == NULL) {
        printf("malloc error");
        return -1;
    }

    newq->data = data;
    newq->next = NULL;

    if (q->rear == NULL) {
        q->front = newq;
        q->rear = newq;
    } else {
        q->rear->next = newq;
        q->rear = newq;
    }

    return 0;
}

int dequeue(QUEUE *q)
{
    if (q == NULL) {
        printf("input error");
        return -1;
    }
    
    if (q->front == NULL) {
        printf("queue is empty");
        return -1;
    }

    NODE *tmp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tmp);
    return 0;
}

int get_queue_len(QUEUE *q)
{
    int len = 0;
    NODE *tmp;

    if (q == NULL) {
        printf("input error");
        return -1;
    }
    
    if (q->front == NULL) {
        printf("queue is empty");
        return 0;
    }

    tmp = q->front;
    while (q->front) {
        len++;
        tmp = tmp->next;
    }
    
    return len;
}


