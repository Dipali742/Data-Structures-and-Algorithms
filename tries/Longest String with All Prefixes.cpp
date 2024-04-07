/*
Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None
*/

/*
  Naive approach using map
  T(C) => O(n*[average length of strings in array])
  S(C) => O(n)
*/
string completeString(int n, vector<string> &a){
        unordered_map<string, int>mp;
        for(int i=0;i<n;i++) {
            mp[a[i]]++;
        }

        string ans = "";

        for(int i=0;i<n;i++) {
            string str = a[i];
            string prefix = "";
            string longestPrefix = "";
            for(int j=0;j<str.length();j++) {
                prefix+=str[j];
                if(mp.find(prefix) != mp.end())
                    longestPrefix = prefix;
                else {
                    longestPrefix = "";
                    break;
                }
            }
            if (ans.length() < longestPrefix.length()) {
                ans = longestPrefix;
            } else if (ans.length() == longestPrefix.length() && ans > longestPrefix)
                ans = longestPrefix;
        }

        return ans != "" ? ans : "None";
}


/*
  using trie data structure.
  T(C) and S(C) are almost same. There is difference of constants. 
*/

#include <bits/stdc++.h> 

class Node {
private:
    Node* links[26];
    bool endFlag = false;

public:
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void putKey(char ch) {
        links[ch-'a'] = new Node();
    }

    Node* getKey(char ch) {
        return links[ch-'a'];
    }

    void isEnd() {
        endFlag = true;
    }

    bool isEndChar() {
        return endFlag;
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
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->putKey(word[i]);
            }
            node = node->getKey(word[i]);
        }
        node->isEnd();
    }   

    bool checkIfPrefix(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            node = node->getKey(word[i]);
            if(!node->isEndChar())
                return false;
        }
        return true;
    } 
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(int i=0;i<n;i++) {
        trie.insert(a[i]);
    }

    string ans = "";
    for(int i=0;i<n;i++) {
        if(trie.checkIfPrefix(a[i])) {
            if(ans.length() < a[i].length())
                ans = a[i];
            else if(ans.length() == a[i].length() && ans > a[i])
                ans = a[i];
        }
    }
    return ans!="" ? ans : "None";
} 
