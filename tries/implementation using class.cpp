#include<bits/stdc++.h>

using namespace std;

class Node {
private:
  Node* links[26];
  bool flg = false;

public:
  bool containsKey(char ch) {
      return links[ch-'a'] != NULL;
  }

  void addKey(char ch) {
      links[ch-'a'] = new Node();
  }

  Node* getKey(char ch) {
      return links[ch-'a'];
  }

  void setEnd() {
      flg = true;
  }

  bool isEnd() {
    return flg;
  }
  
};

class Trie {
private: 
  Node* root;
public:
  Trie() {
    root = new Node();
  }

  //O(len)
  void insert(string word) {
      Node* node = root;
      for(int i=0; i<word.length(); i++) {
          if(!node->containsKey(word[i])) {
              node->addKey(word[i]);
          }
          node = node->getKey(word[i]);
      }
      node->setEnd();
  }

  //O(len)
  bool searchWord(string word) {
      Node* node = root;
      for(int i=0;i<word.length();i++) {
          if(!node->containsKey(word[i])) {
              return false;
          }
          node = node->getKey(word[i]);
      }
      return node->isEnd();
  }

  //O(len)
  bool searchPrefix(string prefix) {
      Node* node = root;
      for(int i=0;i<prefix.length();i++) {
          if(!node->containsKey(prefix[i])) {
              return false;
          }
          node = node->getKey(prefix[i]);
      }
      return true;
  }
};

int main() {
  Trie trie;
  trie.insert("abcd");
  cout<<trie.searchWord("abc");
  cout<<trie.searchPrefix("abc");
  
  return 0;
}
