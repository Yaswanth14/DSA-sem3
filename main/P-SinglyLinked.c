#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void InsertBegining(int x)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void InsertionAt(int x)
{
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    struct Node* newnode, *temp;
    int i;
    newnode = malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL) head = newnode;
    else
    {
        temp = head;
        for(i=1;i<(pos-1);i++) temp = temp->next;
        if(temp != NULL)
        {                       
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}


void InsertLast(int x)
{
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    struct Node *temp = head;
    if(head == NULL) head = newnode;
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void DeleteBeg()
{
    if(head->next==NULL) printf("List is empty! \n");
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
    }
}

void DeleteEnd()
{
    if(head == NULL) printf("List is empty!\n");
    else if(head -> next == NULL)  
    {  
        free(head);
        head = NULL;             
    }
    else
    {
        struct Node *temp1,*temp = head;
        while(temp->next!=NULL)
        {
             temp1 = temp;
             temp=temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
}

void DeleteAt()
{
    int pos,i;
    struct Node *temp=head,*temp1;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(head == NULL) printf("List is empty! \n");
    else if(head->next==NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        for(i=0;i<(pos);i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        free(temp);
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
            InsertLast(x);
            break;
        
        case 3:
            x = Ask();
            InsertionAt(x);
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

