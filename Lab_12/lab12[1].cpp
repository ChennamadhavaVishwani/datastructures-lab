#include <cstdio>
#include <cstdlib>

class Matrix {
private:
    int **adj;
    int vertices;

public:
    Matrix(int v) {
        vertices = v;
        adj = (int**) malloc(vertices * sizeof(int*));
        for (int i = 0; i < vertices; ++i) {
            adj[i] = (int*) malloc(vertices * sizeof(int));
            for (int j = 0; j < vertices; ++j) {
                adj[i][j] = 0;
            }
        }
    }

    void insertEdge(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid edge!\n");
            return;
        }
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid edge!\n");
            return;
        }
        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    void searchEdge(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid input!\n");
            return;
        }
        if (adj[u][v] == 1)
            printf("Edge exists between %d and %d\n", u, v);
        else
            printf("No edge between %d and %d\n", u, v);
    }

    void display() {
        printf("Adjacency Matrix:\n");
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }
    }

    
};

int main() {
    int vertices, choice, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Matrix graph(vertices);

    while (true) {
        printf("\n------------ MENU ------------\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Display Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter edge (u v): ");
            scanf("%d %d", &u, &v);
            graph.insertEdge(u, v);
            break;
        case 2:
            printf("Enter edge (u v): ");
            scanf("%d %d", &u, &v);
            graph.deleteEdge(u, v);
            break;
        case 3:
            printf("Enter edge (u v): ");
            scanf("%d %d", &u, &v);
            graph.searchEdge(u, v);
            break;
        case 4:
            graph.display();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
