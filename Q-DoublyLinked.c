#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

void InsertBegining(int x)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL) head = newnode;
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void InsertEnd(int x)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    struct Node* temp = head;
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL) head = newnode;
    else
    {
        while(temp->next!=NULL) temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void InsertAt(int x)
{
    int pos;
    printf("Enter postition: ");
    scanf("%d",&pos);
    struct Node* newnode = malloc(sizeof(struct Node));
    struct Node* temp = head;
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head==NULL) head = newnode;
    else
    {
        for(int i=1;i<pos;i++) temp = temp->next;
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void DeleteBeg()
{
    struct Node *ptr;
    if(head->next==NULL) printf("List is empty!\n");
    else if(head->next==NULL)
    {
        head = NULL;
        free(head);
    }
    else 
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
}

void DeleteAt()
{
    struct Node *ptr = head;
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    if(head == NULL) printf("List is empty!");
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
}

void DeleteEnd()
{
    struct Node *ptr = head;
    int pos;
    if(head == NULL) printf("List is empty!");
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
    } 
    else
    {
        while(ptr->next!=NULL) ptr = ptr->next;
        ptr->prev->next = NULL;
        free(ptr);
    }
}

void Print()
{
    struct Node* ptr = head;
    printf("List is: ");
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}

int Ask()
{
    int x;
    printf("Eter a value: ");
    scanf("%d",&x);
    return x;
}

int main()
{
    int x;
    head = NULL;
    printf("1.InsertBegining, 2.InsertLast, 3.InsertPos, 4.DeleteBeg, 5.DeleteEnd, 6.DeletePos, 7.exit, 8.Print\n");
    while(1)
    {
        int op;
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            x = Ask();
            InsertBegining(x);
            break;
        
        case 2:
            x = Ask();
            InsertEnd(x);
            break;
        
        case 3:
            x = Ask();
            InsertAt(x);
            break;
        
        case 4:
            DeleteBeg();
            break;
        case 5:
            DeleteEnd();
            break;

        case 6:
            DeleteAt();
            break;

        case 7:
            exit(1);
            break;

        case 8:
            Print();
            break;

        default:
        printf("Something went wrong!\n");
            break;
        }
    }
    return 0;
}
