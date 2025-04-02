#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define QUEUE_SIZE 100

typedef struct {
    char* data;
    int size;
} queue;

char* queue_data[QUEUE_SIZE];

queue* new_queue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    if(q == NULL)
    {
        perror("new_queue failed allocate memory for queue");
        return NULL;
    }

    q->data = queue_data;
    q->size = 0;

    return q;
}

void enqueue(queue* q, char elem)
{
    if(q == NULL)
    {
        fprintf(stderr, "error: queue is NULL");
        return;
    }

    if(q->size == 0)
    {
        q->data[0] = elem;
        q->size++;
        return;
    }

    q->data[q->size] = elem;
    q->size++;
}

void dequeue(queue* q)
{
    if(q == NULL)
    {
        fprintf(stderr, "error: queue is NULL");
        return;
    }

    if(q->size == 0)
    {
        fprintf(stderr, "error: queue is empty");
        return;
    }

    q->data[q->size-1] = '\0';
    q->size--;
}

bool empty(queue* q)
{
    if(q == NULL)
    {
        fprintf(stderr, "error: queue is NULL");
        return false;
    }

    return q->size == 0;
}

int size(queue* q)
{
    if(q == NULL)
    {
        fprintf(stderr, "error: queue is NULL");
        return 0;
    }
    
    return q->size;
}