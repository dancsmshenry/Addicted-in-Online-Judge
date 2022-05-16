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
            // ���ﲻ�ܱȽϺ�һ����һ��Ҫ�ȽϺ�������С����һ��
            // ԭ��123675������5��7С���������������ʱ��Ҫ��6��λ�ÿ�ʼ����
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