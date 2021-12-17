class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
    public:
        Node():key(0), value(0), prev(nullptr), next(nullptr){}
        Node(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
    int size;
    int capacity;

public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
        this -> size = 0;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)){
            return -1;
        }

        Node* node = cache[key];
        moveToHead(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)){
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            this -> size ++ ;
            if (this -> size > this -> capacity){
                Node* node = removeTail();
                this -> size -- ;
                cache.erase(node -> key);
                delete node;
            }
        }else{
            Node* node = cache[key];
            node -> value = value;
            moveToHead(node);
        }
    }

    void addToHead(Node* node){
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }

    void removeNode(Node* node){
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
    }

    void moveToHead(Node* node){
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail(){
        Node* node = tail -> prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */