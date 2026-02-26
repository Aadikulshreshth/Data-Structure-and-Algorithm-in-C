//@uthor: Aadi Kulshreshth
//Insertion Sort
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

void InsertionSortAscend(int a[], int n)
{
    if (n <= 1 || Sorted(a, 1, n)) 
        return;

    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

void InsertionSortDescend(int a[], int n)
{
    if (n <= 1 || Sorted(a, 0, n)) 
        return;

    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j] > a[j - 1])
        {
            a[j] = a[j] + a[j - 1];
            a[j - 1] = a[j] - a[j - 1];
            a[j] = a[j] - a[j - 1];
            j--;
        }
    }
}

int main()
{
    int a[SIZE], n, i, choice;

    ArrayElements(&n, a);
    if (n == 0)
        return 0;

    printf("\nChoose the order:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (Identical(a, n))
                printf("All elements are identical.\n");
            else if (Sorted(a, 1, n))
                printf("Array is already sorted Ascending order.\n");
            else
            {
                InsertionSortAscend(a, n);
                printf("Sorted in Ascending order.\n");
            }
            break;

        case 2:
            if (Identical(a, n))
                printf("All elements are identical.\n");
            else if (Sorted(a, 0, n))
                printf("Array is already sorted in Descending order.\n");
            else
            {
                InsertionSortDescend(a, n);
                printf("Sorted in Descending order.\n");
            }
            break;

        default:
            printf("Invalid input.\n");
            return 1;
    }

    printf("\nFinal Array:");
for (i = 0; i < n; i++)
    printf(" %d", a[i]);
printf("\n");

    return 0;
}
