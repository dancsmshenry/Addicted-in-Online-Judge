class Solution {
public:
    int thirdMax(vector<int>& nums){
        //题目有个小坑，它的第三大的数，是指所有不同数字中排第三大的数
        vector<long> f(3, LONG_MIN);//注意到可能会取值为INT_MIN

        for (auto num: nums){
            if (num > f[0]){
                f[2] = f[1];
                f[1] = f[0];
                f[0] = num;
            }else if (num < f[0] && f[1] < num){
                f[2] = f[1];
                f[1] = num;
            }else if (num < f[1] && f[2] < num){
                f[2] = num;
            }
        }

        return f[2] == LONG_MIN ? f[0] : f[2];//如果当前只有两个数的话，那么就返回最大的那一个
    }
};