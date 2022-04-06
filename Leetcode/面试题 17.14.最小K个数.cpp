class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == arr.size()) {
            return arr;
        }
        quicksort_k(arr, 0, arr.size() - 1, k);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }

    void quicksort_k(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int left = l - 1, right = r + 1, mid = arr[l];

        while (left < right) {
            do left ++ ; while (arr[left] < mid);
            do right -- ; while (arr[right] > mid);
            if (left < right) swap(arr[left], arr[right]);
        }

        if (right + 1 > k) {
            quicksort_k(arr, l, right, k);
        } else if (right + 1 < k){
            quicksort_k(arr, right + 1, r, k);
        }
    }
};