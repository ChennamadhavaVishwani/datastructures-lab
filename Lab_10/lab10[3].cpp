// Program to implement a Priority Queue using Max-Heap with operations like insert, deleteMax, search, and heap sort

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];  
    int size;     
     
public:
    PriorityQueue() {
        size = 0;  
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        // Bubble up the element to maintain heap property
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void insert(int value) {
        if (size >= 100) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        heap[size] = value;         // Insert new value at the end
        heapifyUp(size);            // Fix heap upwards
        size++;
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        // Compare node with its children to maintain max-heap
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);  // Recurse down the heap
        }
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap[size - 1];  // Replace root with last element
        size--;
        heapifyDown(0);           // Fix heap downwards

        return maxValue;
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value)
                return i;  
        }
        return -1;  
    }

    void heapSort() {
        int tempSize = size;
        // Repeatedly move the max to the end and restore the heap
        while (size > 1) {
            swap(heap[0], heap[size - 1]);
            size--;
            heapifyDown(0);
        }
        size = tempSize;  
        cout << "Sorted Elements: ";
        display();
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert\n2. Delete Max\n3. Display\n4. Search\n5. Heap Sort\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                cout << "Deleted max value: " << pq.deleteMax() << endl;
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                int index;
                index = pq.search(value);
                if (index != -1)
                    cout << "Value found at index: " << index << endl;
                else
                    cout << "Value not found!" << endl;
                break;

            case 5:
                pq.heapSort();
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
