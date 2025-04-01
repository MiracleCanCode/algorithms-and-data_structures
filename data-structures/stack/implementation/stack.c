#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_STACK_SIZE 100

typedef struct {
    char* data;
    int size;    
} stack;

stack* new_stack(void)
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s == NULL)
    {
        perror("Failed to allocate memory for stack struct on the heap");
        return NULL;
    }

    char* data = (char*)malloc(sizeof(char) * DATA_STACK_SIZE);
    if (data == NULL)
    {
        perror("Failed to allocate memory on the heap");
        free(s);
        return NULL;
    }

    s->data = data;
    s->size = 0;
    return s;
}

void push(stack* s, char element)
{
    if (s == NULL)
    {
        return;
    }

    if (s->size >= DATA_STACK_SIZE)
    {
        return; 
    }

    s->data[s->size] = element;
    ++s->size;
}

void pop(stack* s)
{
    if (s == NULL || s->size == 0)
    {
        return;      
    }

    --s->size;
}

char peek(stack* s)
{
    if (s == NULL || s->size == 0)
    {
        return '\0'; 
    }

    return s->data[s->size - 1];
}

bool isEmpty(stack* s)
{
    return s->size == 0;
}

void free_stack(stack* s)
{
    if(s != NULL)
    {
        free(s);
        free(s->data);
    }
}