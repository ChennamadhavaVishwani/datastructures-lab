#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;                  // Number of vertices
    list<int>* adj;         // Pointer to array of adjacency lists

public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void insertEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex number!" << endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex number!" << endl;
            return;
        }
        adj[u].remove(v);
        adj[v].remove(u);
    }

    void searchEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex number!" << endl;
            return;
        }

        for (int neighbor : adj[u]) {
            if (neighbor == v) {
                cout << "Edge exists between " << u << " and " << v << endl;
                return;
            }
        }
        cout << "No edge between " << u << " and " << v << endl;
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " -> ";
            }
            cout << "NULL\n";
        }
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    int V, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    while (true) {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g.insertEdge(u, v);
            break;

        case 2:
            cout << "Enter edge to delete (u v): ";
            cin >> u >> v;
            g.deleteEdge(u, v);
            break;

        case 3:
            cout << "Enter edge to search (u v): ";
            cin >> u >> v;
            g.searchEdge(u, v);
            break;

        case 4:
            g.display();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
