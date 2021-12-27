class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        这道题感觉到是用栈来实现两个数组的遍历，但是没有经过训练，不知道从何下手...
        思路：对于其中的每一个矩形来说，我们都往它的左右两端拓展搜索，直到找到那些比当前数小的数，记录下它们的坐标
        然后用左右坐标相减得到矩形的长度，当前点的矩形长度作为高
        然后依次比较
        
        这里有个比较巧妙的位置，就是用栈来寻找那些比当前数要小的数
        一开始，栈没有数字，就只是把当前左边放进去
        然后，有了数字以后就开始操作栈顶，
        如果当前的元素小于栈顶的元素，就把元素弹出，直到栈顶元素大于当前元素
        如果当前的元素大于栈顶的元素，就不操作
        理由：因为我们是要找到那个刚好小于当前数的那个数，记录它的坐标作为矩形的长

        有个问题就是，一直弹出元素，会不会影响后续的元素呢？不会

        如果后面的元素大于前面一个元素，那就直接选这个元素就是了
        如果后面的元素小于前面一个元素，那就把前面一个元素弹出，但是也可以继续使用比前面一个数小的那个数进行判断（因为在前一个元素的时候，踢出的都是比前一个元素还大的数字）
        
        所以，其实弹出元素是不影响的
        栈不是重点，重点是如何维护栈....（只有通过发现题目数据的特性才能够维护好....）
        */

        stack<int> s1, s2;
        vector<int> left(heights.size() + 1, 0), right(heights.size() + 1, 0);

        for (int i = 0; i < heights.size(); i ++ ){
            while (!s1.empty() && heights[s1.top()] >= heights[i]){
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();//理由同下
            s1.push(i);
        }

        for (int i = heights.size() - 1; i >= 0; i -- ){
            while (!s2.empty() && heights[s2.top()] >= heights[i]){
                s2.pop();
            }
            right[i] = s2.empty() ? heights.size() : s2.top();//栈为空，就表明右边的所有的数都大于第i个数，所以返回heights.size()
            s2.push(i);
        }

        int maxn = 0;
        for (int i = 0; i < heights.size(); i ++ ){
            maxn = max(maxn, ((right[i] - i) + (i - left[i]) - 1) * heights[i]);
        }

        return maxn;
    }
};