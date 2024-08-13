/*
Enormously important LeetCode example for C called the Binary Tree ZigZag Traversal.
Here are the reasons:
In this code are algorithm examples for handling Binary Tree Traversals and using
a Queue to find the result.  From a C syntax point of view this example is also one 
of the most important. It contains the syntax systems for dynamically allocating a 
multi-dimensional array.  Handling pointers, pointers to pointers, edge cases, updating 
sizes and so forth.
*/
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
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).
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


// Test the function
int main() {
    // Example usage
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int returnSize = 0;
    int** returnColumnSizes;
    int** result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < *returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
        free(returnColumnSizes[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}