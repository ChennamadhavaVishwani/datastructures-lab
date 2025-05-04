// A header file with function definitions
#ifndef DSALAB1_H
#define DSALAB1_H

void bubblesort(int arr[], int n);
void selectionsort(int arr[], int n);
void insertionsort(int arr[], int n);
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
#endif