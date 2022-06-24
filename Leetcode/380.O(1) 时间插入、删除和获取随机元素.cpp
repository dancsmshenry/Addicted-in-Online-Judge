class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (hashmap.count(val)) {
            return false;
        }
        nums.push_back(val);
        hashmap[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!hashmap.count(val)) {
            return false;
        }
        swap(nums[nums.size() - 1], nums[hashmap[val]]);
        hashmap[nums[hashmap[val]]] = hashmap[val];
        nums.pop_back();
        hashmap.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> hashmap;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */