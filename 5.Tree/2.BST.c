// Linked List representation of Binary Search Tree.


//        10
//      /   \         
//     9    30
//   /  \  
//  3   14

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node *create_node()
{
    struct node *new_node;
    int x;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : -1 for no node\n");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    else
    {
        new_node->data = x;
        printf("Enter left child of %d\n", x);
        new_node->left = create_node();
        printf("Enter right child of %d\n", x);
        new_node->right = create_node();
    }

    return new_node;
}
// Traversing.
void Inorder(struct node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

void Preorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    printf("%d ", node->data);
 
    /* then recur on left subtree */
    Preorder(node->left);
 
    /* now recur on right subtree */
    Preorder(node->right);
}

void Postorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    Postorder(node->left);
 
    // then recur on right subtree
    Postorder(node->right);
 
    // now deal with the node
    printf("%d ", node->data);
}

// Searching.
struct node *searchNode(struct node *temp, int value)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }
    else
    {
        if (temp->data == value){
            return temp;
        }
        if (temp->left != NULL)
            searchNode(temp->left, value);
        if (temp->right != NULL)
            searchNode(temp->right, value);
    }
    return temp;
}

// Insertion at the end of leaf node.

void insertion(int element)
{
    struct node *pos = searchNode(root, element);
    if (pos == NULL)
    {
        printf("Element not found!");
        return;
    }
    struct node *newnode;
    int pref;
    if (pos->left == 0 && pos->right == 0)
    {
        printf("Enter your preference : \n1.Left child. \n2.Right child.\n");
        scanf("%d", &pref);

        if (pref == 1)
        {
            newnode = create_node();
            pos->left = newnode;
            Inorder(root);
            return;
        }
        else
        {
            newnode = create_node();
            pos->right = newnode;
            Inorder(root);
            return;
        }
    }
    else if (pos->left != 0)
    {
        newnode = create_node();
        pos->right = newnode;
        Inorder(root);
        return;
    }
    else if (pos->right != 0)
    {
        newnode = create_node();
        pos->left = newnode;
        Inorder(root);
        return;
    }
    else
        printf("Insertion not possible");
}

// Inorder predecessor...
struct node *inorderPredecessor(struct node* root1){
    root1 = root1->left;
    while(root1->right != NULL)
    root1 = root1->right;
    return root1;
}
// Deletion of leaf node.

struct node *deleteNode(struct node* root, int value){
    struct node* iPre;
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
         free(root);
         return NULL;
    }
    if(value < root->data) root->left = deleteNode(root->left,value);
    else if(value > root->data) root->right = deleteNode(root->right,value);
    else {
        iPre = inorderPredecessor(root); 
        root->data =iPre->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
}

void main()
{
    root = 0;
    root = create_node();
    int x, element,ch;
    char c;

    printf("Enter your choice : \n 1.Traversing. 2. Insertion. 3. Deletion. 4. Searching.\n");
    scanf("%d",&ch);
    
    switch (ch)
    {
    case 1:
        printf("Enter your choice : \n a. Preorder. b. Postorder. c. Inorder.\n");
        scanf("%c",&c);
        if(c == 'a') Preorder(root);
        else if(c == 'b') Postorder(root);
        else if(c == 'c') Inorder(root);
        else printf("Invalid choice");
        break;
    case 2: 
        printf("Enter the leaf node data after which insertion is to be done : \n");
        scanf("%d", &element);
        printf("Tree after Insertion of a Node : \n");
        insertion(element);
        break;
    case 3: 
        printf("Enter the node to be deleted : \n");
        scanf("%d", &element);
        printf("Tree after Deletetion of a Node : \n");
        deleteNode(root,element);
        Inorder(root);
        break; 
    case 4:
        printf("Enter the element to be searched : \n");
        scanf("%d", &element);
        searchNode(root,element);    
    default:
        break;
    }
}
