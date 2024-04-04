class Node {
private:
    Node* links[2];
public:
    bool containsBit(int bit) {
        return links[bit] != NULL;
    }

    void putBit(int bit) {
        links[bit] = new Node();
    }

    Node* nextBit(int bit) {
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
        for(int i=31;i>=0;i--) {
            int bit = (number >> i) & 1;
            if(node != NULL && !node->containsBit(bit)) {
                node->putBit(bit);
            }
            node=node->nextBit(bit);
        }
    }

    int getMaxXOR(int number) {
        Node* node = root;
        int maximum_xor = 0;
        for(int i=31;i>=0;i--) {
            int bit = (number >> i) & 1;
            if(node->containsBit(!bit)) {
                maximum_xor = maximum_xor | (1 << i);
                node = node->nextBit(!bit);
            } else {
                node = node->nextBit(bit);
            }
        }
        return maximum_xor;
    }
};
bool compare(pair<int, vector<int>>a, pair<int, vector<int>>b) {
        if(a.second[1] >= b.second[1])
            return false;
        return true;
    }

class Solution {
public:
    

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        vector<pair<int, vector<int>>>query;
        for(int i=0;i<queries.size();i++) {
            query.push_back({i, {queries[i][0], queries[i][1]}});
        }
        sort(query.begin(), query.end(), compare);
        sort(nums.begin(), nums.end());
        vector<int>ans(queries.size(), -1);

        int arr_index = 0;
        bool flg = false;
        for(int i=0;i<query.size();i++) {
            for(;arr_index<nums.size();arr_index++) {
                if(query[i].second[1] >= nums[arr_index]) {
                    trie.insert(nums[arr_index]);
                    flg = true;
                } else
                    break;
            }
            if(flg)
                ans[query[i].first] = trie.getMaxXOR(query[i].second[0]);
        }
        return ans;
    }
};
