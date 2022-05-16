class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int oil = 0;
        int total_oil = 0;
        int station = 0;

        for (int i = 0; i < gas.size(); ++ i) {
            total_oil += (gas[i] - cost[i]);
            oil += (gas[i] - cost[i]);
            if (oil < 0) {
                oil = 0;
                station = i + 1;
            }
        }

        return total_oil < 0 ? -1: station;
    }
};