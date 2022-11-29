// Linked List representation of Binary Tree.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* create_node(){
    struct node* new_node;
    int x;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data : -1 for no node\n");
    scanf("%d",&x);
    if(x == -1) return 0;
    else{
        new_node->data = x;
        printf("Enter left child of %d\n",x);
        new_node->left = create_node();
        printf("Enter right child of %d\n", x);
        new_node->right = create_node(); 
    }

    return new_node;
}

void Inorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    Inorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
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

void main(){
    root = 0;
    root = create_node();
    printf("Enter your traversal choice : \n1.Preorder. \n2.Inorder. \n3.Postorder.");
    int ch ;
    scanf("%d",&ch);
    switch(ch){
        case 1: 
            Preorder(root);
            break;
        case 2: 
            Inorder(root);
            break;
        case 3: 
            Postorder(root);
            break;
        default:
            printf("Invalid choice try again.");
    }
    return;
}