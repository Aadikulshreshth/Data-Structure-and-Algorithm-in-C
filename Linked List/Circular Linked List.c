//@uthor: Aadi Kulshreshth
//Circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

void insertionatbeginning(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
}

void insertionatend(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data= data;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        
        temp->next=newnode;
        newnode->next=head;
    }
}

void insertionatposition(int data, int pos)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;

    if(pos==1)
    {
        insertionatbeginning(data);
        return;
    }

    struct node *temp=head;
    int i;

    for(i=1; i<pos-1 && temp->next !=head; i++)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Invalid position.");
        free(newnode);
        return;
    }

    newnode->next=temp->next;
    temp->next=newnode;
}

void deletionatbeginning()
{
    if(head==NULL)
    {
        printf("Empty List");
        return;
    }
    struct node *temp=head;

    if(head->next==head)
    {
        head=NULL;
        free(temp);
        return;
    }

    struct node *last=head;
    while(last->next!=head)
        last=last->next;
    head=head->next;
    last->next=head;
    free(temp);
}

void deletionatend()
{
    if(head==NULL)
    {
        printf("Empty list.");
        return;
    }

    struct node *temp=head;

    if(head->next==head)
    {
        head=NULL;
        free(temp);
        return;
    }

    struct node *prev=NULL;
    while(temp->next!=head)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
}

void deletionatposition(int pos)
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }

    if(pos==1)
    {
        deletionatbeginning();
        return;
    }

    struct node *temp=head, *prev=NULL;
    int i;
    for(i=1;i<pos&&temp->next!=head;i++)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Invalid Position");
        return;
    }

    prev->next=temp->next;
    free(temp);
}

void reverse()
{
    if(head==NULL || head->next==head)
        return;

    struct node* prevnode=NULL, *curr=head, *nextnode=NULL;
    struct node *temp=head;

    while(temp->next!=head)
        temp=temp->next;

    do
    {
        nextnode=curr->next;

        if(prevnode==NULL)
            curr->next=temp;
        else
            curr->next=prevnode;
        
        prevnode=curr;
        curr=nextnode;
    }
    while(curr!=head);
        head=prevnode;
}

void display()
{
    if(head==NULL)
    {
        printf("Empty list.\n");
        return;
    }

    struct node *temp=head;
    printf("Circular Linked list:");
    do
    {
        printf("%d ->", temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("(back to %d)\n", head->data);
}

int main()
{
    int choice, data, pos;

    do
    {
        printf("\n---Circular Linked List---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Beginning\n5. Delete at End\n");
        printf("6. Delete at Position\n7. Display List Forward\n8. Display List in Reverse\n9. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the data:");
                scanf("%d",&data);
                insertionatbeginning(data);
                break;

            case 2:
                printf("Enter the data:");
                scanf("%d", &data);
                insertionatend(data);
                break;

            case 3:
                printf("Enter the data:");
                scanf("%d", &data);
                printf("Enter the position:");
                scanf("%d", &pos);
                insertionatposition(data, pos);
                break;

            case 4:
                deletionatbeginning();
                break;

            case 5:
                deletionatend();
                break;

            case 6: 
                printf("Enter the position:");
                scanf("%d", &pos);
                deletionatposition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                reverse();
                printf("List reversed.");
                break;

            case 9: 
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");

        }
    }
    while(choice!=9);
    
    return 0;
}
