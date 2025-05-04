#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <conio.h>
using namespace std;

#include<cstdio>
#include<cstdlib>

class List{
    private:
        struct Node{
        int data;
        Node* next;
        
        };
        struct Node *head;
    
    public:    
        void insertatend(int);
        void deleteatbeg();
        void display();
        void execute(int);

    List(){
        head = NULL;
    }

};



void List::insertatend(int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = num;
    if(head == NULL){
        newNode -> next = newNode;
        head = newNode;}
    else{
        Node*temp = head;
        while(temp ->next != head){
            temp = temp->next;
            }

            temp ->next = newNode;
            newNode -> next = head; 
    }    
}


void List::deleteatbeg(){
    if (head == NULL){
        printf("The list is empty\n");
        return;
    }
    if(head->next == head){
    free(head);
    head = NULL;
    return;}

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;}

        Node* deletea = head;
        head = head ->next;
        temp ->next = head;
        free(deletea);
    
}

void List::display(){
    if(head == NULL){
        printf("The list is empty");
    }

    else{
        Node* temp = head;
        while(temp -> next  != head){
            printf("%d -> ", temp->data);
            temp = temp ->next;}

        printf("%d -> Head\n", temp->data);
    }
}  


void List::execute(int x) {
    if (head == NULL) {
        return;
    }

    if (head->data - x <= 0) {
        deleteatbeg();
    } else {
        int a = head->data - x;
        deleteatbeg();
        insertatend(a);
    }

}
#endif