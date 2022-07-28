class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> record(n + 2, 0);
        for (auto&& booking: bookings) {
            record[booking[0]] += booking[2];
            record[booking[1] + 1] -= booking[2];
        }

        vector<int> res(n, 0);
        res[0] = record[1];
        for (int i = 1; i < n; ++ i) {
            res[i] = res[i - 1] + record[i + 1];
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> record(n + 2, 0);

        for (auto& booking: bookings) {
            record[booking[0]] += booking[2];
            record[booking[1] + 1] -= booking[2];
        }

        vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; ++ i) {
            res[i] = record[i] + res[i - 1];
        }

        res.erase(res.begin());
        return res;
    }
};