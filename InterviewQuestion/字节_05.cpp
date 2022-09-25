#include <iostream>
#include <vector>

using namespace std;

/*
jd：一个自然数数组，数组里连续相邻的数都减一算一次操作，问最少多少次操作能把所有数减到0

背景：如果一连串的数字的差值是正数的话（这里的差值是从左往右的，即右边数字和左边数字的差值），那么要把这些数字全部都减到0的次数应该是这些差值全部相加
PS：这里的前提是最左边是0
那如果中间出现了负数怎么办？
答：不用管他，因为当你把位于正数的数字清零之前，这个数就已经被清零的
解法：在最前面加上0，然后计算相邻项的差值，大于0就相加
*/

int solve(vector<int>& arrs) {
    arrs.insert(arrs.begin(), 0);
    int n = arrs.size();
    int res = 0;
    for (int i = 1; i < n; ++ i) {
        if (arrs[i] > arrs[i - 1]) {
            res += (arrs[i] - arrs[i - 1]);
        }
    }

    return res;
}

int main() {
    vector<int> arrs{1, 2, 3, 0, 8, 7, 2};
    cout << solve(arrs) << endl;
}