class Node {
    public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(int key , int data) {
        this->key = key;
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> mpp;
    Node* head = new Node(-1,-1) ;
    Node* tail = new Node(-1,-1);
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mpp.size() || mpp.find(key) == mpp.end() ) return -1;
        Node* temp = mpp[key];
        Node* newNode = new Node(key,temp->data);
        remove(temp);
        insert(newNode);
        return newNode->data;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key,value);
        if(mpp.find(key) != mpp.end()) {
            remove(mpp[key]);
            insert(newNode);
            return;
        }
        if(mpp.size() == capacity) remove(tail->prev);
        insert(newNode);
    }

    private:
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        mpp[node->key] = node;
    }
    void remove(Node* node) {
        Node* previous = node->prev;
        Node* nex = node->next;
        previous->next = nex;
        nex->prev = previous;
        mpp.erase(node->key);
    }
};
