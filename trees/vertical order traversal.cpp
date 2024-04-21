/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        //verticalIndex, level, nodes
        queue<pair<TreeNode*, vector<int>>>que;
        que.push({root, {0,0}});
        // mp[0][0] = {root->val};
        while(!que.empty()) {
            pair<TreeNode*, vector<int>>temp = que.front();
            que.pop();
            mp[temp.second[0]][temp.second[1]].insert(temp.first->val);
            if(temp.first->left != NULL) {
                que.push({temp.first->left, {temp.second[0]-1, temp.second[1]+1}});
            }
            if(temp.first->right != NULL) {
                que.push({temp.first->right, {temp.second[0]+1, temp.second[1]+1}});
            } 
        }
        vector<vector<int>>verticalTraversal;
        for(auto i: mp) {
            vector<int>row;
            for(auto j: i.second) {
               row.insert(row.end(), j.second.begin(), j.second.end());
            }
             verticalTraversal.push_back(row);
        }
        return verticalTraversal;
    }
};
