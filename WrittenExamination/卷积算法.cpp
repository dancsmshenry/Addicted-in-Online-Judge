#include <iostream>
#include <vector>

using namespace std;

void init(vector<vector<int>>& arr, int n, int m) {
    int temp{};
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            cin >> temp;
            arr[i][j] = temp;
        }
    }
}

int main() {
    int M, N, K, L;
    cin >> M >> N >> K >> L;
    vector<vector<int>> arr1(M, vector<int>(N, 0)); // 原矩阵
    vector<vector<int>> arr2(K, vector<int>(L, 0)); // 卷积核矩阵
    init(arr1, M, N);
    init(arr2, K, L);
    int t1 = K / 2, t2 = L / 2;
    
    vector<vector<int>> res(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++ i) {
        for (int j = 0; j < N; ++ j) {
            int left = 0, right = 0, top = 0, down = 0;
            while (j + left >= 0 && t2 + left >= 0) -- left;
            while (j + right < N && t2 + right < L) ++ right;
            while (i + top >= 0 && t1 + top >= 0) -- top;
            while (i + down < M && t1 + down < K) ++ down;
            for (int i1 = top + 1; i1 < down; ++ i1) {
                for (int j1 = left + 1; j1 < right; ++ j1) {
                    res[i][j] += arr1[i + i1][j + j1] * arr2[t1 + i1][t2 + j1];
                }
            }
        }
    } 
    
    for (auto& a1: res) {
        for (auto& a: a1) {
            if (a < 0) cout << 0 << " ";
            else if (a > 255) cout << 255 << " ";
            else cout << a << " ";
        }
        cout << endl;
    }
}