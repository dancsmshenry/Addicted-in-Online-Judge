class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*靠，这道题的思路我差不多都想齐了，就是对于一个点来说，它可以把它下面所有的点都算进去，然后把算进去的点给删除掉，但就是脑子抽了，不知道到底该如何实现.....*/
        /*bug处理：
        第一次bug：没有考虑到nums.size()=0的情况
        第二次bug：如果数据发生了重复，那么就会出现问题：比如说，第一次出现的时候，我就把它后面的所有数字都删除了；导致第二次该数字再次出现的时候
        ，造成该数字后面没有数字的情况
        第三次bug：超时，没有仔细考虑时间复杂度的情况.......*/
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