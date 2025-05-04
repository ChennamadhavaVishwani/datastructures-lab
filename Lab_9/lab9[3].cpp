// Program to implement a Binary Search Tree (BST) with insertion, traversal (inorder, preorder, postorder), and search operations

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node *left, *right;
    };

    Node *root;

public:
    BST() {
        root = NULL;
    }

    // Insert a new value into the BST
    void insert(int value) {
        Node *newNode = new Node(); 
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *prev = NULL;

        while (current != NULL) {
            prev = current;
            if (value < current->data) {
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                return; // Duplicate value, do not insert
            }
        }
        if (value < prev->data) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
    }

    // Recursive inorder traversal (Left -> Root -> Right)
    void inorder_tree(Node *node) {
        if (node == NULL) return;
        inorder_tree(node->left);
        printf("%d -> ", node->data);
        inorder_tree(node->right);
    }

    void inorder() {
        inorder_tree(root);
        printf("\n");
    }

    // Recursive preorder traversal (Root -> Left -> Right)
    void preorder_tree(Node *node) {
        if (node == NULL) return;
        printf("%d -> ", node->data);
        preorder_tree(node->left);
        preorder_tree(node->right);
    }

    void preorder() {
        preorder_tree(root);
        printf("\n");
    }

    // Recursive postorder traversal (Left -> Right -> Root)
    void postorder_tree(Node *node) {
        if (node == NULL) return;
        postorder_tree(node->left);
        postorder_tree(node->right);
        printf("%d -> ", node->data);
    }

    void postorder() {
        postorder_tree(root);
        printf("\n");
    }

    // Search for a value in the BST
    bool search(int target) {
        Node *temp = root;
        while (temp != NULL) {
            if (temp->data == target) {
                return true;
            }
            if (target < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return false;
    }
};

int main() {
    BST t;
    int choice, value, key;

    while (true) {
        printf("\n-------------MENU--------------\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                t.insert(value);
                break;

            case 2:
                t.inorder();
                break;

            case 3:
                t.preorder();
                break;

            case 4:
                t.postorder();
                break;

            case 5:
                printf("Enter the target value to search: ");
                scanf("%d", &key);
                if (t.search(key))
                    printf("%d found in the tree.\n", key);
                else
                    printf("%d not found in the tree.\n", key);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;  

            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
