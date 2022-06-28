class RandomizedSet {
private:
    unordered_map<int, int> hashmap{};
    vector<int> arr{};
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.count(val)) {
            return false;
        }
        arr.push_back(val);
        hashmap[val] = arr.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!hashmap.count(val)) {
            return false;
        }
        swap(arr[arr.size() - 1], arr[hashmap[val]]);
        hashmap[arr[hashmap[val]]] = hashmap[val];
        arr.pop_back();
        hashmap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */