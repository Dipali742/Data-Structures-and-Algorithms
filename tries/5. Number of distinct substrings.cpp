/*
  Naive approach -> find all substrings and store in set 
  T(C) => O(n^2 * log(m))  
  S(C) => O(n^2 * n/2) => O(n^3)
  m is the size of the set, n is the length of the input string s
*/

int countDistinctSubstrings(string &s)
{
    unordered_set<string>st;
    for(int i=0;i<s.length();i++) {
        string str ="";
        for(int j=i;j<s.length();j++) {
            str+=s[j];
            st.insert(str);
        }

    }
    return st.size()+1;
}

/*
  Trie approach - to reduce space
  T(C) => O(n^2)
  S(C) => 26*26*26 => approximately n(n+1)/2 nodes (one node for each substring character)
*/

class Node {
private:
    Node* links[26];
public:
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void putKey(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* getNode(char ch) {
        return links[ch-'a'];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    int insert(string word) {
        Node* node = root;
        int cnt = 0;
        for(int i = 0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                cnt++;
                node->putKey(word[i], new Node());
            }   
            node = node->getNode(word[i]);
        }
        return cnt;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie trie;
    int cnt = 0;
    for(int i=0;i<s.length();i++) {
        string word = "";
        for(int j = i;j<s.length();j++) {
            word+=s[j];
            cnt += trie.insert(word);
        }
    }
    return cnt+1;
}
