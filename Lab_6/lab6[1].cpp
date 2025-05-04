//A c++ menu driven program to implement stack ADT using array implementation 
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

    void push(int num){
    if (current>=size) return ;
        arr[current] = num;
        current++;
        return;
    }
    
    int pop(){
        if (current == 0){
            printf("Stack overflow!!");
            return -1;
        } 
        int deletedValue = arr[current - 1]; 
        current--; 
        return deletedValue;
    }

    int peek(){
        return arr[current];
    }

    void display(){
       
         if (current == 0) {
            printf("List is empty\n");
            return;
        }
        
        printf("List elements: ");
        for (int i = current -1; i>= 0; i--) { 
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
   
};
int main(){
    List stack;
    int num, choice, target, result, res;
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
        result = stack.pop();
        printf("The popped element is: %d\n", result);
        stack.display();
        break;

        case 3:
        res= stack.peek();
        printf("The element on the top is: %d\n", res);
        break;

        case 4:
        printf("Exiting....");

        default:
        printf("Inavlid choice!!!");
        printf("Exiting...");
    }
        
    }
return 0;}