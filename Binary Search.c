//@uthor: Aadi kulshreshth
//Binary Search
#include<stdio.h>
#define SIZE 100

void title();
void InputArray(int a[], int *n);
int BinarySearch(int ar[], int n, int key);
int Getkey();

int main() 
{
    int a[SIZE], n, i, key, result;

   title();

   InputArray(a, &n);

   key=Getkey();

   result = BinarySearch(a,n,key);

    if (result != -1)
    {
        printf("Element was found at position %d\n", result + 1); 

        for(i=0;i<n;i++)
        {
            if(i != result && a[i]==key)
                printf("Another occurrence found at position %d\n", i +1);
        }

        for(i=0; i<n; i++)
            {
                if(a[i]!=key)
                    break;
            }
        if(i==n)
            printf("The array contains only %d.", key);
    }
    else
        printf("Element not present in the array.\n");

    return 0;
}

void title()
{
    printf("BINARY SEARCH.\n");
}

void InputArray(int a[], int *n)
{
    int i;
    printf("Enter the number of elements to be added in the list:");
    scanf("%d", n);

    printf("Enter the elements in the list:");
    for(i=0; i<*n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<*n;i++)
        printf("%d", a[i]);
}

int Getkey()
{
    int key;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &key);
    return key;
}

int BinarySearch(int arr[], int n, int key) 
{
    int low = 0, high = n - 1, mid;

    while (low <= high) 
    {
        mid = (low + high) / 2;

        if (key == arr[mid])
            return mid; 

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1; 
}