// A cpp menu driven program to implement queue using singly linked list
#include<cstdio>
#include<cstdlib>

class SLL{
    private:
    struct Node{
    int data;
    
    Node*link;
    }*front, *rear;
    

    public:
        SLL(){
        front = rear = NULL;
    }

    bool isempty(){
        return (front == NULL);
    }
    
    void enqueue(int num){
        struct Node*newnode = (struct Node*) malloc (sizeof(Node));
        newnode -> data = num;
        newnode->link = NULL;
        if(rear != NULL){
            rear-> link = newnode;

        }
        rear = newnode;
        if(front == NULL){
            front = newnode;
        }
    }

    int dequeue(){
        if(front == NULL){
            printf("The queue is empty!!");
            return -1;
        }

        int deletedval = front->data;
        Node*temp = front;
        front = front->link;
        free(temp);
        return deletedval;
    }

    int peek(){
        return front -> data;
    }

    void display(){
        if(front == NULL){
            printf("The stack is empty");
        }

        Node*temp = front;
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp->link;
    }
    }
    };

    int main(){
    SLL q;
    int choice;
    int value;
    int top;
    int result;
      while(true){
        printf("-------------MENU--------------\n");
        printf("1. Enqueue. \n");
        printf("2. Dequeue. \n");
        printf("3. Peek.\n");   
        printf("4. Display.\n");
        printf("5. Exit.  \n");                                         

        printf("enter your choice: ");
        scanf("%d" , &choice);
    
    switch(choice){
        case 1:
            printf("Enter the value to be inserted into the queue: ");
            scanf("%d", &value);
            q.enqueue(value);
            q.display();
            break;

        case 2:
            result=q.dequeue();
            printf("The deleted element is :%d\n ", result);
            q.display();
            break;

        case 3:
           top = q.peek();
           printf("The element on the top is: %d\n", top);
           q.display();
           break;

        case 4:
            q.display();
            break;

        case 5:
            printf("Exiting!!");
            break;    

        default:
            printf("Invalid Choice!!!");
            printf("Exiting......");
            
    }}

    return 0;

}

    