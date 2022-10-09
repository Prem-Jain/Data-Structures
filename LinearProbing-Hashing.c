#include<stdio.h>
#include<stdlib.h>
#define size 100
int hashtable[size], n;
int hash(int x)
{
    return x%n;
}

void insert(int x)
{
    int index,start;
    index = hash(x);
    start = index;
    while(hashtable[index]!=-1)
    {
        if(hashtable[index]==-1)
            break;
        index = (index+1)%n;
        if(index==start)
        {
            printf("Hash Table is full.\n");
            return;
        }
    }
    hashtable[index] = x;
}

void search(int x)
{
    int index, start;
    index = hash(x);
    start = index;
    while(hashtable[index]!=x)
    {
        if(hashtable[index]==x)
            break;
        index = (index+1)%n;
        if(index==start)
        {
            printf("Element not found.\n");
            return;
        }
    }
    printf("Element found\n");
}

void display()
{
    for(int i=0;i<n;i++)
    {
        printf("At index %d : %d\n",i,hashtable[i]);
    }
}

void main()
{

    int x,op,i=0;
    printf("Enter table size : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        hashtable[i]=-1;
    while(1)
    {
        printf("1.Insert\t2.Display\t3.Search\t4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter an element to be inserted : ");
                    scanf("%d",&x);
                    insert(x);display(); break;
            case 2: display(); break;
            case 3: printf("Enter an element to search : ");
                    scanf("%d",&x); search(x); break;
            case 4: exit(0);
        }
    }
}
