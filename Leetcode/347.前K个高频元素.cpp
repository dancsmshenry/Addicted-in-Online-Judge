class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res{};
        unordered_map<int, int> hashmap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p; //   pair的第一个数是出现的次数，第二个数是数字本身

        for (const auto& num: nums) {
            ++ hashmap[num];
        }

        for (const auto& pair: hashmap) {
            p.push({pair.second, pair.first});
            if (p.size() > k) {
                p.pop();
            }
        }

        while (!p.empty()) {
            res.push_back(p.top().second);
            p.pop();
        }

        return res;
    }
};


// 方法二
bool cmp2(pair<int, int>a, pair<int, int> b) {
    return a.second > b.second;//对于second的升序
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*把数字放入到键值对里面*/
        map<int, int> hash;
        for (int i:nums){
            hash[i] ++ ;
        }

        /*因为map无法排好序，所以用vector<pair<int, int>>对其进行排序*/
        vector<pair<int, int>> vecs;
        for (auto it = hash.begin(); it!= hash.end(); it ++ ){
            vecs.push_back(make_pair(it->first, it->second));
        }
        sort(vecs.begin(), vecs.end(), cmp2);

        /*选出其中的topk个*/
        vector<int> result;
        for (int i = 0; i < k; i ++ ){
            result.push_back(vecs[i].first);
        }
        return result;
    }
};