// A cpp menu driven program to implement queue using array
#include<cstdio>
#include<cstdlib>
class Queue{
    private:
    int arr[5];
    int front;
    int rear;
    int size;

    public:
    Queue(){
    size = 5;
    front = -1;
    rear = -1;
    }


void enqueue(int num){
    if(rear>size-1){
        printf("Overflow!!");
    }
    if(front = -1) front = 0;
    rear++;
    arr[rear]=num;
    return;

}

int dequeue(){
    if(front == -1 || front>rear ){
        printf("Underflow!!");
        return -1;
    }
    if(front = -1) front = 0;
    int deletedvalue = arr[front];
    front++;
    return deletedvalue;
}

int peek(){
    return arr[front];
}


void display(){
         if (front == -1) {
            printf("List is empty\n");
            return;
        }
        
        printf("List elements: ");
        for (int i = front; i <= rear; i++) { 
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
};


int main(){
    Queue q;
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