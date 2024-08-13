#define MAX_SIZE 100 // Assuming a maximum grid size

typedef struct {
    int row;
    int col;
    int steps;
} QueueNode;

typedef struct {
    QueueNode nodes[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} Queue;

void queueInit(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool queueIsEmpty(Queue *q) {
    return q->front == -1;
}

bool queueIsFull(Queue *q) {
    return q->rear == MAX_SIZE * MAX_SIZE - 1;
}

void queuePush(Queue *q, QueueNode node) {
    if (queueIsFull(q)) return;
    if (queueIsEmpty(q)) q->front = 0;
    q->nodes[++q->rear] = node;
}

QueueNode queuePop(Queue *q) {
    QueueNode node = {0, 0, 0};
    if (queueIsEmpty(q)) return node;
    node = q->nodes[q->front++];
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return node;
}

int directions[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool valid(int row, int col, int n, int** grid) {
    return row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0;
}


int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    if (grid[0][0] == 1) {
        return -1;
    }

    bool seen[MAX_SIZE][MAX_SIZE] = {false};
    Queue queue;
    queueInit(&queue);

    seen[0][0] = true;
    QueueNode start = {0, 0, 1};
    queuePush(&queue, start);

    while (!queueIsEmpty(&queue)) {
        QueueNode curr = queuePop(&queue);
        if (curr.row == n - 1 && curr.col == n - 1) {
            return curr.steps;
        }

        for (int i = 0; i < 8; i++) {
            int nextRow = curr.row + directions[i][0];
            int nextCol = curr.col + directions[i][1];
            if (valid(nextRow, nextCol, n, grid) && !seen[nextRow][nextCol]) {
                seen[nextRow][nextCol] = true;
                QueueNode nextNode = {nextRow, nextCol, curr.steps + 1};
                queuePush(&queue, nextNode);
            }
        }
    }

    return -1;
}