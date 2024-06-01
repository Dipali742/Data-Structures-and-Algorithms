/*
Que1 : What do you know about trees?
Que2 : Write node structure of Binary trees
Que3 : What are N-ary trees, write node structure?
Que4 : Gave one node structure and asked to write pre-order traversal
*/

class TreeNode {
public:
    int data;
    TreeNode* leftMostChild;
    TreeNode* rightSibiling;
    TreeNode* parent;
}

void preorder(TreeNode* root) {
   if(root == NULL)
        return;
    TreeNode* node = root;
    bool flg = false;
    while(1) {
        if(!flg)
            cout<<node->data<<endl;
        if(!flg && node->leftMostChild) {
            node = node->leftMostChild;
        } else if(node->rightSibling) {
            node = node->rightSibling;
            flg = false;
        } else {
            node = node->parent;
            flg = true;
            if(node == root)
                break;
        } 
    }
}
