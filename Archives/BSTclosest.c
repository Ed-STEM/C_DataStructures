/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int closestValue(struct TreeNode* root, double target) {
    
    float val = 0;
    int closest = root->val;
    struct TreeNode* current = root;

    while (current != NULL) {
        // Update the closest value if the current node is closer to the target
        //if (abs(target - current->val) < abs(target - closest)) {
        //closest = current->val;
        //}
        val = current->val;
        double abs_vt = (double)abs(((double)val - (double)target));
  
        double abs_ct = (double)abs(((double)closest - (double)target));
        closest = (abs_vt < abs_ct || (abs_vt == abs_ct && val < closest)) ? val : closest;
        printf(" closest %d,%d ", abs_vt, abs_ct);
        // Decide to go left or right based on the target value
        if (target < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
        
    }

    return closest;
    
}