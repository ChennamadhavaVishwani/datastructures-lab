// A cpp menu driven program to implement circularly linked list
#include<cstdio>
#include<cstdlib>
class List{
    private:
    struct Node{
    int data;
    Node* next;
    
    };
    struct Node *head;
    
    public:
    List(){
        head = NULL;
    }

    void insertatbeg(int num){
        struct Node* newNode = (struct Node*)malloc(sizeof(Node));
        newNode->data = num;
        if(head == NULL){
            newNode->next = newNode;
            head = newNode;
    }
    else{
        Node*temp = head;
        while(temp-> next!= head ){
            temp = temp ->next;}
            
            newNode->next = head;
            temp -> next = newNode;
            head = newNode ;

    }
    }

    void insertatend(int num){
        struct Node* newNode = (struct Node*)malloc(sizeof(Node));
        newNode->data = num;
        if(head == NULL){
            newNode -> next = newNode;
            head = newNode;}
        else{
            Node*temp = head;
            while(temp ->next != head){
                temp = temp->next;
                }

                temp ->next = newNode;
                newNode -> next = head; 
        }    
    }
    void insertatpos(int num, int pos){
        if(pos == 1){
            insertatbeg(num);
            return;
        }
        struct Node* newNode = (struct Node*)malloc(sizeof(Node));
        newNode->data = num;
        int curpos = 1;
        Node*temp = head;

        while(curpos<pos && temp->next != head){
            temp = temp ->next;
            curpos++;                   
        }
        if (temp->next == head && curpos < pos - 1) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
        }
        newNode-> next = temp-> next;
        temp -> next = newNode;
        
    }
    
    
    void deleteatbeg(){
        if (head == NULL){
            printf("The list is empty\n");
            return;
        }
        if(head->next == head){
        free(head);
        head = NULL;
        return;}

        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;}

            Node* deletea = head;
            head = head ->next;
            temp ->next = head;
            free(deletea);
        
    }

    void deleteatend(){
        if (head == NULL){
            printf("the list is empty");
            return;
        }
        if(head->next == head){
            free(head);
            head = NULL;
            return;
           
        }
        Node*temp = head;
        while(temp ->next -> next != head){
            temp = temp->next;
            }
           free(temp -> next);
           temp -> next = head;
    }

    void deleteatpos(int pos){
        if(pos == 1){
            deleteatbeg();
            return;
        }
        Node*temp = head;
        Node*prev = head;

        for(int i =0; temp->next!= head && pos>1; i++ ){
            prev = temp; 
            temp = temp->next;
        }
        if (temp -> next == head) {
            printf("Invalid position!!\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }

    int search(int target){
        if(head == NULL){
            printf("the list is empty");
            
        }
        else{
            Node* temp = head;
            int pos = 1;
            while(temp -> next != head){
                if(temp -> data == target){
                    return pos;
                }
                temp = temp ->next;
                pos++;
            }
        }
        return -1;
    }
    void display(){
        if(head == NULL){
            printf("The list is empty");
        }
        else{
            Node* temp = head;
            while(temp -> next  != head){
                printf("%d ->", temp->data);
                temp = temp ->next;}

            printf("%d -> Head\n", temp->data);
        
        }
   
    }
};


int main(){
    List cll1;
    int num, choice, k, result, target;
    while(choice != 9){
        printf("------------MENU-------------\n");
        printf("1. Insertion at the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion at any position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at any position\n");
        printf("7. Display the elements\n");
        printf("8. search\n");
        printf("9. Exit!!!\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter the number to be inserted:");
            scanf("%d", &num);
            cll1.insertatbeg(num);
            cll1.display();
            break;

            case 2:
            printf("Enter the number to be inserted at the end: ");
            scanf("%d", &num);
            cll1.insertatend(num);
            cll1.display();
            break;

            case 3:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position: ");
            scanf("%d", &k);
            cll1.insertatpos(num, k);
            cll1.display();
            break;

            case 4:
            cll1.deleteatbeg();
            cll1.display();
            break;

 
            case 5:
            cll1.deleteatend();
            cll1.display();
            break;

            case 6:
            printf("Enter the position: ");
            scanf("%d", &k);
            cll1.deleteatpos(k);
            cll1.display();
            break;

            case 7:
            cll1.display();
            break;

            case 8:
            printf("Enter the number to search for: ");
            scanf("%d", &target);
            result = cll1.search(target);
            printf("The tarfet is found at %d\n", result);
            
            break;

            case 9:
            printf("Exiting");
            break;

            default:
            printf("Invalid choice!!!");
            printf("Exiting...."); 
        }
     
    }
    return 0;  }

 
