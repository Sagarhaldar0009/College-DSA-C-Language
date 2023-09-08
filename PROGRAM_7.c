//  Write a program to merge two sorted linked list and display the final sorted linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
void List_Entry(struct node **head, int n);
void display(struct node **head);
void insert_end(struct node ***head, int ele);
void List_Sort(struct node **head, struct node **l1, struct node **l2);
int main()
{
    struct node *head = NULL;
    struct node *l1 = NULL;
    struct node *l2 = NULL;
    int n1, n2;
    printf("\n\nEnter number of items in list 1: ");
    scanf("%d", &n1);
    List_Entry(&l1, n1);
    printf("\n\nList 1 :\n\n");
    display(&l1);
    printf("\n\nEnter number of items in list 2: ");
    scanf("%d", &n2);
    List_Entry(&l2, n2);
    printf("\n\nList 2 :\n\n");
    display(&l2);
    List_Sort(&head, &l1, &l2);
    printf("\n\nLists after sorting and merging:\n\n");
    display(&head);
    return 0;
}
void List_Entry(struct node **head, int n){
    int z = n;
    while (z--){
        int ele;
        printf("Enter info of node %d: ", n - z);
        scanf("%d", &ele);
        insert_end(&head, ele);
    }
}
void insert_end(struct node ***head, int ele){
    if (**head == NULL){
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = **head;
        temp->info = ele;
        **head = temp;
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *head1 = **head;
    struct node *list = **head;
    while (head1 != NULL){
        list = head1;
        head1 = head1->next;
    }
    list->next = temp;
    temp->info = ele;
    temp->next = NULL;
}
void display(struct node **head){
    if (*head == NULL){
        printf("\n\nList is Empty\n\n");
        return;
    }
    struct node *head1 = *head;
    printf("\n\n");
    while (head1 != NULL){
        printf("%d ", head1->info);
        head1 = head1->next;
    }
    printf("\n\n");
}
void List_Sort(struct node **head, struct node **l1, struct node **l2){
    struct node *list1 = *l1;
    struct node *list2 = *l2;
    while (list1 != NULL && list2 != NULL){
        if (list1->info < list2->info){
            insert_end(&head, list1->info);
            list1 = list1->next;
        }
        else{
            insert_end(&head, list2->info);
            list2 = list2->next;
        }
    }
    while (list1 != NULL){
        insert_end(&head, list1->info);
        list1 = list1->next;
    }
    while (list2 != NULL){
        insert_end(&head, list2->info);
        list2 = list2->next;
    }
}