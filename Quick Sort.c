//Quick Sort
//@uthor: Aadi Kulshreshth
#include <stdio.h>
#define SIZE 100

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int low, int high) 
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (a[j] <= pivot) 
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int Sorted(int a[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        if (a[i] < a[i - 1])
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

int main() {
    int n, a[SIZE], i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n == 0) 
    {
        printf("Empty Array\n");
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (Sorted(a, n))
        printf("Array is Already Sorted\n");
    if (Identical(a, n))
        printf("All Elements are Identical\n");

    quickSort(a, 0, n - 1);

    printf("Sorted Array: ");
     for ( i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
