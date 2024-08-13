#define MAX_NODES 50000

typedef struct Node {
    int vertex;
    int loopid;
    struct Node* next;
} Node;

typedef struct {
    Node* edges[MAX_NODES];
    bool seen[MAX_NODES];
    int numNodes;
} Solution;

void initSolution(Solution *sol, int numNodes){
    sol->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++){
        sol->seen[i] = false;
        sol->edges[i] = NULL;
    }
}

void addEdge(Solution *sol, int u, int v){
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = sol->edges[u];
    sol->edges[u] = newNode;
    
    // For undirected graph, add the reverse edge as well.
    Node* newNodeRev = (Node*)malloc(sizeof(Node));
    newNodeRev->vertex = u;
    newNodeRev->next = sol->edges[v];
    sol->edges[v] = newNodeRev;
    
}

bool dfs(Solution *sol, int source, int destination){
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


int countComponents(int n, int** edges, int edgesSize, int* edgesColSize) {

    // initialize the first source and destination.
    int island = 1;
    //int source = edges[0][0];
    //int destination = edges[edgesSize-1][1];

    // initialize the graph.    
    Solution sol;
    initSolution(&sol, n);
    for ( int i = 0; i < edgesSize; i++){
        addEdge(&sol, edges[i][0], edges[i][1]);
    }
    /*
    for (int vert = 0; vert < edgesSize; vert++ ){
        {
            printf("Loop running. ");
            if (!sol.seen[vert]){
                printf("DFS running. ");
                dfs(&sol, source, destination);
                island++;
            }
            
            //Need two edge cases. 
            
        }
    }*/
    for (int row = 0; row < edgesSize; row++){
        for (int col = 0; col <=1; col++){
            if (edges[row][col]){
                dfs(&sol, )
                
            }
        }
    }
    
    //Free memory
    for (int i = 0; i < n; i++){
        Node* current = sol.edges[i];
        while (current != NULL){
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return island;
    
}