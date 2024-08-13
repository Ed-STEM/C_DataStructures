#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct {
    int *edges[MAX_NODES];
    int edgeCount[MAX_NODES];
    bool seen[MAX_NODES];
    int numNodes;
} Solution;

void initSolution(Solution *sol, int numNodes) {
    sol->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        sol->seen[i] = false;
        sol->edgeCount[i] = 0;
        sol->edges[i] = (int *)malloc(MAX_NODES * sizeof(int)); // Allocate memory for adjacency list
    }
}

void addEdge(Solution *sol, int u, int v) {
    sol->edges[u][sol->edgeCount[u]++] = v;
    // For undirected graph, add the reverse edge as well
    // sol->edges[v][sol->edgeCount[v]++] = u;
}

bool dfs(Solution *sol, int node, int destination) {
    if (node == destination) {
        return true;
    }
    sol->seen[node] = true;
    for (int i = 0; i < sol->edgeCount[node]; i++) {
        int neighbor = sol->edges[node][i];
        if (!sol->seen[neighbor]) {
            if (dfs(sol, neighbor, destination)) {
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination) {
    Solution sol;
    initSolution(&sol, n);
    for (int i = 0; i < edgesSize; i++) {
        addEdge(&sol, edges[i][0], edges[i][1]);
    }

    bool pathExists = dfs(&sol, source, destination);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(sol.edges[i]);
    }

    return pathExists;
}