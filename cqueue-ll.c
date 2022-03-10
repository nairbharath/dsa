#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("HEap full. cannot create node\n");
    }
    else
    {
        newnode->data=data;
        newnode->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=rear=newnode;
            rear->next=front;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            newnode->next=rear;
        }
    }
}
void dequeue()
{
    int val;
    struct node *temp=front;
    if((front==NULL) && (rear==NULL))
    {
        printf("EMpty queue\n");
    }
    else if(front==rear)
    {
        front=rear=NULL;
        free(temp);
    }
    else
    {
        val=temp->data;
        printf("Number to be deleted: %d/n",val);
        front=front->next;
        rear->next=front;
        free(temp);
        display();
    }
}

void display()
{
    struct node *temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue Empty. Nothing to proint\n");
    }
    else
    {
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
            
        }while(temp->next!=front);
        printf("%d", temp->data);
        
        
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