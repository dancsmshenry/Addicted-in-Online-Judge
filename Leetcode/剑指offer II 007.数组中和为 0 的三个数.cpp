class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> res;

       int n = nums.size();
       for (int i = 0; i < n; i ++ ){
           if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
           if (nums[i] > 0) break;//如果都大于0了，就不用遍历了
           int left = i + 1, right = n - 1;//双指针
           while (left < right){
               if (nums[i] + nums[left] + nums[right] == 0){
                   res.push_back((vector<int>){nums[i], nums[left], nums[right]});
                   while (right > left && nums[ ++ left] == nums[left - 1]) ;//去重
                   while (right > left && nums[ -- right] == nums[right + 1]) ;//去重
               }else if (nums[i] + nums[left] + nums[right] < 0){
                   while (right > left && nums[ ++ left] == nums[left - 1]) ;//去重
               }else{
                   while (right > left && nums[ -- right] == nums[right + 1]) ;//去重
               }
           }
       }

       return res;
    }
};