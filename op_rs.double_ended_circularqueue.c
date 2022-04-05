#include<stdio.h>
#include<stdlib.h>

int isEmpty(int q[],int n, int*front, int*rear);

int isFull(int q[],int n, int*front, int*rear);

void insert_front(int q[],int n, int*front, int*rear, int value);

void insert_rear(int q[],int n, int*front, int*rear, int value);

int remove_front(int q[],int n, int*front, int*rear);

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
        printf("\n1.INSERT AT FRONT\n");
        printf("2.INSERT AT REAR\n");
        printf("3.REMOVE FROM FRONT\n");
        printf("4.GET FRONT\n");
        printf("5.GET REAR\n");
        printf("6.IS EMPTY ?\n");
        printf("7.IS FULL ?\n");
        printf("8.DISPLAY\n");
        printf("9.EXIT\n");
        printf("\nEnter your choice::");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                int value;
                printf("\nEnter value to be inserted at front:");
                scanf("%d",&value);
                insert_front(queue,n,&front,&rear,value);
                break;
            }
            case 2:
            {
                int value;
                printf("\nEnter value to be inserted at rear:");
                scanf("%d",&value);
                insert_rear(queue,n,&front,&rear,value);
                break;
            }
            case 3:
            {
                int value;
                value=remove_front(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue %d removed from front",value);
                }
                break;
            }
            case 4:
            {
                int value;
                value=get_front(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at front: %d",value);
                }
                break;
            }
            case 5:
            {
                int value;
                value=get_rear(queue,n,&front,&rear);
                if(value!=-1)
                {
                    printf("\nValue at rear: %d",value);
                }
                break;
            }
            case 6:
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
            case 7:
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
            case 8:
            {
                display(queue,n,&front,&rear);
                break;
            }
            case 9:
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


void insert_front(int q[],int n, int*front, int*rear, int value)
{
    if(isFull(q,n,front,rear))
    {
        printf("\nQueue is Full");
        return;
    }
    if(*front==-1)
    {
        *front=0;
        *rear=0;
    }
    else if(*front==0)
    {
        *front=n-1;
    }
    else 
    {
        (*front)--;
    }
    q[*front]=value;
}


void insert_rear(int q[],int n, int*front, int*rear, int value)
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


int remove_front(int q[],int n, int*front, int*rear)
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
