//@uthor: Aadi Kulshreshth 
//Selection Sorting
#include <stdio.h>
#define SIZE 100

void ArrayElements(int *n, int a[]) 
{
    int i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", n);

    if (*n == 0) 
    {
        printf("Empty array.\n");
        return;
    }

    printf("Enter %d elements in the list: ", *n);
    for (i = 0; i < *n; i++)
        scanf("%d", &a[i]);

    printf("The list is:");
    for (i = 0; i < *n; i++)
        printf(" %d", a[i]);
    printf("\n");
}

int Sorted(int a[], int ascend, int n)
{
    int i;
    for (i = 0; i < n - 1; i++) 
    {
        if ((ascend && a[i] > a[i + 1]) || (!ascend && a[i] < a[i + 1]))
            return 0;
    }
    return 1;
}

int Identical(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
            return 0;
    }
    return 1;
}

void SelectionSortAscend(int a[], int n) 
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) 
    {
        minIndex = i;
        for (j = i + 1; j < n; j++) 
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i) 
        {
            a[i] = a[i] ^ a[minIndex];
            a[minIndex] = a[i] ^ a[minIndex];
            a[i] = a[i] ^ a[minIndex];
        }
    }
}

void SelectionSortDescend(int a[], int n) 
{
    int i, j, maxIndex;

    for (i = 0; i < n - 1; i++) 
    {
        maxIndex = i;
        for (j = i + 1; j < n; j++) 
        {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i) 
        {
            a[maxIndex] = a[maxIndex] + a[i];
            a[i] = a[maxIndex] - a[i];
            a[maxIndex] = a[maxIndex] - a[i];
        }
    }
}

int main() 
{
    int a[SIZE], n, choice, i;

    ArrayElements(&n, a);
    if (n == 0) return 0;

    printf("\nChoose the order:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            if (Identical(a, n)) 
                printf("Array is identical.");
            else if (n <= 1 || Sorted(a, 1, n)) 
                printf("Array is already sorted in Ascending order.");
            else 
            {
                SelectionSortAscend(a, n);
                printf("Sorted in Ascending order.");
            }
            break;

        case 2:
            if (Identical(a, n)) 
                printf("Array is identical.");
            else if (n <= 1 || Sorted(a, 0, n)) 
                printf("Array is already sorted in Descending order.");
            else 
            {
                SelectionSortDescend(a, n);
                printf("Sorted in Descending order.");
            }
            break;

        default:
            printf("Invalid input.");
            return 1;
    }

    printf("\nFinal Array:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
