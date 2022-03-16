#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[30];
int top = -1;
void push(char x);
char pop();
int priority(char x);


int main(){
    char exp[20];
    char *e,x1;

    printf("Enter an exression: ");
    scanf("%s",exp);
    e = exp;

    while(*e !='\0'){
        if(isalnum(*e)) printf("%c",*e);
        else if(*e == '(') push(*e);
        else if(*e == ')'){
                while((x1 = pop())!='('){
                printf("%c",x1); //print value in pop
            }
        }
        else{
            while(priority(stack[top])>=priority(*e)) printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}

void push(char x){
    top++;
    stack[top] = x;
}

char pop(){
    char c = stack[top];
    top--;
    return c;
}

int priority(char x){
if(x=='/') return 4;
if(x=='*') return 3;
if(x=='+') return 2;
if(x=='-') return 1;
if(x=='(') return 0;  
}

