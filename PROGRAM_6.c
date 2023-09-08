//  Write a program to count the number of nodes & reverse the single linked list.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

int isEmpty()
{
    if (head == NULL)
    {
        printf("\nList is EMPTY.");
        printf("\nPlease Insert Node in the Link List.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    if (isEmpty())
    {
        return;
    }
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insert() // Insertion at Beginning.
{
    int data;
    printf("\nEnter the data : ");
    scanf("%d",&data);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // Memory Allocation.
 
    temp->data = data;
    temp->next = head;
 
    head = temp;
}

void countNodes(){

    int count=0;

    struct Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }

    printf("\n\nTotal Number of Nodes = %d",count);
}

void reversed()
{   
    struct Node* previousNode = NULL;
    struct Node* currentNode = head;
    struct Node* NextNode = NULL;

    while(currentNode != NULL)
    {
        NextNode = currentNode->next;       //  Storing the Next Node;
        currentNode->next = previousNode;   //  Now update the next pointer of curr to the prev
        //  Update previousNode as currentNode and currentNode as nextNode
        previousNode = currentNode;
        currentNode = NextNode;
    }
    head = previousNode;

    printf("\nReversed LINKED LIST : ");
    display();
}

int main()
{
    char ans[5];
    do
    {
        int choice;
        printf("\n\n********** MENU ***********\n\n");
        printf("Press '1' to Insert a Node.\n");
        printf("Press '2' to Count Total Number of Nodes.\n");
        printf("Press '3' to Reverse the Linked List.\n");
        printf("Press '4' to EXIT.\n\n");
        printf("Press your Choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1 :
                insert();
                display();
                break;
            case 2 :
                printf("\n");
                display();
                countNodes();
                break;
            case 3 :
                reversed();
                break;
            case 4 :
                exit(0);
                break;
            default :
                printf("ERROR : Invalid Choice. Please Re-Enter your Choice.");
                break;   
        }
        printf("\n\nDo you want to continue? (Yes/No): ");
        scanf("%s", ans);
    }while(strcmp(ans, "No") != 0);
return 0;
}