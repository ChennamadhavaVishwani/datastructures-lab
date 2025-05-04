// A C++ menu-driven program to implement singly linked list!!!
#include<cstdio>
#include<cstdlib>

class SLL{
    private:
    struct Node{
    int data;
    Node*link;
    };
    Node*head;

    public:
        SLL(){
        head = NULL;
    }

    void insertatbeg(int num){
        struct Node*newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        newNode -> link = head;
        head = newNode;     

    }
    void insertatend(int num){
        struct Node*newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        newNode -> link = NULL;

        if(head == NULL){
            head = newNode;
            return;
        }

        Node*temp = head;
        while(temp -> link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;

    }
    void insertatpos(int num, int pos){
        if(pos<=1){
            insertatbeg(num);
            return;
        }
        struct Node* newNode = (struct Node*) malloc(sizeof(Node));
        newNode->data = num;
        newNode->link = NULL;
        
        Node*temp = head;
        int currpos = 1;

        while (currpos < pos - 1 && temp != NULL) {
        temp = temp->link;
        currpos++;
    }
    

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->link = temp->link;
    temp->link = newNode;

    }

    void deleteatbeg(){
        if (head == NULL){
            printf("The list is empty");
            return;
        }
        Node*temp = head;
        head = head->link;
        free(temp);
    }

    void deleteatend(){
        Node*temp = head;
        if(head == NULL){
            printf("List is empty");
            return;
        }
        else if(head->link == NULL){
            free(head);
            head = NULL;
            return;
        }
        
        while(temp->link->link!= NULL){
            temp = temp -> link;
        }
        free(temp->link);
        temp -> link = NULL;
    }

    void deleteatpos(int pos){
        if (head == NULL) {
            printf("Empty List!!\n");
            return;
        }
        Node* temp = head;
        if (pos == 1) {
            deleteatbeg();
        }
        Node* prev = NULL;
        for (int i = 1; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL) {
            printf("Invalid position!!\n");
            return;
        }

        prev->link = temp->link;  
        free(temp);
    }
    
    int search(int num){
        Node *temp = head;
        int pos = 1;
        while(temp!= NULL){
           if( temp ->data == num){
            return pos;
            }
        
        temp = temp -> link;
        pos++;}
        return -1;

    }
    void display(){
        Node*temp = head;
        while(temp != NULL){

            printf("%d ->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
    
    void helper(Node* temp) {
        if (temp == NULL) return;  
            helper(temp->link);  
            printf("%d -> ", temp->data);  
        }

    void displayrev() {
        if (head == NULL) {
            printf("List is empty\n");
            return;
        }
        helper(head);
        printf("NULL\n");
    }

    void reverselink(){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->link; 
        current->link = prev; 
        prev = current;       
        current = next;      
    }
    head = prev; 
    }        
    
};

int main(){
    SLL list;
    int num;
    int pos;
    int target;
    int choice;
    int result;

    while(true){
        printf("-------------MENU----------\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at any position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display Reverse\n");
        printf("10. Reverse Link\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
    

    switch(choice){
        case 1:
        printf("Enter the value to be inserted : ");
        scanf("%d", &num);
        list.insertatbeg(num);
        list.display();
        break;

        case 2:
        printf("Enter the value to be inserted: ");
        scanf("%d", &num);
        list.insertatend(num);
        list.display();
        break;

        case 3:
        printf("Enter the value to be inserted: ");
        scanf("%d", &num);
        printf("Enter the position to be inserted at: ");
        scanf("%d", &pos);
        list.insertatpos(num, pos);
        list.display();
        break;

        case 4:
        list.deleteatbeg();
        list.display();
        break;

        case 5: 
        list.deleteatend();
        list.display();
        break;

        case 6:
        printf("Enter the position to be deleted at: ");
        scanf("%d", &pos);
        list.deleteatpos(pos);
        list.display();
        break;

        case 7:
        printf("Enter the target to be searched for: ");
        scanf("%d", &target);
        result = list.search(target);
        printf("The target is found at the target %d: ", result);
        
        break;

        case 8:
        list.display();
        break;

        case 9:
        list.displayrev();
        break;

        case 10:
        list.reverselink();
        list.display();
        break;
         
        default:
        printf("Invalid Choice Entered!!!!!!\n");
        printf("Exiting.......\n");
    }}
    return 0;
}