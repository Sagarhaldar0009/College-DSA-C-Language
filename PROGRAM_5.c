// AIM :- INSERTION and DELETION in the CIRCULAR DOUBLY LINKED LIST.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

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
    if(isEmpty())
    {
        printf("List is Empty!!!");
        return;
    }
    do
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("HEAD");
}

int getLength(){
    int count=0;

    struct Node* temp = head;
    do
    {
        temp = temp->next;
        count++;
    }
    while(temp!=head);
    return count;
}

// CASE 1.1 : INSERTION AT BEGINNING.
void insertAtBegin(){
    int newData;
    printf("\nEnter the Data that you want to Insert : ");
    scanf("%d",&newData);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;


    if(head == NULL){
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    struct Node* tail = head->prev; // Creating Tail i.e, Last Node of the Linked List.

    head->prev = newNode;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;

    head = newNode;
}

// CASE 1.2 : INSERTION AFTER ANY NODE.
void insertAtLoc(){
    if (isEmpty())
    {
        return;
    }

    int newData;
    printf("\nEnter the Data that you want to Insert : ");
    scanf("%d",&newData);

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
        printf("\nINVALID POSITION. Please Re-Enter Your Choices.\n");
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
void insertAtEnd(){


    struct Node* tail;

    if(head == NULL){
        insertAtBegin();
        return;
    }
    int newData;
    printf("\nEnter the Data that you want to Insert : ");
    scanf("%d",&newData);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = newData;
    tail = head->prev;
    
    newNode->prev = tail;
    tail->next=newNode;
    newNode->next=head;
    head->prev=newNode;

    tail = newNode;
}

// CASE 2.1 : DELETION FROM BEGINNING
void deleteFromBegin(){
    if (isEmpty())
    {
        return;
    }
    if(head == head->next) // If there is only a Single Node in the Linked List.
    {
        free(head);
        head=NULL;
        return;
    }
    struct Node* tail = head->prev;
    struct Node* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;

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

    if(deleteData==head->data)
    {
        deleteFromBegin();
        return;
    }

    struct Node* temp = head;
    struct Node* catch = NULL;
    while(temp->data != deleteData)
    {
        catch = temp;
        temp = temp->next;
    }
    catch->next = temp->next;
    temp->next->prev = catch;
    free(temp);
    do
    {
        if(temp->data == deleteData)
        {
            temp->prev->next=temp->next;
            free(temp);
            return;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("\n\nData you want to delete is not present in List\n\n");
}

// CASE 2.3 : DELETION AT THE END.
void deleteFromEnd(){
    if (isEmpty())
    {
        return;
    }
    if(head == head->next)  // If there is only a Single Node in the Linked List.
    {
        free(head);
        head=NULL;
        return;
    }
    struct Node* tail = head->prev;

    struct Node* temp = tail;

    tail = tail->prev; // shifting BACK.
    tail->next = head;
    head->prev = tail;

    free(temp);
}

// CASE 1 : INSERTION
void insertion()
{
    int choose;
    printf("\nPress 1. to insert node AT THE BEGINNING.\n");
    printf("Press 2. to insert a Node AFTER A GIVEN NODE.\n");
    printf("Press 3. to insert a Node AT THE END.\n");
    printf("Enter your Choice : ");
    scanf("%d", &choose);

    switch(choose)
    {
    case 1:
        insertAtBegin();
        display();
        break;
    case 2:
        insertAtLoc();
        display();
        break;
    case 3:
        insertAtEnd();
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
    printf("\nPress 1. to Delete a Node FROM THE BEGINNING.\n");
    printf("Press 2. to Delete a Node FROM THE BETWEEN OF THE LINKED LIST.\n");
    printf("Press 3. to Delete a Node FROM THE END.\n");
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
        printf("Press 1. to INSERT.\n");
        printf("Press 2. to DELETE.\n");
        printf("Press 3. to DISPLAY.\n");
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

// AYUSH RAWAT PROGRAM
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
//     switch (ch){
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
// void display(){
//     if (head == NULL){
//         printf("\n\nList is Empty\n\n");
//         return;
//     }
//     struct node *head1 = head;
//     printf("\n\n");
//     do{
//         printf("%d ", head1->info);
//         head1 = head1->next;
//     }while (head1 != head);
//     printf("\n\n");
// }
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
//     if (head == NULL){
//         struct node *temp = (struct node *)malloc(sizeof(struct node));
//         head = temp;
//         head->info = ele;
//         head->next = head;
//         head->pre = head;
//         return;
//     }
//     struct node *temp = (struct node *)malloc(sizeof(struct node *));
//     temp->info = ele;
//     temp->next = head;
//     temp->pre = head->pre;
//     head->pre->next = temp;
//     head->pre = temp;
//     head = temp;
// }
// void insert_location(int ele){
//     int num;
//     if (head == NULL){
//         printf("\n\nList is empty, cannot use this operation!!!\n\n");
//         return;
//     }
//     printf("\nEnter number in list before which you want to enter element: ");
//     scanf("%d", &num);
//     if (head->info == num){
//         insert_beginning(ele);
//         display();
//         return;
//     }
//     struct node *head1 = head->next;
//     while (head1 != head){
//     if(head1->info == num){
//         struct node *temp = (struct node *)malloc(sizeof(struct node));
//         temp->info = ele;
//         temp->next = head1;
//         temp->pre = head1->pre;
//         head1->pre->next = temp;
//         display();
//         return;
//     }
//     head1 = head1->next;
//     }
//     printf("\n\nNumber not present in List, cannot insert\n\n");
// }
// void insert_end(int ele){
//     if (head == NULL){
//     struct node *temp = (struct node *)malloc(sizeof(struct node *));
//     head = temp;
//     head->info = ele;
//     head->next = head;
//     head->pre = head;
//     return;
//     }
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->info = ele;
//     temp->next = head;
//     temp->pre = head->pre;
//     head->pre = temp;
//     temp->pre->next = temp;
// }
// void del(){
//     int ch;
//     int num;
//     if (head == NULL){
//         printf("\nList already empty.\n\n");
//         return;
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
//     if (head->next == head){
//     struct node *temp = head;
//     head = NULL;
//     free(temp);
//     return;
//     }
//     struct node *list = head;
//     list->pre->next = list->next;
//     list->next->pre = list->pre;
//     head = head->next;
//     free(list);
// }
// void delete_location(int num){
//     if (head->info == num){
//     delete_beginning();
//     return;
//     }
//     struct node *head1 = head->next;
//     while (head1 != head){
//     if (head1->info == num){
//         head1->next->pre = head1->pre;
//         head1->pre->next = head1->next;
//         free(head1);
//         return;
//     }
//     head1 = head1->next;
//     }
//     printf("\n\nElement not present in list\n\n");
// }
// void delete_end(){
//     if(head->next == head){
//     struct node *temp = head;
//     head = NULL;
//     free(temp);
//     return;
//     }
//     struct node *temp = head->pre;
//     temp->pre->next = head;
//     head->pre = temp->pre;
//     free(temp);
// }