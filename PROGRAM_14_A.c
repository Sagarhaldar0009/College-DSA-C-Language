// Implement Circular Queue Using Array.
#include<stdio.h>

#define MAX 3
int queue_array[MAX];
int rear = - 1;
int front = - 1;

void insert()
{
    int x;
    // Condition for OverFlow
    if(front == ((rear+1)%MAX))
    {
        printf("\nQueue Overflow \n");
        return;
    }
    printf("\nInsert the element in queue : ");
    scanf("%d", &x);
    // Initially, when Queue is Empty.
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue_array[rear] = x;
    }
    else    // Inserting Elements, when Some Elements are Already Present inside Queue.
    {
        rear = (rear+1)%MAX; 
        queue_array[rear] = x;
    }
} 

void delete()
{
    if (front == - 1 && rear == -1)
    {
        printf("\nQueue Underflow \n");
        return ;
    }
    else if(front == rear) // when Only 1 Element is Left in a Queue. 
    {   
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = (front + 1)%MAX;
    }
}

void display()
{
    int i = front;
    if (front == - 1 || rear == -1)
    {
        printf("\nQueue is empty \n");
    }     
    else
    {
        printf("\nQueue is : ");
        while(i != rear)
        {
            printf("%d ", queue_array[i]);
            i = (i+1)%MAX;
        }
        printf("%d",queue_array[rear]);
        printf("\n");
    }
} 

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