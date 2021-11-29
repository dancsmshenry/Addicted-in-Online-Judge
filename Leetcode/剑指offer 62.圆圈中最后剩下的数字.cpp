class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
            方法二：搭建环形链表，逐个逐个元素踢出
        */
        /*方法一：用数组模拟，每踢出一个就用数组记录一下（超时了）
        int f[n];
        for (int i = 0; i < n; i ++ ){
            f[i] = i;
        }
        
        int j = 0, mid = 0, count = 0;
        while(mid < n - 1){
            if (f[j] != -1){
                count ++ ;
                if (count == m){
                    f[j] = -1;
                    count = 0;
                    mid ++ ;
                }
            }
            j ++ ;
            j = (j > n - 1 ? 0 : j);
        }

        for (int i = 0; i < n; i ++ ){
            if (f[i] != -1){
                return i;
            }
        }

        return 0;
        */

        /*方法三：用递归实现*/
        /*
            如果只有一个数字，那么就直接返回该数字
        */
        if (n == 1){
            return 0;
        }else{
            /*
                理解一个递推公式：old = (new + m) % n（前提是坐标是从0开始）
                即新的坐标加上m就是原坐标（注意，因为是从0开始，所以要删除第m个元素的时候，删除的是坐标为m-1的元素）
                当新的坐标超过了总长度n的时候，就要再回头数起，所以要mod n

                有了公式以后，就理解一下递归的思路：
                假设我要找的点为a1，我们要返回的是这个点在第一次数组中出现的位置
                那么我们知道他最后一个点的坐标是0
                那么它的上一次位置坐标是什么，就可以用递归公式得出了
                所以不断的往上递归，就出现了该数在第一次数组中出现的位置了
            */
            return (lastRemaining(n - 1, m) + m) % n;
        }
    }
};