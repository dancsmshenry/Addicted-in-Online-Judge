struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    /*init*/
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        /*
            使用伪头部和伪尾部节点，方便后续结点的添加和删除
            因为还没有结点，所以先两个结点相连
        */
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head -> next = tail;
        tail -> prev = head;
    }

    /*获取key*/
    int get(int key) {
        /*如果key不存在，就返回-1*/
        if (!cache.count(key)) {
            return -1;
        }

        /*如果key存在，先通过哈希表定位，然后把结点移到头部*/
        DLinkedNode* node = cache[key];
        moveToHead(node);

        return node->value;
    }
    
    /*插入结点key和value*/
    void put(int key, int value) {
        if (!cache.count(key)) {
            /*如果 key 不存在，创建一个新的节点*/
            DLinkedNode* node = new DLinkedNode(key, value);
            /*结点添加进哈希表*/
            cache[key] = node;
            /*结点添加至双向链表的头部*/
            addToHead(node);
            /*链表长度增加*/
            size ++ ;
            /*如果超出容量，删除双向链表的尾部节点，删除hash中对应的项*/
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed -> key);
                /*防止内存泄漏*/
                delete removed;
                size -- ;
            }
        }
        else {
            /*如果key存在，先通过哈希表定位，然后更新value的值，接着把结点移到头部*/
            DLinkedNode* node = cache[key];
            node -> value = value;
            moveToHead(node);
        }
    }

    /*添加结点到头结点的位置*/
    void addToHead(DLinkedNode* node) {
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }
    
    /*删除结点*/
    void removeNode(DLinkedNode* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    /*将该结点放置头结点的位置*/
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    /*删除最后一个结点*/
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail -> prev;
        removeNode(node);
        return node;
    }
};