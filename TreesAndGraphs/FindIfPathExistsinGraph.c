
int closestValue(struct TreeNode* root, double target) {
    
    double closest = root->val;
    struct TreeNode* current = root;

    while (current != NULL) {
        double val = current->val;
        double abs_vt = fabs(val - target);
  
        double abs_ct = fabs(closest - target);
        closest = (abs_vt < abs_ct || (abs_vt == abs_ct && val < closest)) ? val : closest;
        // Decide to go left or right based on the target value
        if (target < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
        
    }

    return (int)closest;
    
}