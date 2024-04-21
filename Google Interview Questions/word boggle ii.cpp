class TrieNode {
private:
    unordered_map<char, TrieNode*>children;
    bool end;
    bool found;
public:
    TrieNode() {
        end = false;
        found = false;
    }
    
    bool containsChild(char ch) {
        return children.find(ch) != children.end();
    }
    
    void putChild(char ch) {
        children[ch] = new TrieNode();
    }
    
    TrieNode* getChild(char ch) {
        return children[ch];
    }
    
    void setEnd() {
        end = true;
    }
    
    unordered_map<char, TrieNode*>getChildren() {
        return children;
    }
    
    bool isEnd() {
        return end;
    }
    
    bool isFound() {
        return found;
    }
    
    void setFound() {
        found = true;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsChild(word[i])) {
                node->putChild(word[i]);
            }
            node = node->getChild(word[i]);
        }
        node->setEnd();
    }
    
    TrieNode* getNode() {
        return root;
    }
};

class Solution {
public:
    bool isSafe(int row, int column, int r, int c, vector<vector<int>>&visited) {
        return (row < r && row >= 0 && column < c && column >= 0 && visited[row][column] == -1);
    }
    
    void recursive(vector<vector<char>>&mp, TrieNode* root, vector<string>&ans, vector<vector<int>>&visited, int r, int c, string gate) {
       
        if(root->isEnd() && !root->isFound()) {
            ans.push_back(gate);
            root->setFound();
        }
        
        visited[r][c] = 1;
        for(auto it: root->getChildren()) {
            char gate_char = it.first;
               
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(i == 0 && j == 0)
                        continue;
                        
                    int row = r + i;
                    int column = c + j;
                    if(isSafe(row, column, mp.size(), mp[0].size(), visited) ) {
                        if(gate_char == mp[row][column]) {
                            recursive(mp, it.second, ans, visited, row, column, gate + gate_char);
                        }
                    }
                }
            }
        }
        
        visited[r][c] = -1;
     }
    
	vector<string> openGates(vector<vector<char> >& mp, vector<string>& gate_names) {
	   Trie trie;
	  
	   for(auto gate : gate_names) {
	       trie.insert(gate);
	   }
	   
	   TrieNode* root = trie.getNode();
	   vector<vector<int>>visited(mp.size(), vector<int>(mp[0].size(), -1));
	   vector<string>ans;
	   for(int i = 0;i<mp.size();i++) {
	       for(int j =0;j<mp[0].size();j++) {
	           if(root->containsChild(mp[i][j])) {
	               char ch =  mp[i][j];                                                                                        
	               string str = "";
	               str += ch;
	               recursive(mp, root->getChild(ch), ans, visited, i, j, str);
	           }
	              
	       }
	   }
	   
	   return ans;
	}
};
