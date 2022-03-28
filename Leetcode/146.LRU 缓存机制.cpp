struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }

        Node *node = cache[key];
        move_to_head(node);
        
        return node -> value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            Node *node = new Node(key, value);
            cache[key] = node;
            add_to_head(node);
            ++ size;
            if (size > capacity) {
                Node *removed = remove_tail();
                cache.erase(removed -> key);
                delete removed;
                -- size;
            }
        } else {
            Node *node = cache[key];
            node -> value = value;
            move_to_head(node);
        }
    }
    
    void add_to_head(Node *node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    void remove_node(Node *node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void move_to_head(Node *node) {
        remove_node(node);
        add_to_head(node);
    }

    Node* remove_tail() {
        Node* node = tail -> prev;
        remove_node(node);
        return node;
    }
};