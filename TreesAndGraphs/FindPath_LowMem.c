#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* edges[MAX_NODES];
    bool seen[MAX_NODES];
    int numNodes;
} Solution;

void initSolution(Solution *sol, int numNodes) {
    sol->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        sol->seen[i] = false;
        sol->edges[i] = NULL;
    }
}

void addEdge(Solution *sol, int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = sol->edges[u];
    sol->edges[u] = newNode;

    // For undirected graph, add the reverse edge as well
    Node* newNodeRev = (Node*) malloc(sizeof(Node));
    newNodeRev->vertex = u;
    newNodeRev->next = sol->edges[v];
    sol->edges[v] = newNodeRev;
}

bool dfs(Solution *sol, int source, int destination) {

    if (source == destination) {
        return true;
    }

    sol->seen[source] = true;
    Node* temp = sol->edges[source];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!sol->seen[neighbor]) {
            if (dfs(sol, neighbor, destination)) {
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
}

bool validPath(int n, int **edges, int edgesSize,int *edgesColSize, int source, int destination) {
    Solution sol;
    initSolution(&sol, n);

    for (int i = 0; i < edgesSize; i++) {
        addEdge(&sol, edges[i][0], edges[i][1]);
    }
    
    bool pathExists = dfs(&sol, source, destination);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node* current = sol.edges[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    return pathExists;
}

/*

int dfs(Solution *sol, int source, int destination, int count){
    if (source != destination) {
        printf(" edgecase ");
        count++;
        return count;
    }
    
    sol->seen[source] = true;
    Node* temp = sol->edges[source];
    
    while (temp != NULL){
        int neighbor = temp->vertex;
        if (!sol->seen[neighbor]){
            //This will always return 1 needs to get to an iterator.
            if (dfs(sol, neighbor, destination, count) == count){
                printf(" Inner Count Condition: %d ", count);
                return count;
            } 
            
            count++;
            printf(" Middle Count Condition: %d ", count);
        }
        printf(" Loop dfs count condition: %d ", count);
        //count++;
        temp = temp->next;
    }
    
    return count;
}