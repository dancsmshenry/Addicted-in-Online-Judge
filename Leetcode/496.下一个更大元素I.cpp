class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack01;
        unordered_map<int, int> pair;
        vector<int> result;
        
        /*维护一个栈，越往上面数值越小，如果遇到大于栈顶的，就把栈顶加入到hash中，同时踢出栈顶，然后不断的这样踢出去*/
        for (int &i: nums2){
            if (!stack01.empty() && i > stack01.top()){
                while(!stack01.empty() && i > stack01.top()){
                    pair[stack01.top()] = i;
                    stack01.pop();
                }
            }
            stack01.push(i);
        }

        /*如果栈不是空的话，就要把这些数设为-1*/
        while (stack01.size() != 0){
            pair[stack01.top()] = -1;
            stack01.pop();
        }

        for (int &i: nums1){
            result.push_back(pair[i]);
        }

        return result;
    }
};