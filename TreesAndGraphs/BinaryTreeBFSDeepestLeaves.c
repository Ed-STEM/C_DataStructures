/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void sumAtDepth(struct TreeNode* root, int depth, int* sum){
    if (root == NULL){
        return;
    }
    if (depth == 1){
        *sum += root->val;
    } else {
        sumAtDepth(root->left, depth -1, sum);
        sumAtDepth(root->right, depth -1, sum);
    }
}

int deepestLeavesSum(struct TreeNode* root) {
    int depth = maxDepth(root);
    int sum = 0;
    sumAtDepth(root, depth, &sum);
    return sum;

}