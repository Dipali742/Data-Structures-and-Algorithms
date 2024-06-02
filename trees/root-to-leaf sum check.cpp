class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int &currentSum) {
        currentSum += root->val;
        if(currentSum == targetSum && !root->left && !root->right)
            return true;
        bool leftR = false;
        bool rightR = false;
       
        if(root->left) {
            leftR = hasPathSum(root->left, targetSum, currentSum);
        }
        if(root->right) {
            rightR = hasPathSum(root->right, targetSum, currentSum);
        } 
        currentSum -= root->val;
        return leftR || rightR;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        int currentSum = 0;
        return hasPathSum(root, targetSum, currentSum);
    }
};
