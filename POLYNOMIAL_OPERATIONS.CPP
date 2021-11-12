#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct polynomial
{
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;
poly addTerm(poly head, poly temp)
{
	poly p1, p2;
	p1 = p2 = head;
	if(p1 == NULL)
	{
		head = temp;
		return head;
	}
	while(p1 != NULL && p1 -> exp > temp -> exp)
	{
		p2 = p1;
		p1 = p1 -> next;
	}
	if(p1 == NULL)
		p2 -> next = temp;
	else if(p1 -> exp == temp -> exp)
		p1 -> coeff = p1 -> coeff + temp -> coeff;
	else if(p1 -> exp < temp -> exp)
	{
		if(p1 == p2)
		{
			temp -> next = p1;
			head = temp;
		}
		else
		{
			temp -> next = p1;
			p2 -> next = temp;
		}
	}
	return head;
}
poly create(poly head)
{
	poly temp;
	char ch;
	do
	{
		temp = (poly)malloc(sizeof(struct polynomial));
		printf("Enter the coeff and exp of the node : ");
		scanf("%d%d", &temp->coeff, &temp -> exp);
		temp -> next = NULL;
		head = addTerm(head, temp);
		printf("Do you want another term(y/n) : ");
		scanf(" %c", &ch);
	}while(ch != 'n');
	return head;
}
poly add(poly head1, poly head2)
{
	poly p1 = head1, p2 = head2, sum = NULL;
	while(p1 != NULL && p2 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		if(p1 -> exp == p2 -> exp)
		{
			temp -> coeff = p1 -> coeff + p2 -> coeff;
			temp -> exp = p1 -> exp;
			temp -> next = NULL;
			sum = addTerm(sum, temp);
			p1 = p1 ->next;
			p2 = p2 ->next;
		}
		else if(p1 -> exp > p2 -> exp)
		{
			temp -> coeff = p1 -> coeff;
			temp -> exp = p1 -> exp;
			temp -> next = NULL;
			sum = addTerm(sum, temp);
			p1 = p1 -> next;
		}
		else if(p1 -> exp < p2 -> exp)
		{
			temp -> coeff = p2 -> coeff;
			temp -> exp = p2 -> exp;
			temp -> next = NULL;
			sum = addTerm(sum, temp);
			p2 = p2 -> next;
		}
	}
	while(p1 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		temp -> coeff = p1 -> coeff;
		temp -> exp = p1 -> exp;
		temp -> next = NULL;
		sum = addTerm(sum, temp);
		p1 = p1 -> next;
	}
	while(p2 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		temp -> coeff = p2 -> coeff;
		temp -> exp = p2 -> exp;
		temp -> next = NULL;
		sum = addTerm(sum, temp);
		p2 = p2 -> next;
	}
	return sum;
}
poly sub(poly head1, poly head2)
{
	poly p1 = head1, p2 = head2, sub = NULL;
	while(p1 != NULL && p2 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		if(p1 -> exp == p2 -> exp)
		{
			temp -> coeff = p1 -> coeff - p2 -> coeff;
			temp -> exp = p1 -> exp;
			temp -> next = NULL;
			sub = addTerm(sub, temp);
			p1 = p1 ->next;
			p2 = p2 ->next;
		}
		else if(p1 -> exp > p2 -> exp)
		{
			temp -> coeff = p1 -> coeff;
			temp -> exp = p1 -> exp;
			temp -> next = NULL;
			sub = addTerm(sub, temp);
			p1 = p1 -> next;
		}
		else if(p1 -> exp < p2 -> exp)
		{
			temp -> coeff = -1 * p2 -> coeff;
			temp -> exp = p2 -> exp;
			temp -> next = NULL;
			sub = addTerm(sub, temp);
			p2 = p2 -> next;
		}
	}
	while(p1 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		temp -> coeff = p1 -> coeff;
		temp -> exp = p1 -> exp;
		temp -> next = NULL;
		sub = addTerm(sub, temp);
		p1 = p1 -> next;
	}
	while(p2 != NULL)
	{
		poly temp = (poly)malloc(sizeof(struct polynomial));
		temp -> coeff = -1 * p2 -> coeff;
		temp -> exp = p2 -> exp;
		temp -> next = NULL;
		sub = addTerm(sub, temp);
		p2 = p2 -> next;
	}
	return sub;
}
poly pro(poly head1, poly head2)
{
	poly p1, p2, temp, pro = NULL;
	for(p1 = head1; p1 != NULL; p1 = p1 -> next)
	{
		for(p2 = head2; p2 != NULL; p2 = p2 -> next)
		{
			temp = (poly)malloc(sizeof(struct polynomial));
			temp -> coeff = p1 -> coeff * p2 -> coeff;
			temp -> exp = p1 -> exp + p2 -> exp;
			temp -> next = NULL;
			pro = addTerm(pro, temp);
		}
	}
	return pro;
}

void print(poly head)
{
	poly temp = head;
	while(temp != NULL)
	{
		printf("%d X^%d --> ", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}
void main()
{       clrscr();
	int ch;
	poly head1 = NULL, head2 = NULL, add_result, sub_result, mul_result;
	printf("Enter the first polynomial : \n");
	head1 = create(head1);
	printf("Enter the second polynomial : \n");
	head2 = create(head2);
	printf("The first polynomial is ");
	print(head1);                      \
	printf("The second polynomial is ");
	print(head2);
	while(1)
	{
		printf("1.Addition 2.Subtraction 3.Multiplication 4.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add_result = add(head1, head2);
				printf("The addition result = ");
				print(add_result);
				break;
			case 2:	sub_result = sub(head1, head2);
				printf("The subtraction result = ");
				print(sub_result);
				break;
			case 3:mul_result = pro(head1, head2);
				printf("The multiplication result = ");
				print(mul_result);
				break;
			case 4: exit(0);
		}
	}
}