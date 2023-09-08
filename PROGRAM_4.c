// AIM :- INSERTION and DELETION in the DOUBLY LINKED LIST.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* prev = NULL;

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
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int getLength(){
    int count=0;

    struct Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// CASE 1.1 : INSERTION AT BEGINNING.
void insertAtBegin(int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

// CASE 1.2 : INSERTION AFTER ANY NODE.
void insertAtLoc(int newData){
    if (isEmpty())
    {
        return;
    }

    int pos;
    printf("\nEnter the Position after which you want to insert a new Node: ");
    scanf("%d", &pos);

    if(pos == 0){
        insertAtBegin(newData);
        return;
    }

    int size=0;
    size=getLength(); // Finding length of a Linked List.

    if(pos<1 || pos>size){
        printf("\nINVALID POSITION. Please Re-Enter Your CHOICES.\n");
        return;
    }

    // Allocating a new Node in the Heap.
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;

    struct Node *temp = head;

    int i=0;
    while(i!=pos-1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// CASE 1.3 : INSERTION AT END.
void insertAtEnd(int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = newData;
    newNode->next = NULL;

    if(head == NULL){ // if LinkedList is Empty, then make the newNode as HEAD.
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return;
}

// CASE 2.1 : DELETION FROM BEGINNING
void deleteFromBegin(){
    if (isEmpty())
    {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

// CASE 2.2 : DELETION AFTER ANY NODE.
void deleteFromLoc(){
    if (isEmpty())
    {
        return;
    }
    int deleteData;
    printf("Enter the Data, that you want to Delete from your LinkedList : ");
    scanf("%d", &deleteData);

    struct Node* temp = head;
    struct Node* catch = NULL;
    while(temp->data != deleteData){
        catch = temp;
        temp = temp->next;
    }
    catch->next = temp->next;
    temp->next->prev = catch;
    free(temp);
}

// CASE 2.3 : DELETION AT THE END.
void deleteFromEnd(){
    struct Node* first = head;
    struct Node* second = head->next;
    while(second->next != NULL){
        first = first->next;
        second = second->next;
    }
    first->next = NULL;
    second->prev = NULL;
    free(second);
}

// CASE 1 : INSERTION
void insertion()
{
    int newData;
    printf("\nEnter the Data that you want to Insert : ");
    scanf("%d",&newData);
    int choose;
    printf("\nPress 1. to insert Node AT THE BEGINNING of the Doubly Linked List.\n");
    printf("Press 2. to insert a Node AFTER A GIVEN NODE in the Doubly Linked List.\n");
    printf("Press 3. to insert a Node AT THE END of the Doubly Linked List\n");
    printf("Enter your Choice : ");
    scanf("%d", &choose);

    switch(choose)
    {
    case 1:
        insertAtBegin(newData);
        display();
        break;
    case 2:
        insertAtLoc(newData);
        display();
        break;
    case 3:
        insertAtEnd(newData);
        display();
        break;
    default:
        printf("\nERROR : Invalid Choice.\n");
    }
}
// CASE 2 : DELETION
void deletion()
{
    int choose;
    printf("\nPress 1. to Delete a Node from the beginning of the DOUBLY Linked List\n");
    printf("Press 2. to Delete a Node from the Between of the DOUBLY Linked List.\n");
    printf("Press 3. to Delete a Node from the end of the DOUBLY Linked List.\n");
    printf("Enter your Choice : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        deleteFromBegin();
        display();
        break;
    case 2:
        deleteFromLoc();
        display();
        break;
    case 3:
        deleteFromEnd();
        display();
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
        int choice;
        printf("\n\n*************** MENU ***************\n\n");
        printf("Press 1. to INSERT any Node in the DOUBLY LINKED LIST.\n");
        printf("Press 2. to DELETE any Node from the DOUBLY LINKED LIST.\n");
        printf("Press 3. to DISPLAY the DOUBLY LINKED LIST.\n");
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


// AYUSH RAWAT KA PROGRAM
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int info;
//     struct node *next;
//     struct node *pre;
// };
// struct node *head = NULL;
// void menu();
// void display();
// void ins();
// void insert_beginning(int ele);
// void insert_location(int ele);
// void insert_end(int ele);
// void del();
// void delete_beginning();
// void delete_location(int num);
// void delete_end();
// int main()
// {
//     menu();
//     return 0;
// }
// void menu(){
//     int ch;
//     do{
//     printf("Press '1' to display the List\nPress '2' to insert element in List\nPress '3' to delete element from List\nPress '4' to exit\n");

//     printf("\nEnter operation: ");
//     scanf("%d",&ch);
//     switch (ch) {
//         case 1:
//             display();
//             break;
//         case 2:
//             ins();
//             break;
//         case 3:
//             del();
//             break;
//         case 4:
//             printf("\n\n\nExiting....");
//             break;
//         default:
//             printf("\n\n\nInvalid choice....");
//             break;
//     }
//     } while (ch != 4);
// }
// // Display
// void display(){
//     if (head == NULL){
//         printf("\n\nList is Empty\n\n");
//         return;
//     }
//     struct node *head1 = head;
//     printf("\n\n");
//     while (head1 != NULL){
//         printf("%d ", head1->info);
//         head1 = head1->next;
//     }
//     printf("\n\n");
// }
// // Insertion
// void ins(){
//     int ch;
//     int ele;
//     int num;
//     printf("\n\nPress '1' to insert element at the beginning\nPress '2' to insert element before some element already present in List\nPress '3' to insert element at the end\n");
//     printf("\nEnter your choice: ");
//     scanf("%d",&ch);
//     printf("\nEnter number you want to insert: ");
//     scanf("%d",&ele);
//     switch (ch){
//         case 1:
//             insert_beginning(ele);
//             display();
//             break;
//         case 2:
//             insert_location(ele);
//             break;
//         case 3:
//             insert_end(ele);
//             display();
//             break;
//         default:
//             printf("\n\n\nInvalid choice....\n\n");
//             break;
//     }
// }
// void insert_beginning(int ele){
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->next = head;
//     temp->pre = NULL;
//     temp->info = ele;
//     head = temp;
// }
// void insert_location(int ele){
//     int num;
//     if (head == NULL){
//     printf("\n\nList is empty, cannot use this operation!!!\n\n");
//     return;
//     }
//     printf("\nEnter number in list before which you want to enter element: ");
//     scanf("%d", &num);
//     if (head->info == num){
//     insert_beginning(ele);
//     display();
//     return;
//     }
//     struct node *head1 = head->next;
//     struct node *list = head;
//     while (head1 != NULL){
//     if (head1->info == num){
//         struct node *temp = (struct node *)malloc(sizeof(struct node));
//         temp->info = ele;
//         temp->next = head1;
//         temp->pre = list;
//         list->next = temp;
//         display();
//         return;
//     }
//     list = head1;
//     head1 = head1->next;
//     }
//     printf("\n\nNumber not present in List, cannot insert\n\n");
// }
// void insert_end(int ele){
//     if (head == NULL){
//     insert_beginning(ele);
//     return;
//     }
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     struct node *head1 = head;
//     // struct node* list=head;
//     while (head1->next != NULL){
//     // list=head1;
//     head1 = head1->next;
//     }
//     // list->next=temp;
//     head1->next = temp;
//     temp->info = ele;
//     temp->pre = head1;
//     temp->next = NULL;
// }
// // Deletion
// void del(){
//     int ch;
//     int num;
//     if (head == NULL){
//     printf("\nList already empty.\n\n");
//     return;
//     }
//     printf("\n\nPress '1' to delete element from the beginning\nPress '2' to delete element from in between the List\nPress '3' to delete element from the end\n");
//     printf("\nEnter your choice: ");
//     scanf("%d",&ch);
//     switch (ch){
//         case 1:
//             delete_beginning();
//             display();
//             break;
//         case 2:
//             printf("\nEnter element you want to delete : ");
//             scanf("%d", &num);
//             delete_location(num);
//             display();
//             break;
//         case 3:
//             delete_end();
//             display();
//             break;
//         default:
//             printf("\n\n\nInvalid choice....\n\n");
//             break;
//     }
// }
// void delete_beginning(){
//     struct node *temp = head;
//     head = head->next;
//     if (head != NULL)
//     head->pre = NULL;
//     free(temp);
// }
// void delete_location(int num){
//     if (head->info == num){
//         delete_beginning();
//         return;
//     }
//     struct node *head1 = head->next;
//     struct node *list = head;
//     while (head1 != NULL){
//         if (head1->info == num){
//             list->next = head1->next;
//             if (head1->next != NULL)
//             {
//                 head1->next->pre = head1->pre;
//             }
//             free(head1);
//             return;
//         }
//         list = head1;
//         head1 = head1->next;
//     }
//     printf("\n\nElement not present in list\n\n");
// }
// void delete_end(){
//     if (head->next == NULL){
//     delete_beginning();
//     return;
//     }
//     struct node *temp = head->next;
//     struct node *list = head;
//     while (temp->next != NULL){
//     list = temp;
//     temp = temp->next;
//     }
//     list->next = NULL;
//     free(temp);
// }