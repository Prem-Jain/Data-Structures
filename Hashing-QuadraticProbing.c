#include<stdio.h>
#include<stdlib.h>
#define size 100
int h[size], n;

void insert()
{
    int key, index, i, hkey;
    printf("Enter a value to enter into hash table : ");
    scanf("%d", &key);
    hkey = key % n;
    for(i = 0; i < n; i++)
    {
        index = (hkey + i*i) % n;
        if(h[index] == -1)
        {
            h[index] = key; return;
        }
    }
    printf("Element cannot be inserted\n");
}

void search()
{
    int key, index, i, hkey;
    printf("Enter search element : ");
    scanf("%d", &key);
    hkey = key % n;
    for(i = 0; i < n; i++)
    {
        index = (hkey + i*i) % n;
        if(h[index] == key)
        {
            printf("Value found at %d index\n",index);
            return;
        }
    }
    printf("Value not found\n");
}

void display()
{
    int i = 0;
    printf("Elements in the hash table are : \n");
    for(i = 0; i < n; i++)
        printf("At index %d : Value is %d\n", i, h[i]);
}

void main()
{

    int op, i;
    printf("Enter the size of the table : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        h[i] = -1;
    while(1)
    {
        printf("1.Insert\t2.Display\t3.Search\t4.Exit\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1: insert(); display(); break;
            case 2 : display(); break;
            case 3 : search(); break;
            case 4 : exit(0);
        }
    }
}
