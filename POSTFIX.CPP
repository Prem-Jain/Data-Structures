#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define MaxSize 20

int stack[MaxSize], top = -1;

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

void push(int x)
{
	if(top == MaxSize - 1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[++top] = x;
	}
}

int pop()
{
	if(isEmpty())
		return -1;
	return stack[top--];
}

void evaluatePostfix(char *e)
{
	float result, n1, n2, num;
	while(*e != NULL)
	{
		if(isalpha(*e))
		{
			printf("Enter the value for %c : ", *e);
			scanf(" %c", e);
			num = *e - 48;
			push(num);
		}
		else if(isdigit(*e))
		{
			num = *e - 48;
			push(num);
		}
		else
		{
			n1 = pop();
			if(isEmpty())
			{
				printf("Invalid Postfix expression\n");
				return;
			}
			n2 = pop();
			switch(*e)
			{
				case '+' : result = n2 + n1; break;
				case '-' : result = n2 - n1; break;
				case '*' : result = n2 * n1; break;
				case '/' : result = (float)n2 / n1; break;
				deafult : printf("Invalid postfix expression\n"); return;
				}
			push(result);
		}
		e++;
	}
	if(top > 0)
	{
		printf("Invalid postfix Expression\n");
		return;
	}
	printf("Result = %d\n", stack[top]);
}
void main()
{
	char exp[20], *e;
	printf("Enter the postfix expression : ");
	scanf("%s", exp);
	e = exp;
	evaluatePostfix(e);
	getch();
	clrscr();
}