class Solution{
public:

    int dfs(Node* root, int l, int h) {
        
        if(root == NULL)
            return 0;
        
        int cnt = 0;
        //greater
        if(root->data >= l && root->data <= h) {
            cnt = 1 + dfs(root->left, l, h) + dfs(root->right, l, h);
        }
        
        if(root->data < l)
            cnt += dfs(root->right , l , h);
        
        if(root->data > h)
            cnt += dfs(root->left, l, h);
        
        return cnt;
    }
    
    int getCount(Node *root, int l, int h)
    {
        return dfs(root, l, h);
    }
};
