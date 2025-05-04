// A c++ program of ListADT - Array Implementation
#include<cstdio>
class List{

    private:
    int arr[5];
    int size;
    int current;
    int start;

    public:
    List(){
    size = 5;
    current = 0;
    start = 0;}

    int insertatbeg(int value){
    if (current >= size) {
        printf("List is full\n");
        return 0; 
        }    
    for(int i = current - 1; i>=0; i--){
        arr[i+1]= arr[i];
    }
    arr[0] = value;
    current++;
    return 1;
    }

    int insertatend(int value){
    if (current>=size) return 0;
    arr[current] = value;
    current++;
    return 1;
    }
   
    int insertatpos(int value,int pos){
        if (current >= size || pos <= 0 || pos > current + 1) {
            printf("Invalid position or list is full\n");
            return 0; 
        }
        for(int i = current-1; i>=pos; i--){
            arr[i+1] = arr[i];}

            arr[pos-1] = value;
       
        current++;
       
    return 1;
    }

    int deleteatbeg(){
        if (current == 0) {
            printf("List is empty\n");
            return -1;
        }
        int deletedvalue = arr[0];
        for(int i = 0; i<current-1; i++){
            arr[i]= arr[i+1];
        }
        current--;
        return deletedvalue;
    }

    int deleteatend(){
        if (current == 0) return 0;
        int deletedValue = arr[current - 1]; 
        current--;
        return deletedValue;
    }
    

    int deleteatpos(int pos){
        if (current == 0 || pos <= 0 || pos > current) {
            printf("Invalid position\n");
            return -1; 
        }
        int deletedvalue = arr[pos - 1];
        for (int i = pos-1; i < current - 1; i++) {
        arr[i] = arr[i + 1];
    }
    current--;
    return deletedvalue;
    }

    int search(int target){
        for(int i = 0; i < size; i++){
            if(arr[i]== target){
                return i;
            }
        } return -1;
    }

    void display(){
         if (current == 0) {
            printf("List is empty\n");
            return;
        }
        
        printf("List elements: ");
        for (int i = 0; i < current; i++) { 
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    

    int rotate1(int k){
    k=k%size;
    if (current == 0){
        printf("The list is empty\n");
        return 0;
    }
    for(int i=0;i<k;i++){
        int temp = arr[current-1];
        for(int j=current-1;j>0;j--){
        arr[j] = arr[j-1];
    }
    arr[0] = temp;
    }
    return 1;
}

    void reverse(int start, int end) {
    while(start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

int rotate2(int k) {
    if (current == 0) {
        printf("The list is empty\n");
        return 0;
    }
    k = k % current;
    reverse(0, k - 1);
    reverse(k, current - 1);
    reverse(0, current - 1);
    
    return 1;
}
    void swap(int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

    
    void rotate3(int k) {
    if (current == 0) {
        printf("The list is empty\n");
        return;
    }
    
    k = k % current;  
    start = (start + k) % current;  

    printf("Array rotated by %d positions\n", k);
 
}

    };


int main(){
    List list;
    int choice;
    int k;
    int value;
    int pos;
    int temp;
    int target;
    int result;

    while(true){
        printf("-------------MENU--------------\n");
        printf("1. Insertion at the beginning. \n");
        printf("2. Insertion at the end. \n");
        printf("3. Insertion at any position.\n");
        printf("4. Delete at the beginning. \n");
        printf("5. Delete at the end. \n");
        printf("6. Delete at any position. \n");
        printf("7. Search. \n");
        printf("8. Display. \n");
        printf("9. Rotate. \n");
        printf("10. Exit.  \n");

        printf("enter your choice: ");
        scanf("%d" , &choice);
    
    switch(choice){
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            list.insertatbeg(value);
            list.display();
            break;

        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            list.insertatend(value);
            list.display();
            break;

        case 3:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            printf("Enter the position to be inserted in: ");
            scanf("%d", &pos);
            list.insertatpos(value, pos);
            list.display();    
            break;

        case 4:
            result=list.deleteatbeg();
            printf("The deleted element is :%d\n ", result);
            list.display();
            break;

        case 5:
            result = list.deleteatend();
            printf("The deleted element is :%d\n ", result);
            list.display();
            break;

        case 6:
            printf("Enter the position at which the value is to be deleted: ");
            scanf("%d", &pos);
            result= list.deleteatpos(pos);
            printf("The deleted value is :%d\n", result); 
            list.display();
            break;

        case 7:
            
            printf("Enter the target to be searched for: ");
            scanf("%d", &target);
            result = list.search(target);
            if(result == -1){
                printf("target not found!");
            }
            else
                printf("The target is found at the index: %d\n" , result);
            list.display();
            break;

        case 8:
            list.display();
            break;

        case 9:
            printf("Enter the number of times to be rotated: ");
            scanf("%d", &k);
            list.rotate2(k);
            list.display();
            break;

        default:
            printf("Invalid Choice!!!");
            printf("Exiting......");
            

    }
    
}

return 0;
}



