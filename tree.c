#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* buildTree(Node* root) {
    // Base case: if data is -1, don't create a node and return NULL
    printf("Enter the data: ");
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    // Create a new node for the current value
    root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    // Recursively build the left and right subtrees
    printf("Enter data for inserting in left of %d: ", data);
    root->left = buildTree(root->left);
    
    printf("Enter data for inserting in right of %d: ", data);
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root) {
    if (root == NULL) return;

    // Create a queue using an array of Node pointers
    Node** q = (Node**)malloc(100 * sizeof(Node*)); // Arbitrarily large size for demonstration
    int front = 0, rear = 0;

    // Push the root to the queue
    q[rear++] = root;
    q[rear++] = NULL;  // Marker for end of level

    while (front < rear) {
        Node *temp = q[front++];
        
        if (temp == NULL) {  // If marker is encountered
            printf("\n");  // Print a new line for the new level
            if (front < rear) {
                q[rear++] = NULL;  // Insert marker for the next level
            }
        } else {
            printf("%d ", temp->data);  // Print node's data

            // Enqueue left and right children
            if (temp->left) {
                q[rear++] = temp->left;
            }
            if (temp->right) {
                q[rear++] = temp->right;
            }
        }
    }
    free(q);  // Free the dynamically allocated memory for the queue
}

// Depth-First Search Traversals (Inorder, Preorder, Postorder)

// Inorder Traversal: Left, Node, Right
void inorder(Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal: Node, Left, Right
void preorder(Node *root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal: Left, Right, Node
void postorder(Node *root) {
    if (root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node *root = NULL;
    root = buildTree(root);

    printf("Level Order Traversal:\n");
    levelOrderTraversal(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
