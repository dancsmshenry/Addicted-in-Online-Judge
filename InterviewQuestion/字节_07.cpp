#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// JD:给定一系列任务的执行起始时间和结束时间，求最多有多少个任务同时执行

// 假设这里的开始时间都是从0开始的
int solve(vector<vector<int>>& arrs) {
    int maxn = 0;
    int n = arrs.size();
    for (int i = 0; i < n; ++ i) {
        maxn = max(maxn, arrs[i][1]);
    }

    vector<int> temp(maxn + 2, 0);
    for (auto& arr: arrs) {
        ++ temp[arr[0]];
        -- temp[arr[1] + 1];
    }

    int count{}, days{};
    for (int i = 1; i <= maxn; ++ i) {
        if (i != 0) {
            temp[i] += temp[i - 1];
        }
        if (count < temp[i]) days = i;
    }

    return days;
}

int main() {

}