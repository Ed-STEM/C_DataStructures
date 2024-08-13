/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TreeNode* newNode(int data){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // Edge case: if the tree is empty
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize variables for traversal
    int** result = NULL;
    *returnColumnSizes = NULL;
    *returnSize = 0;
    int level = 0, i;
    struct TreeNode* queue[10000]; // Assuming a maximum of 10000 nodes in the tree
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front; // Number of nodes at the current level
        int* currentLevel = (int*)malloc(levelSize * sizeof(int));
        for (i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            // Insert the node's value in the current level array
            int index = (level % 2 == 0) ? i : (levelSize - 1 - i); // Zigzag insertion
            currentLevel[index] = node->val;
            // Enqueue child nodes
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        // Resize and update the result array
        result = (int**)realloc(result, sizeof(int*) * (*returnSize + 1));
        result[*returnSize] = currentLevel;
        // Resize and update the returnColumnSizes array
        *returnColumnSizes = (int**)realloc(*returnColumnSizes, sizeof(int*) * (*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = (int*)malloc(sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
        level++;
    }
    return result;
    
          
}