#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct 
{
	int value;
	struct Node* next;	
} Node;

typedef struct 
{
	struct Node* head;
	int len;
} SinglyLinkedList;

Node* createNode(int value) 
{
	errno = 0;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL)
	{
		
		perror("createNode");
		return NULL;
	}
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

SinglyLinkedList* createSinglyLinkedList()
{
	errno = 0;
	SinglyLinkedList* linkedList = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	if(linkedList == NULL)
	{
		perror("createSinglyLinkedList");
		return NULL;
	}
	linkedList->head = NULL;
	linkedList->len = 0;
	return linkedList;
}

void insertInHead(SinglyLinkedList* list, int value)
{
	Node* newNode = createNode(value);
	if(newNode == NULL)
	{
		return;
	}

	if(list->head == NULL)
	{
		list->head = newNode;
	} else {
		Node* prevHead = list->head;
		newNode->next = prevHead;
		list->head = newNode;
	}
	list->len++;
}

void insertInTail(SinglyLinkedList* list, int value) 
{
	Node* newNode = createNode(value);
	if(newNode == NULL)
	{
		return;
	}
	
	if(list->head == NULL)
	{
		list->head = newNode;
	} else {
		Node* node = list->head;
		while(node->next != NULL)
		{
			node = node->next;
		}

		node->next = newNode;
	}
	list->len++;
}

void insert(SinglyLinkedList* list, int n, int value)
{
	if(n < 0 || n > list->len)
	{
		return;
	}
	if(n == 0)
	{
		insertInHead(list, value);
		return;
	}

	if(n == list->len)
	{
		insertInTail(list, value);
	}

	Node* newNode = createNode(value);
	Node* node = list->head;

	for(int i = 0; i < n - 1; i++)
	{
		node = node->next;
	}

	newNode->next = node->next;
	node->next = newNode;
	list->len++;
}

void deleteHead(SinglyLinkedList* list)
{
	Node* prevHead = list->head;
	Node* newHead = prevHead->next;
	
	free(prevHead);
	list->head = newHead;
	list->len--;
}

void deleteTail(SinglyLinkedList* list)
{
	if(list->head == NULL)
	{
		return;
	}

	Node* prevNode = list->head;
	Node* tailNode;
	while(prevNode->next != NULL)
	{
		tailNode = prevNode;
		prevNode = prevNode->next;
	}
	
	free(prevNode);
	tailNode->next = NULL;
	list->len--;
}

void delete(SinglyLinkedList* list, int pos)
{
	if(pos < 0 || pos > list->len)
	{
		return;
	}

	if(pos == 0)
	{
		deleteHead(list);
		return;
	}

	Node* prevNode = list->head;
	for(int i = 0; i < pos - 1; i++)
	{
		prevNode = prevNode->next;
	}

	Node* posNode = prevNode->next;
	free(posNode);
	prevNode->next = posNode->next;
	list->len--;
}
