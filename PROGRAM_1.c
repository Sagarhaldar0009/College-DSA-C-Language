// AIM : Menu Driven Program - Implement operations (traverse, insert, delete, linear search, selection Sort) on an array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu(){
    printf("\n**** MENU ****\n\n");
    printf("Press 1 for Traverse the Array.\n");
    printf("Press 2 for Inserting an Element in the Array.\n");
    printf("Press 3 for Deleting an Element from the Array.\n");
    printf("Press 4 for Searching an Element from the Array (Linearly) : \n");
    printf("Press 5 for Sorting the Array (Selection Sort) : \n");
    printf("Press 6 for Exit. \n\n");
}
// Function : Traversing the Array
void traverseArray(int *arr, int n){
    printf("Array : ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function : INSERTION of an Element in the Array.
void insertion(int *arr, int *n){
    printf("\nSo, You have Decided to INSERT a Value in the ARRAY.\n\n");
    int pos, Value;
    printf("\nEnter the Position : ");
    scanf("%d", &pos);
    if (pos > *n + 1 || pos <= 0){
        printf("\nCannot Insert any Element at this Position.");
    }
    else{
        printf("\nEnter the Value : ");
        scanf("%d", &Value);
        for (int i = *n - 1; i >= pos - 1; i--){
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = Value;
        *n = *n + 1; // Increment the array size by 1.
        // Printing the Resultant Array
        printf("\nPrinting the Resultant Array : ");
        for (int i = 0; i < *n; i++){
            printf("%d \t", arr[i]);
        }
    }
}

void deletion(int *arr, int *n){    // Function : DELETION of an Element from the Array
    printf("\nSo, You have Decided to DELETE a Value from the ARRAY.\n\n");
    int pos;
    printf("Enter the position of the array's element which you want to delete : \n ");
    scanf(" %d", &pos);
    if (pos <= 0 || pos > *n){
        printf("\nDeletion is not possible for this Position.");
    }
    else{
        for (int i = pos - 1; i < *n; i++){     // use for loop to delete the element and update the index
            arr[i] = arr[i + 1];    // assign arr[i+1] to arr[i]
        }
        *n = *n - 1; // Decrement the array size by 1
        printf("\nResultant Array : "); // Printing the Resultant Array
        for (int i = 0; i < *n; i++){
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}

void LinearSearch(int *arr, int n){     // Function : LINEAR_SEARCH : to search an Element in the Array.
    int i = 0;
    printf("\nSo, You have Decided to perform LINEAR SEARCH in the ARRAY.\n\n");
    int key;
    printf("Enter The Value that you Want to Search : ");
    scanf("%d", &key);
    for (i; i < n; i++){
        if (arr[i] == key){
            printf("%d is Present at Position %d in the array", key, i + 1);
            break;
        }
    }
    if (i == n){
        printf("%d is not Present in the Array.", key);
    }
}

void SelectionSort(int *arr, int n){    // Function : SELECTION_SORT : to Sort the Array.
    printf("\nSo, You have Decided to SORT the ARRAY (By Using Selection Sort).\n\n");
    int i, j, min, temp;
    for (i = 0; i < n; i++){    // Comparison and Swapping the Values.
        min = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min])
                min = j; // updating the Minimum Variable.
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int n; // n->size variable
    printf("Enter the size(or Length) of the Array : ");
    scanf("%d", &n);
    // Special Condition.
    if (n <= 0){
        printf("ERROR : Array is EMPTY.\n");
        exit(0);
    }
    int arr[n];
    printf("Enter %d Elements in the Array : ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Entered Elements are : ");
    for (int i = 0; i < n; i++){
        printf("%d,", arr[i]);
    }
    printf("\n\n");
    char ans[5]; // Decision Variable.
    do{
        menu();
        int choice;
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("So, You have Decided to Traverse the ARRAY.\n");
            traverseArray(arr, n);
            break;
        case 2:
            insertion(arr, &n);
            break;
        case 3:
            deletion(arr, &n);
            break;
        case 4:
            LinearSearch(arr, n);
            break;
        case 5:
            SelectionSort(arr, n);
            printf("\nAfter sorting:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Choose Correct Option to perform an Operation from the Menu : ");
            break;
        }
        printf("\nDo you want to continue? (Yes/No): ");
        scanf("%s", ans); 
    } while (strcmp(ans, "No") != 0);
    return 0;
}