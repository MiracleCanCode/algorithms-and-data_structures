#include <stdio.h>
#include <stdlib.h>

#define DEQUE_CAPACITY 10
#define ERR_DEQUE_IS_NULL "Error: %s: deque is null\n"
#define ERR_DEQUE_OVERFLOW "Error: %s: deque is overflow\n"
#define ERR_DEQUE_UNDERFLOW "Error: %s: deque is empty\n"

typedef struct {
	int size;
	char data[DEQUE_CAPACITY];
	int head;
	int tail;
} Deque;

Deque* new_deque() {
	Deque* deque = (Deque*)malloc(sizeof(Deque));
	if (!deque) {
		fprintf(stderr, "new_deque: failed to allocate memory for deque\n");
		return NULL;
	}
	deque->size = 0;
	deque->head = 0;
	deque->tail = 0;
	return deque;
}

void push_front(Deque* deque, char value) {
	if (!deque) {
		fprintf(stderr, ERR_DEQUE_IS_NULL, "push_front");
		return;
	}
	if (deque->size == DEQUE_CAPACITY) {
		fprintf(stderr, ERR_DEQUE_OVERFLOW, "push_front");
		return;
	}
	deque->head = (deque->head - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
	deque->data[deque->head] = value;
	deque->size++;
}

void push_back(Deque* deque, char value) {
	if (!deque) {
		fprintf(stderr, ERR_DEQUE_IS_NULL, "push_back");
		return;
	}
	if (deque->size == DEQUE_CAPACITY) {
		fprintf(stderr, ERR_DEQUE_OVERFLOW, "push_back");
		return;
	}
	deque->data[deque->tail] = value;
	deque->tail = (deque->tail + 1) % DEQUE_CAPACITY;
	deque->size++;
}

void pop_front(Deque* deque) {
	if (!deque) {
		fprintf(stderr, ERR_DEQUE_IS_NULL, "pop_front");
		return;
	}
	if (deque->size == 0) {
		fprintf(stderr, ERR_DEQUE_UNDERFLOW, "pop_front");
		return;
	}
	deque->data[deque->head] = 0; 
	deque->head = (deque->head + 1) % DEQUE_CAPACITY;
	deque->size--;
}

void pop_back(Deque* deque) {
	if (!deque) {
		fprintf(stderr, ERR_DEQUE_IS_NULL, "pop_back");
		return;
	}
	if (deque->size == 0) {
		fprintf(stderr, ERR_DEQUE_UNDERFLOW, "pop_back");
		return;
	}
	deque->tail = (deque->tail - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
	deque->data[deque->tail] = 0; 
	deque->size--;
}

