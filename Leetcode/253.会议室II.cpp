/**
 * jd：
 * 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],…] (si < ei)，
 * 为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
*/

class Solution {
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> heap;// 最小堆，越小的越放到前面

        for (auto&& interval: intervals) {
            if (!heap.empty() && head.top() <= interval[0]) {
                heap.pop();
            }

            heap.push(interval[1]);
        }

        return heap.size();
    }
};