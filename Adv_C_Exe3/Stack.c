#include "Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* current = s->head;
	charNode* next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->head = NULL;
	printf("Stack is Empty\n");
}


void push(Stack* s, char data)
{
	charNode* newn = (charNode*)malloc(sizeof(charNode));
	if (newn == NULL)
		return;//Check if newn is empty

	newn->data = data;
	newn->next = s->head;
	s->head = newn;
}

char pop(Stack* s)
{
	if (!isEmptyStack) return;
	charNode* current = s->head;
	char tm = s->head->data;
	s->head = s->head->next;
	free(current);
	return tm;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	else
		return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	char res;
	Stack Original, Tmp1, Tmp2;
	initStack(&Original); initStack(&Tmp1); initStack(&Tmp2);
	int lean = (strlen(sentence) - 1);
	while (lean > -1)
	{
		push(&Original, sentence[lean]);
		lean--;
	}

	while (!(isEmptyStack(&Original)))
	{
		while (res = !'#')
		{
			res = pop(&Original);
			push(&Tmp1, res);
		}
		push(&Tmp1, res);
		while (res != '#')
		{
			if (isEmptyStack(&Original))
				break;
			res = pop(&Original);
			push(&Tmp2, res);
		}
		push(&Tmp2, res);

		while (!(isEmptyStack(&Tmp2)))
			push(&Tmp1, pop(&Tmp2));
	}

	while (!(isEmptyStack(&Tmp1)))
		push(&Original, pop(&Tmp1));

	printf("The new string is : ");
	while (!(isEmptyStack(&Original)))
		printf("%c", pop(&Original));

}

int isPalindrome(Stack* s)
{
	Stack Top1, Top2;
	initStack(&Top1); initStack(&Top2);
	Top1.head = s->head;
	Top2.head = s->head;
	if (isEmptyStack(&Top1))
		return 0;
	int count = Stackleanght(&Top1);

	Top1.head = s->head;

	for (count; count > 0; count--)
	{
		for (int i = count - 1; i > 0; i--)
			Top2.head = Top2.head->next;
		if ((Top1.head->data) != (Top2.head->data))
			return 0;
		Top1.head = Top1.head->next;
		Top2.head = s->head;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (isEmptyStack(&s)) return;
	Stack stk1, stk2, original;
	original.head = s->head;
	initStack(&stk1); initStack(&stk2);
	int leanght = Stackleanght(&original);
	if (n<0 || n>leanght)
		return;

	for (int i = 0; i < leanght - n; i++)
		push(&stk1, pop(&original));

	while (!isEmptyStack(&original))
		push(&stk2, pop(&original));

	while (!isEmptyStack(&stk1))
		push(&original, pop(&stk1));

	while (!isEmptyStack(&stk2))
		push(&original, pop(&stk2));
	s->head = original.head;
}


int Stackleanght(Stack* s)
{
	if (isEmptyStack(&s)) return;
	Stack Top;
	int count = 1;
	initStack(&Top);
	Top.head = s->head;
	while (Top.head->next != NULL)
	{
		count++;
		Top.head = Top.head->next;
	}
	Top.head = s->head;
	return count;
}