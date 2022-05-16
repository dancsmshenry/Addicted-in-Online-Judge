class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        int maxn = 0;

        for (int& i: nums){
            hash.insert(i);
        }

        for (int& i: nums){
            if (!hash.count(i - 1)){
                int number1 = 1, number2 = i + 1;
                while (hash.count(number2)){
                    number1 ++ ;
                    number2 ++ ;                   
                }
                maxn = max(maxn, number1);
            }
        }

        return maxn;
    }
};

// 用空间换时间
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int& num: nums) {
            hashmap[num] = 1;
        }

        int res = 0;
        for (int &i: nums) {
            if (!hashmap.count(i)) continue;
            int number = i + 1;
            while (hashmap.count(number)) {
                hashmap[i] += hashmap[number];
                hashmap.erase(number);
                ++ number;
            }
            res = max(res, hashmap[i]);
        }

        return res;
    }
};