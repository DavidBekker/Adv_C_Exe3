#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include<string.h>

void prinurrenttack(Stack* s);
void main()
{
	char c;
	int choos;
	Stack ps;
	initStack(&ps);
	while (1)
	{
		printf("\nTo Enter a word to stack choose: 1 \n To check if Palindrome choose: 2 \n \
To fix word with # enter: 3 \n To delete data choose: 4\n To print stack choose: 5 \n To Rotate Stack choose 6: \nTo Delete wordl from Stack choose: 7\n To exit choose: 8\n");

		fseek(stdin, 0, SEEK_END);
		scanf("%d", &choos);
		switch (choos)
		{
		case 1:
		{
			printf("Enter a latter to new stack\n");
			fseek(stdin, 0, SEEK_END);
			scanf("%c", &c);
			push(&ps, c);
			break;
		}
		case 2:
		{
			if (isPalindrome(&ps) == 1)
			{
				printf("Palindrome");
				break;
			}

			printf("Not Palindrome\n");
			break;
		}
		case 3:
		{
			Stack tmp1 = ps;
			Stack tmp2 = ps;
			char c;
			if (isEmptyStack(&tmp1)) break;
			int i = 0, leanght = Stackleanght(&tmp1);

			char* str = (char*)malloc(sizeof(char) * leanght + 1);
			if (str == NULL)break;
			while (!isEmptyStack(&tmp2))
			{
				c = pop(&tmp2);
				str[i] = c;//PROBLEM
				i++;
			}
			str[i] = '\0';
			flipBetweenHashes(&str);
			free(str);
			break;
		}
		case 4:
		{
			destroyStack(&ps);
			break;
		}
		case 5:
		{
			prinurrenttack(&ps);
			break;
		}
		case 6:
		{
			printf("Enter where to rotate the Stack\n");
			int rotate;
			scanf_s("%d", &rotate);
			rotateStack(&ps, rotate);
			printf("The new Stack after rotate :\n");
			prinurrenttack(&ps);
			break;
		}
		case 7:
		{
			printf(" The latter of Latter after pop is: %c  \n", pop(&ps));
			break;
		}
		case 8:
		{
			exit(1);
		}
		default:
			break;
		}

	}

}

void prinurrenttack(Stack* s)
{
	int tmp = isEmptyStack(&s);
	if (tmp == 1)
	{
		printf("\n Stack is empty");
		return;
	}
	charNode* tm = s->head;
	while (tm != NULL)
	{
		printf("%c  ", tm->data);
		tm = tm->next;
	}
	printf("\n");
}
