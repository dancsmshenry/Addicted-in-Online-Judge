class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            if (arr[left] == target) {
                return left;
            }
            int mid = left + (right - left) /2;
            if (target == arr[mid]) {
                right = mid;
            } else if (arr[mid] > arr[left]) {
                if (target < arr[mid] && target >= arr[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (arr[mid] < arr[left]) {
                if (target <= arr[right] && target > arr[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left ++ ;
            }
        }

        return -1;
    }
};