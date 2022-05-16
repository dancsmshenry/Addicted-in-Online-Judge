class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int n = array.size();
        vector<int> res {-1, -1};
        if (n < 2) {
            return res;
        }
        
        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; -- i) {
            // 这里不能比较后一个，一定要比较后面中最小的那一个
            // 原因：123675，这里5比7小，但是重新排序的时候要从6的位置开始排序
            if (array[i] > currMin) {
                res[0] = i;
            } else {
                currMin = min(currMin, array[i]);
            }
        }

        int currMax = INT_MIN;
        for (int i = 0; i < n; ++ i) {
            if (array[i] < currMax) {
                res[1] = i;
            } else {
                currMax = max(currMax, array[i]);
            }
        }

        return res;
    }
};