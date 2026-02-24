//@uthor: Aadi Kulshreshth
//Linear Search
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void title()
{
    printf("LINEAR SEARCH OF A LIST OF ELEMENTS.");
}
void ListElements(int a[], int *n)
{
    int i;
    printf("\nEnter the number of elements in the list:\n");
    scanf("%d", n);

    if(*n==0)
    {
        printf("Empty Array Edge Case.\n");
        exit(0);
    }

    printf("Enter the elements in the list:\n");
    for(i=0;i<*n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<*n;i++)
        printf(" %d", a[i]);

}
int Searchkey()
{
    int key;
    printf("\nEnter the Search Key:");
    scanf("%d",&key);
    return key;

}
int LinearSearch(int a[], int n, int key)
{
    int flag=-1, i;
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            printf("First occurrence of the element found at %d position.\n", i+1);
            flag=1;
            break;
        }
    }
    if (flag==-1)
        printf("\nElement not present in the list.\n");
    else
    {
        for(i=i+1;i<n;i++)
        {
            if(key==a[i])
                printf("Other occurrences of the element found at %d position.\n", i+1);
        }
    }
    return flag;

}
int main()
{
    int a[SIZE], n, key;
    title(); 

    ListElements(a, &n);

    key=Searchkey();

    LinearSearch(a, n, key);

    return 0;
}