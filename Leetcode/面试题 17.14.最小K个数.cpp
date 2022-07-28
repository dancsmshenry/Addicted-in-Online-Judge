class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (true) {
            if (left >= right) {
                break;
            }
            int i = left - 1, j = right + 1, mid = arr[left];
            while (i < j) {
                do ++ i; while (arr[i] < mid);
                do -- j; while (arr[j] > mid);
                if (i < j) swap(arr[i], arr[j]);
            }

            if (j > k - 1) {
                right = j;
            } else if (j < k - 1) {
                left = j + 1;
            } else if (j == k - 1) {
                break;
            }
        }

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};