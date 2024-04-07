/*
Naive solution - XOR every element with every other element in an array using XOR(^) operator
Time Complexity: O(n^2)

Better approach - using Trie
Space Complexity: O(n*32)
Time Complexity: O(n*32)
*/

class Node {
private:
    Node* links[2];
public:
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void putKey(int bit) {
        links[bit] = new Node();
    }

    Node* getNext(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public: 
    Trie() {
        root = new Node();
    }

    void insert(int number) {
        Node* node = root;
        int temp_number = number;
        for(int i=31;i>=0;i--) {
            int bit = (temp_number>>i) & 1;
            if(!node->containsKey(bit)) {
                node->putKey(bit);
            }
            node = node->getNext(bit);
        }
    }

    int max_XOR(int x) {
        Node* node = root;
        int temp_number = x;
        int maximum_xor = 0;
        for(int i=31;i>=0;i--) {
            int bit = (temp_number>>i) & 1;
            if(node->containsKey(!bit)) {
                maximum_xor = maximum_xor | (1<<i);
                node = node->getNext(!bit);
            } else
                node = node->getNext(bit);     
        }
        return pair_num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(int i=0;i<n;i++) {
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<n;i++) {
            int x = nums[i];
            maxi = max(maxi, trie.max_XOR(x));
        }
        return maxi;
    }
};
