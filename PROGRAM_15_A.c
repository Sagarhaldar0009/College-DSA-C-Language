#include <stdio.h>
#include <stdlib.h>
struct node{
    int num;
    struct node *next;
};
void menu(struct node **head);
void display(struct node **head);
void push(struct node **head);
void pop(struct node **head);
int main()
{
    struct node *head = NULL;
    menu(&head);
    return 0;
}
void menu(struct node **head){
    int ch;
    do{
        printf("Press '1' to display the Stack\nPress '2' to PUSH\nPress '3' to POP\nPress '4' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch){
                case 1:display(head);
                    break;
                case 2:push(head);
                    display(head);
                    break;
                case 3:pop(head);
                    display(head);
                    break;
                case 4:printf("\n\n\nExiting....");
                    break;
                default:printf("\n\n\nInvalid choice....\n\n");
                    break;
        }
    } while (ch != 4);
}
void display(struct node **head){
    if (*head == NULL){
        printf("\n\nStack is Empty\n\n");
        return;
    }
    struct node *head1 = *head;
    printf("\n\nTOS --> ");
    while (head1 != NULL){
    printf("%d ", head1->num);
    head1 = head1->next;
    }
    printf("\n\n");
}
void push(struct node **head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("\n\nOVERFLOW !!!\n\n");
        return;
    }
    int ele;
    printf("\n\nEnter number you want to insert: ");
    scanf("%d", &ele);
    temp->next = *head;
    temp->num = ele;
    *head = temp;
}
void pop(struct node **head){
    if (*head == NULL){
        printf("\nUNDERFLOW !!!\n\n");
        return;
    }
    struct node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}