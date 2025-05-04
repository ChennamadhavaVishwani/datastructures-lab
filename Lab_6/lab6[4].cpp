
#include "lab6[4].h"

int main() {
    SLL stack;
    char expression[100];
    int x, choice;
     while(true){
        printf("---------MENU---------\n");
        printf("1. Check Balance\n");
        printf("2. Exit!\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter the expression to be checked for:");
            scanf("%s", expression);
            
             if (stack.isBalanced(expression)) {
                    printf("Balanced Parentheses\n");
                } else {
                    printf("Unbalanced Parentheses\n");
                }
                
            break;
        
        case 2:
            printf("Exit!!");
            break;

        default:
        printf("Invalid Choice!!");
        printf("Exiting");    


}}return 0;
}