/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {

    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    if (root->val < val){
        root->right =  insertIntoBST(root->right, val);
    } else if (root->val > val) {
        root->left =  insertIntoBST(root->left, val);
    } 
    
    return root;
    
}