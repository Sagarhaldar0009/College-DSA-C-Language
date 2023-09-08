//AIM : Implement operations (push, pop) on a stack using arrays. Check the status of the stack whether there is underflow or overflow.

#include<stdio.h>
#include<stdlib.h>

// Defining the Stack using Array with maximum size = 5.
int stack[5];
int size = 2; // MAX SIZE of STACK.
int tos = -1; // Initialising the index for Top of the Stack.

int num;

void push(){
    printf("\nEnter the VALUE, that you want to PUSH : ");
    scanf("%d",&num);

    if(tos<size-1){
        tos++;
        stack[tos] = num;
        printf("\n%d has been Successfully PUSHED into Stack.\n",num);
        return;
    }
    else{
        printf("\nOVERFLOW.\n");
    }
}

void pop(){
    if(tos < 0){
        printf("\nUNDERFLOW.\n");
        return;
    }
    else{
        printf("\nPOPED element from stack is %d\n",stack[tos]);
        tos--;
    }
}

void display(){
    if(tos == -1){
        printf("\nSTACK is EMPTY.\n");
        return;
    }
    else{
        printf("\nElements inside the STACK : ");
        for(int i=0; i<=tos; i++){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    char ans[5];
    int perform = 1;
    while(perform)
    {
        printf("\nPress '1' to PUSH an ELEMENT into the stack. ");
        printf("\nPress '2' to POP an ELEMENT into the stack. ");
        printf("\nPress '3' to DISPLAY the Elements in the Stack.");
        printf("\nPress '4' to EXIT.");
        printf("\n\nEnter your CHOICE : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                push();
                break;
            case 2 : 
                pop();
                break;
            case 3 :
                display();
                break;
            case 4 :
                perform=0;
                break;
            default :
                printf("Wrong Choice. Please Rechoice.");
                break;
        }
    }  
return 0;
}