#include<bits/stdc++.h>

using namespace std;

class Node {
private:
    Node* links[26];
    int cntPrefix = 0;
    int cntEnd = 0;
public:
  bool containsKey(char ch) {
      return links[ch-'a'] != NULL;
  }

  void addKey(char ch) {
      links[ch-'a'] = new Node();
  }

  Node* getNode(char ch) {
      return links[ch-'a'];
  }

  void increasePrefix() {
      cntPrefix++;
  }

  void increaseEnd() {
      cntEnd++;
  }

  int getEnd() {
      return cntEnd;
  }

  int getPrefix() {
      return cntPrefix;
  }

  void reducePrefix() {
      cntPrefix--;
  }

  void reduceEnd() {
      cntEnd--;
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
            if(!node->containsKey(word[i]))
                node->addKey(word[i]);
            node = node->getNode(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
              if(!node->containsKey(word[i]))
                  return 0;
              node = node->getNode(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
              if(!node->containsKey(word[i]))
                  return 0;
              node = node->getNode(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
              node = node->getNode(word[i]);
              node->reducePrefix();  
        }
        node->reduceEnd();
    }
};

int main() {
    Trie trie;
    trie.insert("abcd");
    trie.insert("abcd");
    trie.insert("abc");
    trie.insert("dog");
    cout<<trie.countWordsEqualTo("dog")<<endl;
    cout<<trie.countWordsEqualTo("abcd")<<endl;
    cout<<trie.countWordsStartingWith("abc")<<endl;
    trie.erase("abcd");
    cout<<trie.countWordsEqualTo("dog")<<endl;
    cout<<trie.countWordsEqualTo("abcd")<<endl;
    cout<<trie.countWordsStartingWith("abc")<<endl;
    return 0;
}
