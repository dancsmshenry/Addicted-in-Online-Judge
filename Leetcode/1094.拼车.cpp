class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> record(1001, 0);

        for (auto&& trip: trips) {
            record[trip[1]] += trip[0];
            record[trip[2]] -= trip[0];
        }

        int sum = 0;
        for (auto&& number: record) {
            sum += number;
            if (sum > capacity) {
                return false;
            }
        }

        return true;
    }
};