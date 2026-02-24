//Tree Traversal and Search
//@uthor: Aadi Kulshreshth
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Inorder(struct node* root) 
{
    if (root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder(struct node* root) 
{
    if (root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct node* root) 
{
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void inOrder_iterative(struct node *root) 
{
    struct node *stack[20];
    int top = -1;
    struct node *current = root;

    while (current != NULL || top != -1) 
    {
        while (current != NULL) 
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preOrder_iterative(struct node *root) 
{
    if (root == NULL) return;

    struct node *stack[20];
    int top = -1;
    stack[++top] = root;

    while (top != -1) 
    {
        struct node *current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) 
            stack[++top] = current->right;
        
        if (current->left != NULL) 
            stack[++top] = current->left;
        
    }
}

void postOrder_iterative(struct node *root) 
{
    if (root == NULL) return;

    struct node *stack1[20], *stack2[20];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) 
    {
        struct node *current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) 
            stack1[++top1] = current->left;
        
        if (current->right != NULL) 
            stack1[++top1] = current->right;
        
    }

    while (top2 != -1) 
        printf("%d ", stack2[top2--]->data);
    
}

void searchElement(struct node *root, int key, int *found) 
{
    if (root == NULL || *found == 1) 
        return;
    
    if (root->data == key) 
    {
        *found = 1;
        return;
    }
    searchElement(root->left, key, found);
    searchElement(root->right, key, found);
}

int main() 
{
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal: ");
    Inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    Preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    Postorder(root);
    printf("\n");

    printf("Inorder (iterative) traversal: ");
    inOrder_iterative(root);
    printf("\n");

    printf("Preorder (iterative) traversal: ");
    preOrder_iterative(root);
    printf("\n");

    printf("Postorder (iterative) traversal: ");
    postOrder_iterative(root);
    printf("\n");

    int key, found = 0;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    searchElement(root, key, &found);
    if (found) 
        printf("Element %d is present in the tree.\n", key);
    else 
        printf("Element %d is not present in the tree.\n", key);

    return 0;
}
 