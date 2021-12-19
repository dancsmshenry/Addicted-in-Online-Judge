class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //只有一个人的时候，他就是法官了.....
        if (n == 1){
            return 1;
        }
        unordered_map<int, int> hash;
        vector<int> res;

        for (int i = 0; i < trust.size(); i ++ ){
            hash[trust[i][1]] ++;
            if (hash[trust[i][1]] == n - 1){
                res.push_back(trust[i][1]);
            }
        }

        if (res.size() == 1){
            for (vector<int>& a:trust){
                if (a[0] == res[0]){
                    return -1;
                }
            }
            return res[0];
        }

        return -1;
    }
};