/*
Que1 : Given a binary tree, find its inorder string repesentation
*/

void inorder(TreeNode* node, string &result) {
    if(root == NULL)
        return;
    inorder(node->left, result);
    result += node->data;
    inorder(node->right, result);
}


/*
Que2 : Given two binary trees, check if its inorder string representations are same.
*/

//Approach 1 : call method written in earlier que and compare
bool isEqualInorderTraversal(TreeNode* root1, TreeNode* root2) {
    string result1 = "";
    string result2 = "";
    inorder(root1, result1);
    inorder(root2, result2);
    return result1 == result2;
}

//Approach 2 : write two different methods
bool findInorderAndCompare(TreeNode* root, string result, int &index) {
    if(root != NULL) {
        bool leftCheck = findInorderAndCompare(root->left, result, index);
        if(index >= result.length() || result[index] != root->data)
            return false;
        index++;
        bool rightCheck = findInorderAndCompare(root->right, result, index);
        return leftCheck || rightCheck;
    }
    return result.length() == index;
}

bool isEqualInorderTraversal(TreeNode* root1, TreeNode* root2) {
    string result = "";
    inorder(root1, result);
    int index = 0;
    return findInorderAndCompare(root2, result, index);
}

