#include <cstdio>
#include <cstdlib>

class Tree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;

public:
    Tree() { 
        root = nullptr; 
    }

    // Insert node in a basic left-right alternating manner (not a BST)
    void insert(int value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* temp = root;
        while (true) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            } else if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            } else {
                temp = temp->left;  //always go left if both children are filled
            }
        }
    }

    // Recursive inorder traversal (left-root-right)
    void inorder_traversal(Node* node) {
        if (node == nullptr) return;
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }

    void inorder() {
        inorder_traversal(root);
    }

    // Recursive preorder traversal (root-left-right)
    void preorder_traversal(Node* node) {
        if (node == nullptr) return;
        printf("%d ", node->data);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void preorder() {
        preorder_traversal(root);
        printf("\n");
    }

    // Recursive postorder traversal (left-right-root)
    void postorder_traversal(Node* node) {
        if (node == nullptr) return;
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printf("%d ", node->data);
    }

    void postorder() {
        postorder_traversal(root);
    }

    // traverses down left children first, then right
    bool search(int key) {
        Node* temp = root;
        while (temp) {
            if (temp->data == key)
                return true;
            if (temp->left)
                temp = temp->left;
            else if (temp->right)
                temp = temp->right;
            else
                break;
        }
        return false;
    }
};

int main() {
    Tree T;
    int choice, value;

    while (true) {
        printf("\n------- MENU -------\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &value);
                T.insert(value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                T.preorder();
                break;
            case 3:
                printf("Inorder Traversal: ");
                T.inorder();
                break;
            case 4:
                printf("Postorder Traversal: ");
                T.postorder();
                break;
            case 5:
                printf("Enter integer to search: ");
                scanf("%d", &value);
                if (T.search(value))
                    printf("%d found in the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
