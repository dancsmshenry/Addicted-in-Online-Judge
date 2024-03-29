class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /**
        首先假设有一个幂集（总共有n个元素），我现在想再加一个元素进去，那么请问现在幂集变为了多少？
        应该是原来的个数再乘以2是吧（这个其实从公式的推到上就可以看出来了）（而实际上，就是原来的幂集（没有这个新的数）加上新的幂集（有这个新的数））

        而就是这一点给了启发，既然每加一个元素都会使原来幂集的数量扩至原来的两倍
        那我只要模拟这个过程，维护一个“部分数列”，那么每添加一个数，就插入一个有这个新的数字的“部分数组”
        不断的重复这个过程，最终就是答案！
        **/
        vector<vector<int>> res{};
        vector<int> temp{};
        res.push_back(temp);
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            int length = res.size();
            for (int j = 0; j < length; ++ j) {
                temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};