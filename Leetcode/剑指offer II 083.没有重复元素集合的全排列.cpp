class Solution {
private:
    vector<vector<int>> res{};
    int n{};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int begin) {
        if (begin == n - 1) {// 这里是n-1还是n都是可以的
            res.push_back(nums);
            return ;
        }

        for (int i = begin; i < n; ++ i) {
            swap(nums[i], nums[begin]);
            dfs(nums, begin + 1);
            swap(nums[i], nums[begin]); //  这里一定要换回来，否则的话，就会出现重复的情况
            // 如果没有上面这一行的话，
            // 比如说对于数据1 2 3，将1和1换位了，变为了1 2 3
            // 然后进入下一层的dfs，一直到最后一层dfs，好像都没有啥问题
            // 但，上述只是进入的dfs只进行一次for循环的时候（得到 1 2 3）
            // 如果倒数第二个dfs进入第二层循环（后续会得到1 3 2）
            // 再返回第一层循环，此时会交换3和1，即得到3 1 2
            // 进入此时的第二层循环（后续会一次输出3 1 2和 3 2 1）
            // 问题来了，此时是3 2 1，而此时要和最后一次进行交换，就会变成了 1 2 3
            // 重蹈覆辙了属于是
            // 简述：如果不交换回来的话，一开始位于前面的数会因为深层的dfs而被移动到后面，而当前层次的循环在遍历
            // 到后面数字的时候又会把它交换回前面，从而造成重复

            // 还有一种解决方式，就是为了防止后续的dfs影响，给数组实际上传入的就不能是引用，而是传值了，参考46全排序
            // 的第二种做法
        }
    } 
};