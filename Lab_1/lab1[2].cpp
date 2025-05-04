// A CPP file to implement searching

#include <stdio.h>
#include "lab1[1].h"

int binary_search(int arr[], int n, int target) {
    bubblesort(arr, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid =(high + low) / 2;
        
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int linearsearch(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}
int main(){
     int n, target, choice, ind;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }


  do {
       printf("\nMenu!\n");
       printf("1. Linear Search\n");
       printf("2. Binary search\n");
       printf("3. Exiting.....\n");
       printf("enter your choice : ");
       scanf("%d", &choice);

     switch (choice){

         case 1:
         printf("Enter the target: ");
         scanf("%d", &target);
        ind =  linearsearch(arr, n, target);
        if (ind != -1){
            printf("The element is at index: %d\n", ind);
        } 
        else {
            printf("Element not found!\n");
        }
               break; 

         case 2:
         printf("Enter the target: ");
         scanf("%d", &target);
        ind = binary_search(arr, n, target);
             if (ind != -1){
         printf("The element is at index: %d\n", ind);
              } 
              else {
            printf("Element not found!\n");
        }
           break;

           case 3:
            printf("exiting...\n");
            break;
        
           default:
             printf("Invalid Choice entered\n");

       }
    } while(choice != 3);

 return 0;
}
  

