//@uthor: Aadi Kulshreshth
//Bubble Sorting
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
    for(i=0;i<n-1;i++)
    {
        if((ascend && a[i]>a[i+1]) ||(!ascend && a[i]<a[i+1]))
            return 0;
    }
    return 1;
}

void BubbleSortAscend(int a[], int n) 
{
    if(n<=1 || Sorted(a, 1, n)) 
        return;

    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break; 
    }
}

void BubbleSortDescend(int a[], int n) 
{
    if(n<=1 || Sorted(a, 1, n)) 
        return;

    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int Identical(int a[], int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] != a[0])
            return 0;
    return 1;
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
        if (n <= 1 || Identical(a, n)) 
            printf("Array is identical.\n");
        else if (n <= 1 || Sorted(a, 1, n)) 
            printf("Array is already sorted in Ascending.");
        else 
        {
            BubbleSortAscend(a, n);
            printf("Sorted in Ascending order.");
        }
        break;

    case 2:
        if (n <= 1 || Identical(a, n)) 
            printf("Array is identical.\n");
        else if (n <= 1 || Sorted(a, 0, n)) 
            printf("Array is already sorted in Descending.");
        else 
        {
            BubbleSortDescend(a, n);
            printf("Sorted in Descending order.");
        }
        break;

    default:
        printf("Invalid input.");
        return 1;
    }

    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
