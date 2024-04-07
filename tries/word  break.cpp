#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return dfs(0, s, trie.root);
    }

    bool dfs(int start, const string& s, TrieNode* node) {
        if (start == s.length()) {
            return true;
        }

        TrieNode* curr = node;
        for (int i = start; i < s.length(); i++) {
            char c = s[i];
            if (curr->children.find(c) == curr->children.end()) {
                break;
            }
            curr = curr->children[c];
            if (curr->isEnd && dfs(i + 1, s, node)) {
                return true;
            }
        }
        return false;
    }
};
