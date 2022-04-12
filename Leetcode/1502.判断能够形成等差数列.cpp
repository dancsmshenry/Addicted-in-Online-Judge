class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> hashmap;
        int imin = INT_MAX, imax = INT_MIN;
        int n = arr.size();

        for (auto& num: arr) {
            imin = min(imin, num);
            imax = max(imax, num);
            hashmap.insert(num);
        }

        
        if ((imax - imin) % (n - 1) != 0) {
            return false;
        }
        
        int count = (imax - imin) / (n - 1);
        while (imin != imax) {
            imin += count;
            if (!hashmap.count(imin)) {
                return false;
            }
        }

        return true;
    }
};