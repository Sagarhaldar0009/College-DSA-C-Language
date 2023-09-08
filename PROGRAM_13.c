// AIM : Implement operations (enqueue, dequeue) on a queue using arrays. Check the status of the queue whether it is empty or full.
#include <stdio.h>
 
#define MAX 3
 
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main()
{
    int choice;
    int perform=1;
    while (perform)
    {   
        printf("\n********** MENU **********\n");
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
    int x; // value to be insert.
    if (rear == MAX - 1){
        printf("\nQueue Overflow \n");
    }
    else
    {
        if (front == - 1)
        {
           front = 0; /*If queue is initially empty */
        } 
        printf("\nInsert the element in queue : ");
        scanf("%d", &x);
        rear = rear + 1;
        queue_array[rear] = x;
    }
} 

 
void delete()
{
    if (front == - 1)
    {
        printf("\nQueue Underflow \n");
        return ;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

 
void display()
{
    int i;
    if (front == - 1)
    {
        printf("\nQueue is empty \n");
    }     
    else
    {
        printf("\nQueue is : ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
} 