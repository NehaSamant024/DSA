#include <stdio.h>
#include <stdlib.h>

//implementing linear queue using array

void enqueue(int queue[],int *front,int *rear,int n, int value);
int dequeue(int queue[],int *front, int *rear);
void display(int queue[],int *front, int *rear);

int main()
{
    int n;
    printf("Enter max size of queue:");
    scanf("%d",&n);
    int queue[n];
    int front=-1,rear=-1;
    int value,choice;
    while(1)
    {
        printf("\n********************************MENU*******************************\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nEnter value to be inserted:");
                scanf("%d",&value);
                enqueue(queue,&front,&rear,n,value);
                break;
            }
            case 2:
            {
                value=dequeue(queue,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue removed is %d",value);

                }
                break;
            }
            case 3:
            {
                display(queue,&front,&rear);
                break;
            }
            case 4:
            {
               printf("\n*****************************PROGRAM ENDED****************************\n");
               exit(0);
            }
            default:
            {
                printf("\nINVALID CHOICE.....");
            }
             
        }
        printf("\n**********************************************************************\n");
    }
    return 0;
}

void enqueue(int queue[],int *front,int *rear,int n, int value)
{
    if(*rear==n-1)
    {
        printf("\nQueue is Full\n");
        return;
    }
    if(*rear==-1)
    {
        *front=0;
    }
    queue[++(*rear)]=value;
}

int dequeue(int queue[],int *front, int *rear)
{
    if(*rear==-1)
    {
        printf("\nQueue is Empty\n");
        return -1;

    }
    int value=queue[*front];
    int i;
    for(i=*front;i<*rear;i++)
    {
        queue[i]=queue[i+1];
    }
    if(*front==*rear)
    {
        *front=-1;
    }
    (*rear)--;
    return value;
}

void display(int queue[],int *front, int *rear)
{
    if(*rear==-1)
    {
        printf("\nQueue is Empty\n");
        return;

    }
    printf("\nQueue is:");
    int i;
    for(i=*front;i<=*rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");

}
