// A cpp menu driven program to implement doubly linked list with a tail pointer
#include<cstdio>
#include<cstdlib>

class DLL{
    private:
    struct Node{
    int data;
    Node*next;
    Node*prev;
    };
    Node*head;
    Node*tail;
    
     public:
        DLL(){
        head = NULL;
        tail = NULL;
    }

    void insertatbeg(int num){
        
        struct Node*newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        newNode -> prev = NULL;
        newNode -> next = head;

        if(head!= NULL){
            head->prev = newNode;

        }
        else{tail = newNode;
        }
        head = newNode;
    }

    void insertatend(int num){
        if(head == NULL){
            insertatbeg(num);
            return;
        }
        
        struct Node*newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        newNode -> prev = tail;
        newNode -> next = NULL;
        if(tail != NULL){
            tail -> next = newNode;
        }
        else{head = newNode;}
        tail = newNode;

    }
    
    void insertatpos(int pos, int num){
        if(head == NULL){
            printf("The list is empty");
            return;
        }
        if(pos == 1){
            insertatbeg(num);
        }
        struct Node*newNode = (struct Node*) malloc (sizeof(Node));
        newNode -> data = num;
        struct Node*temp = head;
        for(int i = 1; temp != NULL && i <pos-1; i++){
            temp = temp -> next;

        } 
        if(temp == NULL){
            printf("Out of Bounds! ");
            free(newNode);
        }
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        if(temp -> next != NULL){
            temp -> next -> prev = newNode;
        }
        else{
            tail = newNode;
        }
        temp -> next = newNode;
       
    }

    void deleteatbeg(){
        if(head == NULL){
            printf("The list is empty/n");
            return;
        }
        struct Node*temp = head;
        head = head -> next;
        if(head != NULL){
            head->prev = NULL;
        }
        else{
           tail = NULL;
        }
        free(temp);}

    void deleteatend(){
        if(tail == NULL){
            printf("The list empty");
            return;
        }
        struct Node*temp = tail;
        tail = tail-> prev;

        if(tail!= NULL){
        tail-> next = NULL;}
        
        else{
            head = NULL;
        }
        free(temp);
    }

    int search(int target){
        Node *temp = head;
        int pos = 1;
        while(temp-> next != NULL){
           if( temp ->data == target){
            printf("%d", pos);
            return 0;}
        }
        temp = temp -> next;
        pos++;
        return pos;
    }
    
    void deleteatpos(int pos){
        if(head == NULL){
            printf("THe list is empty");
            return;
        }
        if(pos == 1){
            deleteatbeg();
            return;
        }
        
        struct Node*temp = head; 
        for(int i = 1; temp != NULL && i <pos-1; i++){
            temp = temp -> next;

        } 
        if(temp == NULL){
            printf("Out of Bounds! ");
            return;

        if(temp -> next != NULL){
            temp -> next -> prev = temp -> prev;

        }   
        else(tail = temp -> prev);
        if(temp -> prev != NULL){
            temp -> prev -> next = temp -> next;
        } 
        free(temp);
            
    }}

    void display(){ 
        if(head == NULL){
            printf("The list is empty");
        }

        Node*temp = head;
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp->next;
    }
    
    printf("NULL/n");

    }
};
int main(){
DLL list;
int result, choice, pos, target, num;

while(true){
    
        printf("----------------MENU---------------\n\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at any position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit!");

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
        printf("Enter the value to be inserted at end: ");
        scanf("%d", &num);
        list.insertatend(num);
        list.display();
        break;

        case 3:
        printf("Enter the value to be inserted: ");
        scanf("%d", &num);
        printf("Enter the position to be inserted at: ");
        scanf("%d", &pos);
        list.insertatpos(pos,num);
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
        printf("The target is found at the target %d: \n", result);
        
        break;

        case 8:
        list.display();
        break;
         
        case 9:
        printf("Exiting!!");
        
        default:
        printf("Invalid Choice Entered!!!!!!");
        printf("Exiting.......");
    }
    
}      


return 0;
}
