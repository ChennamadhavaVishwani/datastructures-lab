// A cpp menu driven program to implement circular queue using array
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

    int enqueue(int num){
    if((rear + 1)%size == front ){
        printf("The queue is full!!");
        return -1;
    }
    rear = (rear+1)%size;
    if(front == -1) front = rear;
    arr[rear]=num;
    return 0;
    }

    int dequeue(){
    if(front == -1){
        printf("Underflow!!");
        return -1;
    }
    int deletedvalue = arr[front];
    if (front==rear)
    {
        front=rear=-1;
    }
    else{
        front = (front+1)%size;
    }
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
