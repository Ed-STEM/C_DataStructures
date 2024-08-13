/*
    Data Structures: Replace C++ unordered_map and vector with C arrays or dynamically allocated arrays.
    Function Definitions: In C, functions are defined globally and not as part of structures.
    Passing Arrays: In C, arrays are passed to functions by pointer.
    Graph Representation: We can represent the graph using an adjacency list, 
    which can be an array of lists or a 2D array if the maximum number of edges is known.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100 // Assuming a maximum number of nodes

typedef struct {
    int edges[MAX_NODES][MAX_NODES];
    int edgeCount[MAX_NODES];
    bool seen[MAX_NODES];
    int numNodes;
} Solution;

void initSolution(Solution *sol, int numNodes) {
    sol->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        sol->seen[i] = false;
        sol->edgeCount[i] = 0;
        for (int j = 0; j < numNodes; j++) {
            sol->edges[i][j] = -1;
        }
    }
}

void addEdge(Solution *sol, int u, int v) {
    sol->edges[u][sol->edgeCount[u]++] = v;
    sol->edges[v][sol->edgeCount[v]++] = u;
}

void dfs(Solution *sol, int node) {
    sol->seen[node] = true;
    for (int i = 0; i < sol->edgeCount[node]; i++) {
        int neighbor = sol->edges[node][i];
        if (!sol->seen[neighbor]) {
            dfs(sol, neighbor);
        }
    }
}

int findCircleNum(Solution *sol, int isConnected[MAX_NODES][MAX_NODES]) {
    for (int i = 0; i < sol->numNodes; i++) {
        for (int j = i + 1; j < sol->numNodes; j++) {
            if (isConnected[i][j] == 1) {
                addEdge(sol, i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < sol->numNodes; i++) {
        if (!sol->seen[i]) {
            ans++;
            dfs(sol, i);
        }
    }
    return ans;
}

int main() {
    Solution sol;
    int isConnected[MAX_NODES][MAX_NODES] = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1}
    };

    int numNodes = 3;
    initSolution(&sol, numNodes);
    int circleNum = findCircleNum(&sol, isConnected);
    printf("Number of Provinces: %d\n", circleNum);

    return 0;
}

/*

In this refactored code:

- The `Solution` structure holds the graph's adjacency list, a seen array to track visited nodes, and the total number of nodes.
- The `initSolution` function initializes the `Solution` structure with the number of nodes.
- The `addEdge` function adds an edge to the graph's adjacency list.
- The `dfs` function performs a depth-first search to traverse the graph.
- The `findCircleNum` function builds the graph from the `isConnected` matrix and then counts the number of connected components (provinces) in the graph.
- The `main` function demonstrates how to use the `Solution` structure and its functions.


*/