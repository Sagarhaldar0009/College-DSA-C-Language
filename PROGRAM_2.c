// AIM : Implement INSERTION and DELETION(at the beginning, at specified location, at the end) on Single Linked List.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

// Creating a head Node, initialised with 'NULL' value.
struct Node *head = NULL;

int isEmpty()
{
    if (head == NULL)
    {
        printf("\n\nList is Empty\n\n");
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

// FUNCTION : INSERTION_CASE_1 : Insert a Node at the Beginning of Linked List.
void insertAtBegin()
{

    int newData;
    printf("\nEnter the Data that you want to insert : ");
    scanf("%d", &newData);

    // Allocating a new Node in the Heap.
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->next = head;
    newNode->data = newData;
    head = newNode;
}

// FUNCTION : INSERTION_CASE_2 : Insert a Node at any Specific Position of Linked List.
void insertAtLoc()
{
    if (isEmpty())
    {
        return;
    }

    int newData;
    printf("\nEnter the Data that you want to insert : ");
    scanf("%d", &newData);
    int pos;
    printf("\nEnter the Position of Node after which you want to insert element: ");
    scanf("%d", &pos);

    // Allocating a new Node in the Heap.
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // put in the data
    newNode->data = newData;

    struct Node *temp = head;

    int i = 0; // For traverse the LinkedList from Head Node (by assuming it's index == 0)
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next; // join the link
    temp->next = newNode;       // break the Link.
}
// FUNCTION : INSERTION_CASE_3 : Insert a Node at the end of Linked List.
void insertAtEnd()
{

    if (isEmpty())
    {
        return;
    }

    int newData;
    printf("\nEnter the Data that you want to insert : ");
    scanf("%d", &newData);

    // Allocating a new Node in the Heap.
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    // Condition : if Linked list is EMPTY, Then make the new node as head.
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// FUNCTION : DELETION_CASE_1 : delete a Node from the Beginning of a Linked List.
void deleteFromBegin()
{
    if (isEmpty())
    {
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}
// FUNCTION : DELETION_CASE_2 : delete a Node from any specific position of a Linked List.
void deleteFromLoc()
{
    if (isEmpty())
    {
        return;
    }

    int deleteData;
    printf("Enter the Data, that you want to Delete from your LinkedList : ");
    scanf("%d", &deleteData);

    struct Node *temp = head;
    struct Node *list = NULL;

    while (temp->data != deleteData)
    {
        list = temp;
        temp = temp->next;
    }
    list->next = temp->next;
    free(temp);
}
// FUNCTION : DELETION_CASE_3 : delete a Node from the End of a Linked List.
void deleteFromEnd()
{
    if (isEmpty())
    {
        return;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

// INSERTION
void insertion()
{
    int choose;
    printf("\nPress 1. to insert Node at the beginning\n");
    printf("Press 2. to insert a Node after a given Node.\n");
    printf("Press 3. to insert a Node at the end\n");
    printf("Enter your Choice : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        insertAtBegin();
        break;
    case 2:
        insertAtLoc();
        break;
    case 3:
        insertAtEnd();
        break;
    default:
        printf("\nERROR : Invalid Choice.\n");
    }
}
// DELETION
void deletion()
{
    int choose;
    printf("\nPress 1. to Delete a Node from the beginning of the Linked List\n");
    printf("Press 2. to Delete a Node from the Between of the Linked List.\n");
    printf("Press 3. to Delete a Node from the end of the Linked List.\n");
    printf("Enter your Choice : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        deleteFromBegin();
        break;
    case 2:
        deleteFromLoc();
        break;
    case 3:
        deleteFromEnd();
        break;
    default:
        printf("\nERROR : Invalid Choice.\n");
    }
}

int main()
{
    char ans[5];
    do
    {
        // MENU
        int choice;
        printf("\nPress 1. to INSERT any Node in the Single Linked List\n");
        printf("Press 2. to DELETE any Node from the Single List List\n");
        printf("Press 3. to DISPLAY the LINKED LIST\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertion();
            break;

        case 2:
            deletion();
            break;

        case 3:
            display();
            break;

        default:
            printf("ERROR : INVALID CHOICE.");
            break;
        }
        printf("\nDo you want to continue? (Yes/No): ");
        scanf("%s", ans);
    } while (strcmp(ans, "No") != 0);

    return 0;
}