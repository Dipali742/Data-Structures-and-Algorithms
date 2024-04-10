class Node {
private:
    Node* links[26];
    bool end = false;
    int cnt = 0;
public:
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void putKey(char ch) {
        links[ch-'a'] = new Node();
    }

    Node* nextNode(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        end = true;
    }

    int getCnt(char ch) {
        return links[ch-'a']->cnt;
    }

    void increaseCnt() {
        cnt++;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->putKey(word[i]);
            }
           
            node = node->nextNode(word[i]);
            node->increaseCnt();
        }
        node->setEnd();
    }

    string longestPrefix(string word, int n) {
        Node* node = root;
        string ans = "";
        for(int i = 0;i<word.length();i++) {
            if(node->getCnt(word[i]) == n)
                ans+=word[i];
            else
                break;

            node = node->nextNode(word[i]);
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(int i = 0;i<strs.size();i++) {
            trie.insert(strs[i]);
        }

        return trie.longestPrefix(strs[0], strs.size());
    }
};
