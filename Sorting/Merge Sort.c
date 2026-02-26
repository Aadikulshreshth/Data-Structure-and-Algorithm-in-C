//Merge Sort
//@uthor: Aadi Kulshreshth
#include <stdio.h>
#define SIZE 100

void merge(int a[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) 
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int Sorted(int a[], int n) 
{
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return 0;
    return 1;
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
    int n, a[SIZE], i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Empty array.\n");
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n == 1) {
        printf("Single element array.\n");
    } else if (Identical(a, n)) {
        printf("All elements are identical.\n");
    } else if (Sorted(a, n)) {
        printf("Array is already sorted.\n");
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
