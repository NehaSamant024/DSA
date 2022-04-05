//circular queue using array
#include<stdio.h>
#include<stdlib.h>

int isEmpty(int q[],int n, int*front, int*rear);

int isFull(int q[],int n, int*front, int*rear);

void enqueue(int q[],int n, int*front, int*rear, int value);

int dequeue(int q[],int n, int*front, int*rear);

int get_front(int q[],int n, int*front, int*rear);

int get_rear(int q[],int n, int*front, int*rear);

void display(int q[],int n, int*front, int*rear);

int main()
{
    int n;
    printf("Enter max size of queue:");
    scanf("%d",&n);
    int queue[n];
    int front=-1,rear=-1;
    while(1)
    {
        char *s="OPERATION PERFORMED SUCCESSFULLY";
        printf("\n\n*************************************************************************************\n\n");
        printf("YOU CAN PERFORM FOLLOWING OPERATIONS...........\n");
        printf("\n___________MENU___________\n");
        printf("\n1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.GET FRONT\n");
        printf("4.GET REAR\n");
        printf("5.IS EMPTY ?\n");
        printf("6.IS FULL ?\n");
        printf("7.DISPLAY\n");
        printf("8.EXIT\n");
        printf("\nEnter your choice::");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            
            case 1:
            {
                int value;
                printf("\nEnter value to be inserted:");
                scanf("%d",&value);
                enqueue(queue,n,&front,&rear,value);
                break;
            }
            case 2:
            {
                int value;
                value=dequeue(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue %d removed",value);
                }
                break;
            }
            case 3:
            {
                int value;
                value=get_front(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at front: %d",value);
                }
                break;
            }
            case 4:
            {
                int value;
                value=get_rear(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at rear: %d",value);
                }
                break;
            }
            case 5:
            {
                if(isEmpty(queue,n,&front,&rear))
                {
                    printf("\nQueue is empty");
                }
                else
                {
                    printf("\nQueue is not empty");
                }
                break;
            }
            case 6:
            {
                if(isFull(queue,n,&front,&rear))
                {
                    printf("\nQueue is full");
                }
                else
                {
                    printf("\nQueue is not full");
                }
                break;
            }
            case 7:
            {
                display(queue,n,&front,&rear);
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


int isEmpty(int q[],int n, int*front, int*rear)
{
    if(*front==-1){return 1;}
    return 0;
}


int isFull(int q[],int n, int*front, int*rear)
{
    if((*front==(*rear+1)%n)){return 1;}
    return 0;
}




void enqueue(int q[],int n, int*front, int*rear, int value)
{
    if(isFull(q,n,front,rear))
    {
        printf("\nQueue is Full");
        return;
    }
    if(*rear==-1)
    {
        *front=0;
        *rear=0;
    }
    else 
    {
        *rear=(*rear+1)%n;
    }
    q[*rear]=value;
}


int dequeue(int q[],int n, int*front, int*rear)
{
    if(isEmpty(q,n,front,rear))
    {
        printf("\nQueue is Empty");
        return -1;
    }
    int value=q[*front];
    if(*front==*rear)
    {
        *front=-1;
        *rear=-1;
    }
    else 
    {
        *front=(*front+1)%n;
    }
    return value;
}


int get_front(int q[],int n, int*front, int*rear)
{
    if(isEmpty(q,n,front,rear))
    {
        printf("\nQueue is empty, no element at front");
        return -1;
    }
    return q[*front];
}


int get_rear(int q[],int n, int*front, int*rear)
{
    if(isEmpty(q,n,front,rear))
    {
        printf("\nQueue is empty, no element at rear");
        return -1;
    }
    return q[*rear];
}


void display(int q[],int n, int*front, int*rear)
{
    if(isEmpty(q,n,front,rear))
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("Queue:: ");
    int i;
    for(i=*front;i!=*rear;i=(i+1)%n)
    {
        printf("%d ",q[i]);
    }
    printf("%d ",q[i]);

}
