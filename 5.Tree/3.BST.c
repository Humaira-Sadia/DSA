// Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

//Inorder Traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->data);
		inorder(root->right);
	}
}

//Insertion of new node in BST
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
	if (root == NULL || root->data == key)
	return root;
		if (root->data < key)
	return search(root->right, key);
	return search(root->left, key);
}
int main()
{
	/* BST 
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
    
	// print inoder traversal of the BST
    int val = 40 ;
    struct node* key = search(root,val);
	inorder(root);
    if(key == NULL)
    printf("Element-%d not found!!" , val);
    else
    printf("Element-%d is present" , val);
	return 0;
}
