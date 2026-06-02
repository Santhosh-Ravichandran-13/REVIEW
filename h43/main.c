#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node *findMin(struct node *root)
{
    while (root && root->left)
        root = root->left;

    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Value %d not found in tree\n", value);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // No child
        if (root->left == NULL && root->right == NULL)
        {
            printf("Deleting leaf node: %d\n", value);
            free(root);
            return NULL;
        }

        // One left child
        if (root->right == NULL)
        {
            printf("Deleting node %d with one child (left)\n", value);
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // One right child
        if (root->left == NULL)
        {
            printf("Deleting node %d with one child (right)\n", value);
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Two children
        printf("Deleting node %d with two children\n", value);

        struct node *temp = findMin(root->right);

        printf("Using inorder successor: %d\n", temp->data);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert value\n");
        printf("2. Delete value\n");
        printf("3. Display inorder traversal\n");
        printf("4. Exit\n");
        printf("Choose option: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);

            root = insert(root, value);

            printf("Inserted %d\n", value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);

            root = deleteNode(root, value);

            printf("Deletion attempted for %d\n", value);
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}