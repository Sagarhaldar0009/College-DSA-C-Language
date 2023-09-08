// Implement Circular Queue Using LinkedList.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front;
struct Node* rear;

void insert();
void delete();
void display();

int size = 0;
#define MAX 3

int main()
{
    
    int choice;
    int perform=1;
    while (perform)
    {  
        printf("\n\n********** MENU **********\n");
        printf("PRESS 1. to Insert element in queue \n");
        printf("PRESS 2. to Delete element from queue \n");
        printf("PRESS 3. to Display all elements of queue \n");
        printf("PRESS 4. to Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            perform=0;
            break;
            default:
            printf("\nWrong choice \n");
        }
    }
return 0;
}

void insert()
{
    if((size+1)>MAX){
        printf("\nOVERFLOW\n");
        return;
    }

    int newData;
    printf("\nEnter New data, that you want to insert : ");
    scanf("%d",&newData);
    
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("\nERROR.\n");
    }
    else
    {
        newNode->data = newData;
        newNode->next = NULL;
        // Initially, when Queue is Empty.
        if(rear == NULL)
        {
            front = rear = newNode;
            rear->next = front;
            size++;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
            size++;
        }
    }
}

void delete()
{
    struct Node *temp = front;

    // CASE 1 : when Queue is Already Empty.
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    // CASE 2 : When there is only 1 Element is Left inside a Queue.
    else if (front == rear)
    {
        printf("\n DELETED Data : %d",front->data);
        front = rear = NULL;
        free(temp);
        size--;
        printf("\n\n Now, Queue is Empty.\n");
    }
    // CASE 3 : Many Elements are Present in the Queue.
    else
    {
        printf("\nDELETED DATA : %d",temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
        size--;
    }
}

int isEmpty(){
    if(front==NULL)
    {
        printf("\n\nList is Empty\n\n");
        return 1;
    }
    else{
        return 0;
    }  
}

void display()
{
    if(isEmpty())
    {
        return;
    }

    printf("The Elements in circular queue:\n");
    struct Node *temp = front;

    printf("\nrear-->");
    do{
        printf("%d-->",temp->data);
        temp = temp->next;
    }while(temp!=front);
    printf("Front");
}