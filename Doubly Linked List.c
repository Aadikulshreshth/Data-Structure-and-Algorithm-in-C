//@uthor: Aadi Kulshreshth
//Doubly Linked list
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("Inserted %d at beginning.\n", data);
}

void insertAtEnd(struct Node **head, int data) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        newNode->prev = NULL;
        *head = newNode;
        printf("Inserted %d at end.\n", data);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", data);
}

void insertAtPosition(struct Node **head, int data, int pos) 
{
    if (pos == 1) 
    {
        insertAtBeginning(head, data);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos-1; i++)
        temp = temp->next;
    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}

void deleteAtBeginning(struct Node **head) 
{
    if (*head == NULL) 
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
    printf("Node deleted from beginning.\n");
}

void deleteAtEnd(struct Node **head) 
{
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == NULL) 
    {  
        *head = NULL;
        free(temp);
        printf("Last node deleted.\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("Node deleted from end.\n");
}

void deleteAtPosition(struct Node **head, int pos) 
{
    if (*head == NULL) 
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;  
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted at position %d.\n", pos);
}

void display(struct Node *head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse(struct Node *head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List in reverse: ");
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void concatenate(struct Node **head1, struct Node *head2) 
{
    if (*head1 == NULL) 
    {
        *head1 = head2;
        return;
    }
    if (head2 == NULL) return;
    struct Node *temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2->prev = temp;
    printf("Lists concatenated successfully.\n");
}

int main() 
{
    struct Node *head = NULL;
    int choice, data, pos;
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        print("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete at Beginning\n5. Delete at End\n
        6. Delete at Position\n7. Display List Forward\n8. Display List in Reverse\n9. Concatenate with another list\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                break;

            case 4:
                deleteAtBeginning(&head);
                break;

            case 5:
                deleteAtEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;

            case 7:
                display(head);
                break;

            case 8:
                displayReverse(head);
                break;

            case 9: 
                struct Node *head2 = NULL;
                int n;
                printf("Enter number of nodes in second list: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) 
                {
                    printf("Enter data for node %d: ", i+1);
                    scanf("%d", &data);
                    insertAtEnd(&head2, data);
                }
                concatenate(&head, head2);
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } 
    while (choice != 10);

    return 0;
}