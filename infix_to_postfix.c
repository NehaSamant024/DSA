#include<stdio.h>
#include<string.h>
#define MAX 1000
char st[MAX];
int top = -1;
void push(char value){
    st[++top] = value;
}
char pop(){
    return st[top--];
}
int priority(char value){
    if(value == '('){
        return 0;
    }
    else if(value == '+' || value == '-'){
        return 1;
    }
    else if(value == '*' || value == '/' || value == '%'){
        return 2;
    }
    else if(value == '^'){
        return 3;
    }
}
int main(){
    char a[MAX];
    char b;
    fgets(a,MAX,stdin);
    for(int i=0;i<strlen(a);i++){
        if((a[i] >= '%' && a[i] <= '/') || a[i] == '^'){
            if(a[i] == '('){
                push(a[i]);
            }
            else if(a[i] == ')'){
                while((b = pop()) != '('){
                    printf("%c ",b);
                }
            }
            else{
                while(priority(a[i]) <= priority(st[top])){
                    printf("%c ",pop());
                }
                push(a[i]);
            }
        }
        else if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')){
            printf("%c ",a[i]);
        }
    }
    while(top != -1){
        printf("%c ",pop());
    }
    return 0;
}
