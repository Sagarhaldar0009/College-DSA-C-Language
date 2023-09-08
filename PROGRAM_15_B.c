#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
void menu(struct node **head, struct node **rear);
void display(struct node ***head);
void enqueue(struct node ***head, struct node ***rear);
void dequeue(struct node ***head, struct node ***rear);
int main()
{
    struct node *head = NULL;
    struct node *rear = NULL;
    menu(&head, &rear);
    return 0;
}
void menu(struct node **head, struct node **rear){
    int ch;
    do{
        printf("Press '1' to display the Queue\nPress '2' to ENQUEUE\nPress '3' to DEQUEUE\nPress '4' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch) {
                case 1:
                    display(&head);
                    break;
                case 2:
                    enqueue(&head, &rear);
                    display(&head);
                    break;
                case 3:
                    dequeue(&head, &rear);
                    display(&head);
                    break;
                case 4:
                    printf("\n\n\nExiting....");
                    break;
                default:
                    printf("\n\n\nInvalid choice....\n\n");
                    break;
        }
    } while (ch != 4);
}
void display(struct node ***head){
    if (**head == NULL){
        printf("\n\nQueue is Empty\n\n");
        return;
    }
    struct node *head1 = (**head);
    printf("\n\n");
    while (head1 != NULL){
        printf("%d ", head1->num);
        head1 = head1->next;
    }
    printf("\n\n");
}
void enqueue(struct node ***head, struct node ***rear){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("\n\nOVERFLOW !!!\n\n");
        return;
    }
    int ele;
    printf("\n\nEnter number you want to insert: ");
    scanf("%d", &ele);
    temp->num = ele;
    temp->next = NULL;
    if ((**rear) == NULL){
        (**head) = temp;
        (**rear) = temp;
        return;
    }
    (**rear)->next = temp;
    (**rear) = temp;
}
void dequeue(struct node ***head, struct node ***rear){
    if ((**head) == NULL){
        printf("\nUNDERFLOW !!!\n\n");
        return;
    }
    struct node *temp = (**head);
    (**head) = (**head)->next;
    if ((**head) == NULL){
        (**rear) = NULL;
    }
    free(temp);
}