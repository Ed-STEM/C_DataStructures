/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxAncestorDiffHelper(struct TreeNode* root, int minVal, int maxVal){
    if (root == NULL){
        return maxVal - minVal;
    }
    
    maxVal = (root->val > maxVal) ? root->val : maxVal;
    minVal = (root->val < minVal) ? root->val : minVal;
    
    int leftDiff = maxAncestorDiffHelper(root->left, minVal, maxVal);
    int rightDiff = maxAncestorDiffHelper(root->right, minVal, maxVal);
    
    return (leftDiff > rightDiff) ? leftDiff : rightDiff;

}


int maxAncestorDiff(struct TreeNode* root) {
    
    if (root == NULL){
        return 0;
    }
    
    return maxAncestorDiffHelper(root, root->val, root->val);
    
}