#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 题干：将字符串s1修改为s2，接着给出插入字符，删除字符，修改字符的代价，寻求最小代价（本质上就是编辑距离）

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int a, b, c; // 分别表示插入的代价，删除的代价，修改的代价
    cin >> a >> b >> c;

    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++ i) {
        dp[i][0] = b * i;
    }

    for (int j = 0; j <= m; ++ j) {
        dp[0][j] = a * j;
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            int temp = min(dp[i][j - 1] + a, dp[i - 1][j] + b); // 第一个表示在s1后面插入一个新值，第二个表示删除s1最后的一个值
            if (s1[i - 1] == s2[j - 1]) {
                temp = min(temp, dp[i - 1][j - 1]);
            }
            dp[i][j] = min(dp[i - 1][j - 1] + c, temp); // 当前对应的值不同，需要修改
        }
    }

    cout << dp[n][m] << endl;
}