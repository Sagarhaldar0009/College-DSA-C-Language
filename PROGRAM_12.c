#include <stdio.h>

int binarySearch(int arr[], int key, int start, int end)
{
    // BASE CASE
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    else if (arr[mid] > key) // 1st Half - LEFT SIDE
    {
        return binarySearch(arr, key, start, mid - 1);
    }
    else // 2nd Half - RIGHT SIDE
    {
        return binarySearch(arr, key, mid + 1, end);
    }
}

int main()
{
    int n; // n->size variable
    // Special Condition.
    int size = 1;
    while (size)
    {
        printf("\nEnter the size(or Length) of the Array : ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("ERROR : Array is EMPTY.\n");
            printf("\nPlease Enter Appropriate Size (Size>0) for an ARRAY.");
            size = 1;
        }
        else
        {
            size = 0;
        }
    }

    int arr[n];
    printf("Enter %d Elements in the Array : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Entered Elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n\n");

    int key;
    int choice;
    int perform = 1;
    int flag = 1;

    while (perform)
    {

        printf("\nEnter the Element that you want to Search : ");
        scanf("%d", &key);

        int index = binarySearch(arr, key, 0, n - 1);

        if (index == -1)
        {
            printf("\n%d is not Present in the Array.");
        }
        else
        {
            printf("\n\n%d is FOUNDED at index number %d.", key, index);
        }

        while (flag)
        {
            printf("\n\nDo You Want to Search More Elemenst in the Array ??");
            printf("\nPress 1. - YES. ");
            printf("\nPress 2. - NO.");
            printf("\nPlease Enter your Choice : ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                perform = 1;
                flag = 0;
            }
            else if (choice == 2)
            {
                perform = 0;
                flag = 0;
            }
            else
            {
                printf("\nPlease Re-Enter & Choose Correct Choice.\n");
                flag = 1;
            }
        }
        flag = 1;
    }
    return 0;
}