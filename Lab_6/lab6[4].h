#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class SLL {
private:
    struct Node {
        int data;
        Node* link;
    };
    Node* head;

public:
    SLL() {
        head = NULL;
    }

    void push(int num) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->link = head;
        head = newNode;
    }

    void pop() {
        if (head == NULL) {
            printf("The stack is empty\n");
            return;
        }
        Node* temp = head;
        head = head->link;
        free(temp);
    }

    int peek() {
        if (head == nullptr) {
            printf("The stack is empty\n");
            return -1;
        }
        return head->data;
    }

    bool isEmpty() { 
        return head == NULL;
    }

    void display() {
        if (head == NULL) {
            printf("The stack is empty\n");
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }

    bool isBalanced(string str) {
        SLL stack;  
        for (char ch : str) {
            if (ch == '(') {
                stack.push(ch);  
            } else if (ch == ')') {
                if (stack.isEmpty()) {
                    return false;  
                }
                stack.pop();  
            }
        }

        return stack.isEmpty();  
    }
};

#endif
