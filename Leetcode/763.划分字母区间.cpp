class Solution {
public:
    vector<int> partitionLabels(string s) {
        //这里用到的是贪心的做法，因为我们要分割得到的片段是同一字母最多出现在一个片段中，所以对于这个片段的字母，有一个限制，就是这个字母最后出现的位置，必定是在这个片段内的；所以我们就可以模拟这样一个过程：首先将每个字母最后一个出现的位置给记录下来，然后设置begin和end，开始遍历字符串，end表示区间的末尾，begin表示区间的头部，end每次更新，都是区间中字母出现的最后一个位置，如果在某次更新后，发现end就是当前字母最后一次出现的地方，这说明，对于前面的字母，他们出现的位置都是在end或end之前的位置，那么就可以组成一个区间，同时更新begin的位置
        vector<int> f(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i ++ ) {
            f[s[i] - 'a'] = i;
        }
        vector<int> res;

        int begin = 0, end = 0;
        for (int i = 0; i < n; i ++ ) {
            end = max(end, f[s[i] - 'a']);
            if (end == i) {
                res.push_back(end - begin + 1);
                begin = end + 1;
            }
        }

        return res;
    }
};