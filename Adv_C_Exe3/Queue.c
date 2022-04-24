#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 
/***************** Queue ADT Implementation *****************/
void print(Queue* q);
void reverse(Queue* q);
int min_max(Queue* s1, Queue* s2);

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("\nEmpty queue! noting to remove\n");
		return 0;
	}
	while (!isEmptyQueue(q))
		dequeue(q);

	printf("\n All data is removed \n");
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* new = (intNode*)calloc(1, sizeof(intNode));
	if (new != NULL) {
		new->data = data;
		if (!isEmptyQueue(q))
		{
			q->tail->next = new;
			q->tail = new;
			return;
		}
		q->tail = q->head = new;
	}
	else
		return;

}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("Empty queue!");
		return 0;
	}
	int res = q->head->data;
	intNode* n = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(n);
	return res;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
		return 1;
	return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void print(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("Empty queue!\n");
		return;
	}

	Queue x;
	initQueue(&x);
	int data;
	while (!isEmptyQueue(q))
	{
		data = dequeue(q);
		printf("%d\t", data);
		enqueue(&x, data);
	}
	while (!isEmptyQueue(&x))
		enqueue(q, dequeue(&x));
}

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("\nEmpty queue!\n");
		return;
	}
	intNode* n1 = q->head;
	intNode* n2 = q->tail;
	int x = n2->data;
	int temp;
	while (n1->data != x) {
		temp = dequeue(q);
		enqueue(q, temp);
		n1 = q->head;
	}
	printf("the new Queue after Rotate\n");
	print(q);
}

void reverse(Queue* q) {
	Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	while (!isEmptyQueue(q)) {
		while (!isEmptyQueue(&s1)) {
			enqueue(&s2, dequeue(&s1));
		}
		enqueue(&s1, dequeue(q));
		while (!isEmptyQueue(&s2)) {
			enqueue(&s1, dequeue(&s2));
		}
	}
	while (!isEmptyQueue(&s1)) {
		enqueue(q, dequeue(&s1));
	}
}

void cutAndReplace(Queue* q)
{
	Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	int c = 0;
	int x = 0;
	if (isEmptyQueue(q)) {
		printf("Empty queue!");
		return;
	}
	while (!isEmptyQueue(q)) {
		c++;
		x += q->head->data;
		enqueue(&s2, dequeue(q));
	}
	if (c % 2 != 0) {
		x = x / c;
		enqueue(&s2, x);
		c++;
		for (int i = 0; i < c / 2; i++)
			enqueue(&s1, dequeue(&s2));
		reverse(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	else {
		for (int i = 0; i < c / 2; i++)
			enqueue(&s1, dequeue(&s2));
		reverse(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	print(&s2);
}

void sortKidsFirst(Queue* q)
{
	Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	int data, temp, counter = 0;
	if (isEmptyQueue(q)) {
		printf("Empty queue!");
		return;
	}
	for (int i = 0; !(isEmptyQueue(q) && isEmptyQueue(&s1)); i++) {
		if (isEmptyQueue(q))
			enqueue(&s2, min_max(&s1, q));
		else
			enqueue(&s2, min_max(q, &s1));
	}
	while (!isEmptyQueue(&s2))
		enqueue(q, dequeue(&s2));
	print(q);
}

int min_max(Queue* s1, Queue* s2)
{
	unsigned int data = dequeue(s1);
	while (!isEmptyQueue(s1)) {
		if (s1->head->data <= data) {
			enqueue(s2, data);
			data = dequeue(s1);
		}
		else
			enqueue(s2, dequeue(s1));
	}
	return data;
}