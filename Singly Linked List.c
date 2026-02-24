//Singly Linked List
//@uthor: Aadi Kulshreshth
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int main()
{
    int choice, v, posi, i;
    struct node*head=NULL, *newnode, *temp, *prev;
    struct  node*head2=NULL; 
    
    do
    {
        printf("\nSelect the operation from the menu:\n");
        printf("1. Insertion at the begining.\n2. Insertion at the end.\n3. Insert at a random position.\n4. Delete at the begining.\n");
        printf("5. Delete at the end.\n6. Delete at a random position.\n7.Reversing the list.\n8.Concatenating the list.\n9.Display the list.\n10.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the value:");
                scanf("%d", &v);
                newnode->data=v;
                newnode->next=head;
                head=newnode;
                printf("Inserted at the begining.\n");
                break;
            
            
            case 2:
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the value:");
                scanf("%d", &v);
                newnode->data=v;
                newnode->next=NULL;
                if(head==NULL)
                    head=newnode;
                else
                {
                    temp=head;
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=newnode;
                }
                printf("Inserted at the end.\n");
                break;

            
                case 3:
                    printf("Enter the position u want to insert:");
                    scanf("%d", &posi);
                    newnode=(struct node*)malloc(sizeof(struct node));
                    printf("Enter the value:");
                    scanf("%d", &v);
                    newnode->data=v;
                    temp=head;
                    for(i=1; i<posi-1 && temp!= NULL; i++)
                        temp=temp->next;

                    if(temp==NULL)
                    {
                        printf("Position out of range.\n");
                        free(newnode);
                        break;
                    }
                    newnode->next=temp->next;
                    temp->next=newnode;
                    printf("Inserted at the position %d\n", posi);
                    break;

                case 4:
                    if(head==NULL)
                        printf("Empty list, nothing to delete.\n");
                    else
                    {
                        temp=head;
                        head=head->next;
                        free(temp);
                        printf("Deleted at the begining.\n");
                    }
                    break;

                case 5:
                    if(head==NULL)
                        printf("Empty list, nothing to delete.\n");
                    else if(head->next==NULL)
                    {
                        free(head);
                        head=NULL;
                        printf("Deleted at end.\n");
                    }
                    else
                    {
                        temp=head;
                        while(temp->next->next!=NULL)
                            temp=temp->next;
                        free(temp->next->next);
                        temp->next=NULL;
                        printf("Deletion at end successful.\n");
                    }
                    break;
                
                case 6: 
                    printf("Enter the position:");
                    scanf("%d", &posi);
                    if(head==NULL)
                        printf("List is emppty.\n");
                    else 
                    {
                        temp=head;
                        for(i=1;i<posi && temp != NULL; i++)
                        {
                            prev=temp;
                            temp=temp->next;
                        }
                        if(temp==NULL)
                            printf("Invalid position.");
                        else
                        {
                            prev->next=temp->next;
                            free(temp);
                            printf("Deleted node at position %d\n", posi);
                        }
                    }
                    break;
                
                case 7:
                    if(head==NULL)
                        printf("List is empty.\n");
                    else
                    {
                        struct node* prevnode=NULL, *curr=head, *nextnode=NULL;
                        while(curr!=NULL)
                        {
                            nextnode=curr->next;
                            curr->next=prevnode;
                            prevnode=curr;
                            curr=newnode;
                        }
                        head=prevnode;
                        printf("The list is reversed successfully.\n");
                    }

                case 8:
                    printf("Creating second list for concatenation...\n");
                    head2 = NULL;
                    int n;
                    printf("Enter number of nodes for second list: ");
                    scanf("%d", &n);
                    for (i = 0; i < n; i++) 
                    {
                        newnode = (struct node*)malloc(sizeof(struct node));
                        printf("Enter value for node %d: ", i + 1);
                        scanf("%d", &v);
                        newnode->data = v;
                        newnode->next = NULL;
                        if (head2 == NULL)
                            head2 = newnode;
                        else 
                        {
                            temp = head2;
                            while (temp->next != NULL)
                                temp = temp->next;
                            temp->next = newnode;
                        }
                    }
                    if (head == NULL)
                        head = head2;
                    else 
                    {
                        temp = head;
                        while (temp->next != NULL)
                            temp = temp->next;
                        temp->next = head2;
                    }
                    printf("Lists concatenated successfully.\n");
                    break;

                case 9:
                    if(head==NULL)
                        printf("List is empty.\n");

                    else
                    {
                        printf("Linked list:");
                        temp=head;
                        while(temp != NULL)
                        {
                            printf(" %d", temp->data);
                            temp=temp->next;
                        }
                        printf("\n");
                    }
                    break;


                case 10:
                    printf("Exiting the program.\n");
                    break;

                default:
                    printf("Invalid choice.\n");
            }

    }
    while (choice!=8);

    return 0;
}