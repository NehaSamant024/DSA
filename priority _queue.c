//priorty queue implementation using array

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int data;
    int pr;
}member;

int isEmpty(member q[],int * rear);

int isFull(member q[],int n,int * rear);

int get_front(member q[],int n, int * front, int * rear);

int get_rear(member q[],int n, int * front, int * rear);

void insert(member q[],int n,int * front,int * rear,int el, int pri);

int delete(member q[],int * front,int * rear);

void display(member q[],int * front,int * rear);

int main()
{
  
    int n,front=-1,rear=-1;
    printf("\nEnter size of queue::");
    scanf("%d",&n);
    member queue[n];
    int choice;
    while(1)
    {
         char * s="OPERATION PERFORMED SUCCESSFULLY";
         printf("\n\n*************************************************************************************\n\n");
         printf("YOU CAN PERFORM FOLLOWING OPERATIONS...........\n");
         printf("\n\n****************************MENU*******************************\n\n");
         printf("1.INSERT ELEMENT\n");
         printf("2.FETCH/DELETE ELEMENT\n");
         printf("3.DISPLAY\n");
         printf("4.GET FRONT\n");
         printf("5.GET REAR\n");
         printf("6.IS EMPTY ?\n");
         printf("7.IS FULL ?\n");
         printf("8.Exit\n");
         printf("\nEnter choice::");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             {
                 int el,pri;
                 printf("\nEnter element to be inserted:");
                 scanf("%d",&el);
                 printf("Enter priorty of element:");
                 scanf("%d",&pri);
                 insert(queue,n,&front,&rear,el,pri);
                 break;
             }
             case 2:
             {
                 int value=delete(queue,&front,&rear);
                 if(value!=-1)
                 {
                     printf("\nFetched element is %d",value);
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
                int value;
                value=get_front(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at front: %d ",value);
                }
                break;
            }
            case 5:
            {
                int value;
                value=get_rear(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at rear: %d ",value);
                }
                break;
            }
            case 6:
            {
                if(isEmpty(queue,&rear))
                {
                    printf("\nQueue is empty");
                }
                else
                {
                    printf("\nQueue is not empty");
                }
                break;
            }
            case 7:
            {
                if(isFull(queue,n,&rear))
                {
                    printf("\nQueue is full");
                }
                else
                {
                    printf("\nQueue is not full");
                }
                break;
            }
             case 8:
             {
                 printf("\n\n*************************************************************************************\n\n");
                 printf("                                   PROGRAM FINISHED                                        ");
                 printf("\n\n*************************************************************************************\n\n");
                 exit(0);
             }
             default: s="        INVALID CHOICE         ";
         }
         printf("\n\n*************************************************************************************\n\n");
         printf("                         %s                            ",s);

    }

    return 0;
}


int isEmpty(member q[],int * rear)
{
    if( * rear==-1){return 1;}
    return 0;
}
int isFull(member q[],int n,int * rear)
{
    if( * rear==n-1){return 1;}
    return 0;
}

int get_front(member q[],int n, int * front, int * rear)
{
    if(isEmpty(q,rear))
    {
        printf("\nQueue is empty, no element at front");
        return -1;
    }
    return q[ * front].data;
}


int get_rear(member q[],int n, int * front, int * rear)
{
    if(isEmpty(q,rear))
    {
        printf("\nQueue is empty, no element at rear");
        return -1;
    }
    return q[ * rear].data;
}
void insert(member q[],int n,int * front,int * rear,int el, int pri)
{
    if(isFull(q,n,rear))
    {
        printf("\n\n############ QUEUE IS FULL #############\n\n");
    }
    else if( * front==-1)
    {
        * front=0;
        ( * rear)++;
        q[ * rear].data=el;
        q[ * rear].pr=pri;
    }
    else
    {
        ( * rear)++;
        q[ * rear].data=el;
        q[ * rear].pr=pri;
    }
}

int delete(member q[],int * front,int * rear)
{
    if(isEmpty(q,rear))
    {
        printf("\n\n############ QUEUE IS EMPTY #############\n\n");
        return -1;
    }
    int temp,max=0;
    int i=0;
    for(i=0;i<= * rear;i++)
    {
        if(q[i].pr>q[max].pr)
        {
            max=i;
        }
    }
    temp=q[max].data;
    for(i=max;i< * rear;i++)
    {
        q[i]=q[i+1];
    }
    ( * rear)--;


    return temp;



}

void display(member q[],int * front,int * rear)
{
    if(isEmpty(q,rear))
    {
        printf("\n\n############ QUEUE IS EMPTY #############\n\n");
    }
    else
    {
        int i=0;
        printf("\nQueue is [value,priorty]:");
        for(i=0;i<= * rear;i++)
        {
            printf("[%d,%d] ",q[i].data,q[i].pr);
        }
        printf("\n\n");
    }
}
