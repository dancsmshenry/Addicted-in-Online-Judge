#include <bits/stdc++.h>

using namespace std;

// 这几行代码可以使得 cin cout 的速度和 scanf printf 大致一样快
// 普通的 cin cout 会比 scanf printf 慢非常多
void fast_read() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_read();

    // 读入整个数组为一个字符串
    string array{};
    cin >> array;
    // 将整个字符串拆分成各个数
    vector<string> nums;
    for (int i = 1, j = 1; j < array.size(); ++ j) {
        if (array[j] == ',' || array[j] == ']') {
            string num = array.substr(i, j - i);
            nums.push_back(num);
            i = j + 1;
        }
    }
    // 按自定义规则排序
    sort(nums.begin(), nums.end(), [&](const string& a, const string& b){
        return a + b > b + a;
    });
    // 打印结果
    string res{};
    for (auto& num : nums) {
        res += num;
    }

    cout << res << endl;
    return 0;
}