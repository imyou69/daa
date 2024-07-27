#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_V 100 // Define a maximum for the number of vertices

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX_V][MAX_V], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_V][MAX_V], int V) {
    int parent[MAX_V]; // Array to store constructed MST
    int key[MAX_V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[MAX_V]; // To represent set of vertices included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    key[0] = 0;       // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1;   // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet, V);
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V; 
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_V][MAX_V];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}