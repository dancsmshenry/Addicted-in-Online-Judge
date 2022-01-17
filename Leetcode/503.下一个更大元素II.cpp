class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //一眼用栈来解决问题
        vector<int> res(nums.size(), -1);
        stack<int> s1;
        for (int i = 0, n = nums.size(); i <= n * 2; i ++ ){
            while (!s1.empty() && nums[i % n] > nums[s1.top()]){
                res[s1.top()] = nums[i % n];
                s1.pop();
            }
            s1.push(i % n);
        }

        return res;
    }
};