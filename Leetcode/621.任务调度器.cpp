class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks){
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;

        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        /*
            这道题的理论很深，需要慢慢理解
            首先，我们找到最多执行次数的那个任务，并找到同样执行这么多次数的任务的个数

            对于这些任务，我们把它平铺到每一个桶当中
            
            不过，注意这里最后一个桶后续是不用等待时间的，所以就直接加上最多执行次数的任务的次数就可以了
            所以就是(maxExec) * (n + 1)
            但是吧，对于最后一个桶来说，它只要完成了这个次数（最多执行次数的任务的次数）就可以了，后续就不用等待了
            所以应该是(maxExec - 1) * (n + 1) + maxCount

            但是这里有一个特殊情况["A","A","A","B","B","B", "C","C","C", "D", "D", "E"]2，这里的答案是12
            又应该如何解释呢？
            关键点就在这，因为后面的元素其实是不够3个的（3是最多执行次数任务的次数），但其实啊，它不够，但是可以把它单独放到每个桶的最后面，那就相当于是没有空闲的时间了
            所以就直接等于tasks的长度了
            说白了，为什么会出现时间长度大于任务队列长度的情况，就是因为最多执行次数的任务的次数没有满上n+1的值，导致了空闲的时间，而这个空闲时间有没有被其他的零散的任务给用上（没有这样的任务）
            所以才导致空闲时间的，像刚才那个例子，如果任务的长度大于等于n+1，那就不会有空闲的了，那就直接返回size即可
        */
        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};