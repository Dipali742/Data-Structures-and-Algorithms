/*
  You are given a set of IP addressess and hostnames as shown below. You are supposed to write the code for 2 methods 
  Insert
  which takes an IP address and hostname and stores it
  Find
  which takes in an IP address and returns the hostname(s)
  e.g below the list of the IP address and Hostnames
  1.2.3.4 a.com
  1.2.3.5 b.com
  1.2.3.6 c.com
  1.6.2.4 d.com
  Insert(1.2.3.4 , a.com) 
  Insert(1.2.3.5 , b.com) 
  Insert(1.2.3.6 , c.com) 
  Insert(1.6.2.4 , d.com) 
  Find(1.2.3.4 ) must return {a.com}
  Find(1.2.3.) must return {a.com, b.com, c.com}
  Find(1.) must return {a.com, b.com,c.com, d.com}
  Find(2.) must return {}

  Time Complexity:
  Insert Operation: O(1)
  Find Operation:
  Complete IP Address: O(1)
  Incomplete IP Address: O(n)
  Space Complexity: O(n)
*/

#include<bits/stdc++.h>

using namespace std;

class Node {
private:
    Node* links[256];
    vector<string>hostnames;

public:
    bool containsOctet(int octet) {
        return links[octet] != NULL;
    }

    void putOctet(int octet) {
        links[octet] = new Node();
    }

    void updateHostnames(string hostname) {
        hostnames.push_back(hostname);
    }

    Node* nextNode(int octet) {
        return links[octet];
    }

    vector<string>getHostnames() {
        return hostnames;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string ip, string hostname) {
        Node* node = root;
        istringstream iss(ip);
        string token;
        while (getline(iss, token, '.')) {
            int octet = stoi(token);
            if(!node->containsOctet(octet)) {
                 node->putOctet(octet);
            }
            node->updateHostnames(hostname);
            node = node->nextNode(octet);
        }
        node->updateHostnames(hostname);
    }

    vector<string> find(string ip) {
        Node* node = root;
        istringstream iss(ip);
        string token;
        while(getline(iss, token, '.')) {
            int octet = stoi(token);
            if(!node->containsOctet(octet))
                return {};
            node = node->nextNode(octet);
        }
        return node->getHostnames();
    }
};

int main() {
  Trie trie;
  trie.insert("1.2.3.4", "a.com");
  trie.insert("1.2.3.5", "b.com");
  trie.insert("1.2.3.6", "c.com");
  trie.insert("1.6.2.4", "d.com");
  vector<string>ans;
  ans = trie.find("1.2.3.4");
  for(int i=0;i<ans.size();i++) {
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  ans = trie.find("1.2.3.");
  for(int i=0;i<ans.size();i++) {
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  ans = trie.find("1.");
  for(int i=0;i<ans.size();i++) {
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  ans = trie.find("2.");
  for(int i=0;i<ans.size();i++) {
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
