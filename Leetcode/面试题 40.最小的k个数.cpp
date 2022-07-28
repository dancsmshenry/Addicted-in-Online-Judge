class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort_k(arr, 0, arr.size() - 1, k);

        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void quick_sort_k(vector<int>& arr, int left, int right, int k) {
        if (left >= right) {
            return ;
        }

        int i = left - 1, j = right + 1, mid = arr[left];
        while (i < j) {
            do ++ i; while (arr[i] < mid);
            do -- j; while (arr[j] > mid);
            if (i < j) swap(arr[i], arr[j]);
        }

        if (j > k - 1) {
            quick_sort_k(arr, left, j, k);
        } else if (j < k - 1) {
            quick_sort_k(arr, j + 1, right, k);
        }
    }
};