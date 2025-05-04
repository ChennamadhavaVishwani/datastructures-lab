// A cpp menu driven program to implement hashtable using chain probing
#include<cstdio>
#include<cstdlib>

class Hashtable{
    private:
    struct Node{
        int data;
        Node *next;
    }; 
     Node* arr[10];

     int hash(int key) {
        return key % 10;
    }

    public:
    Hashtable(){
        for (int i = 0; i < 10; i++) {
            arr[i] = NULL;
        }
    }

    void insert(int num){
        int index = hash(num);
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = arr[index];
        arr[index] = newNode;
    }

    void remove(int key){
        int index = hash(key);
        Node* temp = arr[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->data == key) {
                if (prev == NULL) {
                    arr[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("Element not found!\n");
    }

   int search(int target){
        int index = hash(target);
        Node* temp = arr[index];
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == target) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }

        return -1;
    }

    void display(){
         printf("Hashtable contents:\n");
        for (int i = 0; i < 10; i++) {
            printf("Index %d: ", i);
            Node* temp = arr[i];
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }

    }
};
int main(){
    Hashtable h;
    int choice;
    int value;
    int key; 
    int result;
      while(true){
        printf("-------------MENU--------------\n");
        printf("1. Insert. \n");
        printf("2. Delete. \n");
        printf("3. Search.\n");   
        printf("4. Display.\n");
        printf("5. Exit.  \n");                                         

        printf("enter your choice: ");
        scanf("%d" , &choice);
    
    switch(choice){
        case 1:
            printf("Enter the value to be inserted into the table: ");
            scanf("%d", &value);
            h.insert(value);
            h.display();
            break;

        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &key);
            h.remove(key);
            h.display();
            break;

        case 3:
            printf("Enter the element to serach for: ");
            scanf("%d", &key);
            result = h.search(key);
            printf("the element %d is at the position %d", key, result);
            h.display();
            break;

        case 4:
            h.display();
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



    