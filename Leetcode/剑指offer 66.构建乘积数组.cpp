class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) {
            return {};
        }
        vector<int> left(n, a[0]), right(n, a[n - 1]);
        vector<int> res(n, 0);

        for (int i = 1; i < n; ++ i) {
            left[i] = left[i - 1] * a[i];
        }
        for (int i = n - 2; i >= 0; -- i) {
            right[i] = right[i + 1] * a[i];
        }

        for (int i = 0; i < n; i ++ ) {
            if (i == 0) res[i] = right[i + 1];
            else if (i == n - 1) res[i] = left[i - 1];
            else res[i] = right[i + 1] * left[i - 1];
        }

        return res;
    }
};

//最佳的方法
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if (n == 0) {
            return {};
        }
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++ i) {
            res[i] = res[i - 1] * a[i - 1];
        }

        int temp = a[n - 1];
        for (int i = n - 2; i >= 0; -- i) {
            res[i] *= temp;
            temp *= a[i];
        }

        return res;
    }
};