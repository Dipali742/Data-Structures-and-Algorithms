class Solution {
public:

    string dupSub1(Node* root, unordered_set<string>&subtrees, bool &flg)
    {
        
        if (root == NULL || flg) {
            return "";
        }

        string s = "";
        string s1 = dupSub1(root->left, subtrees, flg);
        string s2 = dupSub1(root->right, subtrees, flg);
        
        
        s += (s1 + (root->data) + s2);

        if (s.size() >= 2) {
            if(subtrees.find(s) != subtrees.end()) {
                flg = true;
                return "";
            }
            subtrees.insert(s);
        }

        return s;
    }

    int dupSub(Node* root)
    {
        unordered_set<string> subtrees;
        bool flg = false;
        string st = dupSub1(root, subtrees, flg);

       return flg;
    }
};
