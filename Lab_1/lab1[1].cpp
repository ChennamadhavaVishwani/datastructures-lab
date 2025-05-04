// A MENU-DRIVEN PROGRAM FOR SORTING 
#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int n){
    for (int i = 0; i < n-1; i++) {
        int smallestindex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[smallestindex]) {
               smallestindex = j;
            }
        }
        int temp = arr[smallestindex];
        arr[smallestindex] = arr[i];
        arr[i] = temp;
    }
}

void insertionsort(int arr[], int n) {
    for(int i = 1; i< n-1; i++){
        int key = arr[i];
        int j= i-1;
        while(j>=0 && arr[j]> key){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}
 
void printarray(int arr[], int n){
    for(int i= 0; i<n; i++ ){
        printf("%d\n", arr[i]);
    }
} 
int main() {
 int n, choice;
     printf("Enter the value of n: ");
     scanf("%d", &n);
    int arr[n];
     
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

do {
        printf("\nMenu!\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exiting.....\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
          case 1:
          bubblesort( arr, n);
          printf("the sorted array is : ");
          printarray( arr , n);
          break; 

          case 2:
          selectionsort(arr, n);
          printf("the sorted array is : ");
          printarray( arr, n);
          break;

          case 3:
          insertionsort(arr, n);
          printf("the sorted array is : ");
          printarray( arr, n);
          break; 

          case 4:
          printf("exiting...\n");
        
          default:
          printf("Invalid Choice entered\n");

        }
    } while(choice != 4);

return 0;
}
