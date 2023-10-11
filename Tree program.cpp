#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} ;

struct Node* createNode(int data) {
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
struct Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp =findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice,key;;
    printf("Enter 1 to insert node");
    printf("\nEnter 2 for inorder traversal");
    printf("\nEnter 3 for preorder traversal");
    printf("\nEnter 4 for postorder traversal");
    printf("\nEnter 5 to delete node");
    printf("\nEnter 6 to search node");
    printf("\nEnter 7 to exit");
    
    do{
		printf("\nEnter your choice: ");
	    scanf("%d",&choice);
	switch(choice)
    {
    	case 1:
    		int data;
    		printf("Enter value of node: ");
    		scanf("%d",&data);
    		root=insert(root,data);
    		break;
    	case 2:
    		printf("Inorder traversal: ");
		    inorderTraversal(root);
		    printf("\n");
		    break;
		case 3:
			printf("Preorder traversal: ");
		    preorderTraversal(root);
		    printf("\n");
		    break;
		case 4:
			printf("Postorder traversal: ");
		    postorderTraversal(root);
		    printf("\n");
		    break;
		case 5:
			
			printf("\nEnter node to be deleted: ");
			scanf("%d",&key);
			root = deleteNode(root, key);
			printf("\nInorder traversal after deletion: ");
			inorderTraversal(root);
			printf("\n");
			break;
		case 6:
			{
			printf("\nEnter node to be searched: ");
			scanf("%d",&key);
		    struct Node* foundNode = search(root, key);
		    if (foundNode != NULL)
		        printf("Node with key %d found.\n", key);
		    else
		        printf("Node with key %d not found.\n", key);
			break;
	}
		default:
			printf("Enter valid choice!!");		
			break;	
	}
	}while(choice!=6);
    return 0;
}
