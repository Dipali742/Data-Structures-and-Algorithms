class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    int cap;
    int count;
    Node* head;
    Node* tail;
    unordered_map<int, Node*>keyMapping;
    
public: 
    void addAtBeginning(int key, int value) {
        Node* new_node = new Node(key, value);
        new_node->next = head->next;
        head->next->prev = new_node;
        new_node->prev = head;
        head->next = new_node;
        keyMapping[key] = new_node;
    }
    
    void removeNode(int key) {
        Node* toBeRemoved = keyMapping[key];
        toBeRemoved->prev->next = toBeRemoved->next;
        toBeRemoved->next->prev = toBeRemoved->prev;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->count = 0;
        this->cap = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(keyMapping.find(key) == keyMapping.end())
            return -1;
        Node* current = keyMapping[key];
        removeNode(key);
        addAtBeginning(key, current->value);
        return current->value;
    }
    
    void SET(int key, int value)
    {
        if(keyMapping.find(key) == keyMapping.end()) {
            if(count >= cap) {
                int toBeDeletedKey = tail->prev->key;
                removeNode(toBeDeletedKey);
                keyMapping.erase(toBeDeletedKey);
            }
            count++;
        } else {
            removeNode(key);
        }
        addAtBeginning(key, value);
    }
};
