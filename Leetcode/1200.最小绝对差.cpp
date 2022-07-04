class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int count = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; ++ i) {
            if (arr[i + 1] - arr[i] < count) {
                count = arr[i + 1] - arr[i];
                res = {{arr[i], arr[i + 1]}};
            } else if (arr[i + 1] - arr[i] == count) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};