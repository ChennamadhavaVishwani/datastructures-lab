//A c++ menu driven rogram to implement stack ADT using singly linked list 
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

    void push(int num){
       
        struct Node *newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        newNode -> link = head;
        head = newNode;         
    }

    void pop(){
        if(head == NULL){
            printf("The stack is empty");
            return;
        }
        Node*temp = head;
        head = head -> link;
        free(temp);
        return;
    
    }

    int peek(){
        if(head == nullptr){
            printf("The stack is empty");
            return  -1;
        }
        
        Node *temp = head;
        
        return temp -> data;

    }

    void display(){
        if(head == NULL){
            printf("The stack is empty");
        }

        Node*temp = head;
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp->link;
    }

    
    }
};

int main(){
    SLL stack;
    int num, choice, target, result;
    while(true){
        printf("--------------MENU-------------\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

    
    switch(choice){
        case 1:
        printf("Enter the value to be pushed into the stack: ");
        scanf("%d", &num);
        stack.push(num);
        stack.display();
        break;

        case 2:
        stack.pop();
        stack.display();
        break;

        case 3:
        result = stack.peek();
        printf("The element on the top of the stack is %d ", result);
        stack.display();
        break;

        case 4:
        printf("Exiting....");

        default:
        printf("Inavlid choice!!!");
        printf("Exiting...");
    }
        
    }


return 0;}












