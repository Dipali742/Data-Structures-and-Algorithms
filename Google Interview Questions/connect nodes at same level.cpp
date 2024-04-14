
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*>que;
       que.push(root);
       while(!que.empty()) {
           int size_que = que.size();
            for(int i = 0; i<size_que;i++) {
                Node* first = que.front();
                que.pop();
                // level.push_back(first);
                if(first->left)
                    que.push(first->left);
                if(first->right)
                    que.push(first->right);
                Node* second = NULL;
                if(i < size_que-1)
                    second = que.front();
                first->nextRight = second;
           }
       }
    }    
      
};
