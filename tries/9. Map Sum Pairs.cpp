class Node {
private: 
    map<char, Node*>mp;
    int sum = 0;
public:
    bool containsKey(char key) {
        return mp.find(key) != mp.end();
    }

    void putKey(char key) {
        mp[key] = new Node();
    }

    void addSum(int val) {
        sum+= val;
    }

    Node* nextKey(char key) {
        return mp[key];
    }

    int getSum() {
        return sum;
    }
};

class MapSum {
private:
    Node* root;
    map<string, int>input;
public:
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* node = root;
        if(input.find(key) != input.end()) {
            int current = input[key];
            input[key] = val;
            val = val - current;
        } else {
            input[key] = val;
        }
        for(int i=0;i<key.length();i++) {
            if(!node->containsKey(key[i])) {
                node->putKey(key[i]);
            }
            node->addSum(val);
            node = node->nextKey(key[i]);
        }
        node->addSum(val);
        
    }
    
    int sum(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++) {
            if(!node->containsKey(prefix[i]))
                return 0;
            node = node->nextKey(prefix[i]);
        }
        return node->getSum();
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
