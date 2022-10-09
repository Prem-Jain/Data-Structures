#include<stdio.h>
#include<stdlib.h>
#define size 100
int n;
struct node
{
    int data;
    struct node *next;
};

struct node *head[size]={NULL},*c;

void insert()
{
    int i,key;
    struct node *newnode;
    printf("Enter value to insert into hash table : ");
    scanf("%d",&key);
    i = key%n;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if(head[i]==NULL)
        head[i]=newnode;
    else
    {
        c=head[i];
        while(c->next!=NULL)
            c=c->next;
        c->next = newnode;
    }
}

void search()
{
    int key, index;
    printf("Enter element to be searched : ");
    scanf("%d",&key);
    index = key%n;
    if(head[index]==NULL)
        printf("Element not found\n");
    else
    {
        for(c=head[index];c!=NULL;c=c->next)
        {
            if(c->data==key)
            {
                printf("Search element found\n");
                return;
            }
        }
        printf("Search element not found\n");
    }
}

void display()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Entries at index %d : ",i);
        if(head[i]==NULL)
            printf("No hash entry\n");
        else
        {
            for(c=head[i];c!=NULL;c=c->next)
                printf("%d -> ",c->data);
            printf("\n");
        }
    }
}

void main()
{
    int op,i;
    printf("Enter the table size : ");
    scanf("%d",&n);
    while(1)
    {
        printf("1.Insert\t2.Display\t3.Search\t4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: insert(); display(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: exit(0);
        }
    }
}
