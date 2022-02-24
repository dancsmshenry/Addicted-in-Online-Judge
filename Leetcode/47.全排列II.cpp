class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans(22, 0);

        for (int i = 0; i < nums.size(); i ++ ) {
            ans[nums[i] + 10] ++ ;
        }
        
        vector<int> nullvector;
        solve(ans, nullvector);
        return res;
    }

    void solve(vector<int>& ans, vector<int>& res1) {
        if (res1.size() == ans.size()) {
            res.push_back(res1);
        }

        for (int i = 0; i < ans.size(); i ++ ) {
            if (ans[i] > 0) {
                res1.push_back(i - 10);
                ans[i] -- ;
                solve(ans, res1);
                ans[i] ++ ;
                res1.pop_back();
            }
        }
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, 0);

        return result;
    }

    void solve(vector<int> nums, int begin) {//为什么这里不是引用，因为我们两次swap才能将数组恢复到原来的样子，而现在只有一次swap，如果用引用的话就会越搞越乱...（比如说：第begin的位置是5，，但是再begin后面可能6，注意此时6可能已经出现过再第i个位置了，比如前面排序过，而引用传递会把顺序都弄乱了，导致begin和值是6的地方又出现了一次交换，就会发生重复了...）
        if (begin == n) {//n和n-1都是一样的
            result.push_back(nums);
            return ;
        }

        for (int i = begin; i < n; ++ i) {
            if (i != begin && nums[i] == nums[begin]) {
                continue;
            }
            swap(nums[begin], nums[i]);
            solve(nums, begin + 1);
            //为什么这里不再来一次交换，因为比如1122，我第一个1和第一个2交换以后，得到2112，进行solve；solve后再一次交换的话，就会变为1122；接着再将第一个1和第二个2交换，又变为了2112了...；这样即使前面想要去重也去重不了
        }
    }
};