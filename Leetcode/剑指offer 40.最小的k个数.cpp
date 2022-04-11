class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if (k == n) {
            return arr;
        }
        quick_sort_k(arr, 0, n - 1, k);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }

    void quick_sort_k(vector<int>& arr, int left, int right, int k) {
        if (left >= right) {
            return ;
        }

        int mid = arr[left], l = left - 1, r = right + 1;
        while (l < r) {
            do l ++ ; while (arr[l] < mid);
            do r -- ; while (arr[r] > mid);
            if (l < r) swap(arr[l], arr[r]);
        }

        if (r + 1 < k) {
            quick_sort_k(arr, r + 1, right, k);
        } else if (r + 1 > k) {
            quick_sort_k(arr, left, r, k);
        }
    }
};