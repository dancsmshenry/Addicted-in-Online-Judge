#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分查找，有重复数字，返回目标数字第一次出现的位置下标
 * 
*/

int solve(int target, vector<int>& arrs) {
    int n = arrs.size();
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arrs[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,6,7,8,9};
    cout << solve(1, arr) << endl;
}