class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;

        for (int i = 1; i < n; ++ i) {
            if (ratings[i] >= ratings[i - 1]) {
                //如果一直是递增的序列的话
                dec = 0;//重置下降序列的长度
                pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1;//如果比前面大，就是pre+1;否则就是1（这里是个很贪心的技巧，因为只是要求相邻的孩子高的糖果多）
                ret += pre;//加上当前长度
                inc = pre;//统计上升序列的长度
            } else {
                dec++;//统计下降序列的长度
                if (dec == inc) {
                    dec++;
                }//这一步非常的精髓，首先是他统计了这个下降序列的长度，如果该下降序列的长度大于前面上升序列的长度，就把后面下降序列的每一位都加一
                //所以inc实际上是统计了上升序列的长度的
                ret += dec;//有多少下降的数字就加多少（有一个，就加一，有两个，就加1+2，有三个，就加1+2+3）
                pre = 1;//重置上升序列的长度
            }
        }

        return ret;
    }
};