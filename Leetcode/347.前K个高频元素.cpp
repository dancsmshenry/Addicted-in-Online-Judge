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