#include<stdio.h>
void TOH(int,char,char,char);
int main()
{
    int n;
    printf("enter the number of disc\n");
    scanf("%d",&n);
    TOH(n,'A','B','C');
    return 0;
}
void TOH(int n,char source,char dest,char help)
{
    if(n==1)
    {
    printf("Move disk %d from rod %c to rod %c \n",n,source,dest,help);
    return;
}
TOH(n-1,source,help,dest);
printf("move disk %d rod %c to rod %c",n,source,dest);
TOH(n-1,help,dest,source);
}
