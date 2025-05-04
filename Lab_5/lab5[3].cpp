// A cpp menu driven program to implement round robin scheduling using the header file
#include "lab5[3].h"

int main() {
    List L;
    int num, x, choice;
     while(choice != 3){
        printf("---------MENU---------\n");
        printf("1. Insert\n");
        printf("2. Execute\n");
        printf("3. Exit!\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter the number to be inserted:");
            scanf("%d", &num);
            L.insertatend(num);
            L.display();
            break;

        case 2:
            printf("Enter the time constraints: ");
            scanf("%d", &x);
            L.execute(x);
            L.display();
            break;
        
        case 3:
            printf("Exit!!");
            break;

        default:
        printf("Invalid Choice!!");
        printf("Exiting");    


}}return 0;
}