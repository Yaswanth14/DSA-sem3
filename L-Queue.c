#include <stdio.h>
#include <stdlib.h>
#define max 50

void enque();
void deque();
void display();
void peek();
void isfull();
void isempty();

int queue[max];
int rear = -1, front = -1;

int main(){
    int op;
    while(1){
        printf("1.enque, 2.deque, 3.diaplay, 4.isfull, 5.isempty, 6.peek, 7.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        
        switch (op)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;

        case 3:
            display();
            break;

        case 4:
            isfull();
            break;

        case 5:
            isempty();
            break;

        case 6:
            peek();
            break;

        case 7:
            exit(1);
        
        default:
            printf("Invalid!\n");
            break;
        }
    }
}

void enque(){
    int item;
    if(rear== max-1) printf("Overflow!\n");
    else{
        if(front==-1) front++;
        printf("Insert element value: ");
        scanf("%d",&item);
        rear++;
        queue[rear] = item;
    }
}

void deque(){
    if(front==-1||front>rear){
        printf("Underflow!\n");
        return;
    }
    else{
        printf("Deleted element = %d\n",queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(front==-1||front>rear) printf("Queue is empty!\n");
    else{
        for(i=front;i<=rear;i++) printf("%d ",queue[i]);
        printf("\n");
    }
}

void isfull(){
    if(rear==(max-1)) printf("Queue is full!\n");
    else printf("Queue still has some space!\n");
}

void isempty(){
    if(front==-1||front>rear) printf("Queue is empty!\n");
    else printf("Queue is not empty!\n");
}

void peek(){
    if(front==-1||front>rear) printf("You can't peek an empty queue!\n");
    else printf("%d\n",queue[front]);
}

