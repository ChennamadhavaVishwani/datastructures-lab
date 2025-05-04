// A cpp menu driven program to implement hashtable using linear probing
#include<cstdio>
#include<cstdlib>

class hashtable{
    private:
    int table[10];
    int size;

    int hashfunction(int key){
        return key %size;
    }
    public:
    hashtable(){
        size = 10;
        for(int i = 0; i<size; i++){
            table[i] = -1;
        }
    }

    void insert(int key){
        int index = hashfunction(key);
        int start = index;

        while(table[index]!= -1){
            index = (index + 1)%size;
            if (index == start)break;
        }
    table[index] = key;
        
    }

    void remove(int key){
        int index = hashfunction(key);
        int start = index;

        while(table[index]!= -1){
            if(table[index] == key){
                table[index] = -1;
            }
            index = (index + 1)%size;
            if (index == start) break;
            }
    }

    void search(int key){
        int index = hashfunction(key);
        int start = index;

        while(table[index]!= -1){
            if(table[index] == key){
                printf("The key %d is found at index %d", key, index);
                return;
                }
        index = (index + 1)%size;
        if(index == start)   break; }

    printf("the key not found!");         
    }
    
    void display(){
        printf("The hashtable is: ");
        for(int i = 0; i<size; i++){
            
            printf("%d ", table[i]);
            
            
        }
    }};

    int main(){
    hashtable h;
    int choice;
    int value;
    int key;
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
            h.search(key);
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

