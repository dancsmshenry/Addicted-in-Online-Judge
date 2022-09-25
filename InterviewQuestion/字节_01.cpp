#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 给定一个数 n，如 23121，给定一组数 A，{2, 4, 9}，返回用A可以组成的小于 n 的最大数，A 不为空，答案 22999，
 **/

class Solution {
public:
    int findMax(int number, vector<int> &nums) {
        vector<int> record{};   //  将给定数组按位划分
        for (int i = number; i > 0; i /= 10) {
            record.push_back(i % 10);
        }

        int res = 0;    //  用来存储结果
        bool flag = false;  //  false表示要找小于等于的，true表示要找小于的
        int maxn = nums[max_element(nums.begin(), nums.end()) - nums.begin()];  //  寻找数组的最大值
        
        // 从高位到低位遍历
        for (int i = record.size() - 1; i >= 0; -- i) {
            int mid = find_max(record[i], nums, flag);
            // 对第一个位置的数进行判断，发现当前不存在小于或等于record[i]的数，或小于或等于record[i]的数为0
            if (res == 0 && mid <= 0) {
                for (int j = i - 1; j >= 0; -- j) res = res * 10 + maxn;
                return res;
            }

            if (mid == -1) {    // 不存在小于record[i]的数
                i += 2;
                res /= 10;
                flag = true;
            } else if (mid < record[i]) {   //  只存在小于record[i]的数
                res = res * 10 + mid;
                for (int j = i - 1; j >= 0; -- j) res = res * 10 + maxn;
                return res;
            } else if (mid == record[i]) {  //  存在等于record[i]的数
                res = res * 10 + mid;
                if (res == number) {    //  每一位都取到了等于record[i]的数
                    i += 2;
                    res /= 100;
                    flag = true;
                }
            }
        }
        
        return -1;
    }

private:
    //去arr里面找刚好小于或等于target的数字
    int find_max(int target, vector<int>& arr, bool flag) {
        int res = -1;

        for (auto& num: arr) {
            if (flag == false) {
                if (num <= target) res = max(res, num);
            } else {
                if (num < target) res = max(res, num);
            }
            
        }

        return res;
    }
};

int main() {
    int n1 = 321;
    vector<int> arr = {0};//23113
    Solution s1;
    cout << s1.findMax(n1, arr) << endl;
}