#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX], front=NULL, rear=NULL;

void enqueue(data){
    if(front==NULL && rear==NULL)
    {
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%MAX==front)
    {
        //overflow
    }
    else
    {
        rear=(rear+1)%MAX; //rear incremented
        queue[rear]=data;
    }
}
void dequeue()
{
    if(front==NUll && rear==NULL)
    {
        printf("underfloiw");
    }
    else if(front==rear)
    {
        //print queue[front]
        front=NULL;rear=NULL;
    }
    else
    {
        //print queue[front]
        front=(front+1)%MAX
    }
}

void display()
{
    i=front;
    while(i<rear)
    {
        printf(queue[i]);
        i=(i+1)%MAX;
    }
}

void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("Quueue empty\n");
    }
    else{
        printf("First element is :%d",front->data);
    }
}
void main()
{
    int option,i,n,data;
    do{
        printf("\n\nMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\nEnter a choice: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("\nHow many data elements? ");
                    scanf("%d",&n);
                    printf("Enter data:\n");
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&data);
                        enqueue(data);
                    }
                    break;
            case 2:dequeue();
                    break;
            case 3:display();break;
            case 4:peek();break;
            default:printf("Enter valid option\n");break;

        }
    }while(option!=5);
}