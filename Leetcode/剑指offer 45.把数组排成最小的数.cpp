class Solution {
public:
    string minNumber(vector<int>& nums) {
        /*        
        大前提：将数组排序后再全部加在一起
        所以这道题的思路就是，将数组转换为字符串数组，然后进行排序，然后再全部加起来
        排序规则：如果x + y > y + x，则说明x > y
        */
        vector<string> str;
        for (const int& i: nums){
            str.push_back(to_string(i));
        }
        quick_sort(str, 0, str.size() - 1);
        
        string result = "";
        for (const string& s1: str){
            result += s1;
        }

        return result;
    }

    void quick_sort(vector<string>& str, int left, int right){
        if (left >= right){
            return ;
        }

        int i = left - 1, j = right + 1;
        string temp = str[left];
        while (i < j){
            do i ++ ; while (temp + str[i] > str[i] + temp);
            do j -- ; while (str[j] + temp > temp + str[j]);
            if (i < j) swap(str[i], str[j]);
        }

        quick_sort(str, left, j);
        quick_sort(str, j + 1, right);
    }
};