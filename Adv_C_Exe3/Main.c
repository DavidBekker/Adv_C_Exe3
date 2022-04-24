#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include<string.h>

void prinurrenttack(Stack* s);

void main()
{
	int choos1;// Stack or queue
	printf("Choos: 1 For Stack\n Choos: 2 For Queue\n  ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &choos1);
	while (1)
	{
		switch (choos1)
		{
		case 1:
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

					char* str = (char*)malloc(sizeof(char) * (leanght + 1));
					if (str == NULL)break;
					//char str[leanght + 1];
					while (!isEmptyStack(&tmp2))
					{
						c = pop(&tmp2);
						*(str + i) = c;//PROBLEM
						i++;
						tmp2.head = tmp2.head->next;
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
					printf(" The latter after pop is: %c  \n", pop(&ps));
					break;
				}
				case 8:
				{
					return ;
				}
				default:
					break;
				}

			}
			break;
		}
		case 2:
		{
			Queue x;
			initQueue(&x);
			int data;
			int choosx;
			while (1)
			{
				printf("\nTo print the queue choos: 1\nTo insert new value to queue enter :2 \nTo Rotate queue choos : 3");
				printf("\nTo Sort the queue choos : 4 \nTo cut and replace Queue choos :5 \nTo Delete Last data from queue choos: 6\n");
				printf("To Delete the queue choos : 7\nTo Rotate Queue choos: 8\n");
				fseek(stdin, 0, SEEK_END);
				scanf("%d", &choosx);
				switch (choosx)
				{
				case 1: //print
				{
					printf("\nThe queue you choose\n");
					print(&x);
					printf("\n");
					break;
	
				}
				case 2://Add Value to queue
				{
					printf("\nEnter Data in Queue\n");
					scanf_s("%d", &data);
					enqueue(&x, data);
					break;
				}
				case 3:
				{
					printf("\nRotating:\n");
					rotateQueue(&x);
					break;
				}
				case 4:
				{
					printf("\nSorting:\n");
					sortKidsFirst(&x);
					break;
				}
				case 5:
				{
					printf("Cut and replace:\n");
					cutAndReplace(&x);
					break;
				}
				case 6:
				{
					int datar = dequeue(&x);
					printf("\nThe data you remove is: %d\n", datar);
					break;
				}
				case 7:
				{
					destroyQueue(&x);
					break;
				}
				case 8:
				{
					printf("\n");

					rotateQueue(&x);
					printf("\n");
					break;
				}
				default:
					break;
				}

			}
			
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


