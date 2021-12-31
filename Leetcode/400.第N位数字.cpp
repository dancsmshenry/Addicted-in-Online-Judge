class Solution {
public:
    //解法一
    int findNthDigit(int n) {
        // 计算该数字是由多少位组成的，并记录到digits当中，同时也要缩减n的范围
        long base = 9, digits = 1;
        while (n - base * digits > 0){
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数连成的序列的第n个数字，idx计算要求的数，是digits位数的第几位
        if (idx == 0) idx = digits;// 如果是第0位，就把idx设为digits
        /*举个例子，如果当前的n是177，那么177/3得到的就是59，可是，三位数是从100开始数数的，所以应该对应的是158的第三位，即8
        而如果是176/3的话，得到的是58，这里，虽然是从100开始数的，但是数到了157，后面还要再加上2个，所以就变成了158了*/

        //下面两行可以认为是填满基数，即是三位数吗，所以就要得到一个100
        long number = 1;
        for (int i = 1; i < digits; i ++ ) number *= 10;

        //这一行可以认为是一种修正，即如果idx==digits，就证明idx原来要得到的是第0位，所以除以后得到的数就应该要减一（参考上面的解释）
        //如果不等于，就证明得到的不是第0位，就直接除以即可
        number += (idx == digits ? n / digits - 1 : n / digits);

        // 从真实的数字中找到我们想要的那个数字
        for (int i = idx; i < digits; i ++ ) number /= 10;
        /*解释：如果上面是要求第0位（即mod后的结果是0），那么就直接mod 10就可以得到结果了
        如果不是第0位（即mod后的结果不是0），那么就要一个一个除，然后再mod 10*/
        return number % 10;
    }

    //解法二
    // int findNthDigit(int n) {
    //     n -- ;

    //     for (long digits = 1; digits < 11; digits ++ ){
    //         int first_num = pow(10, digits-1);
    //         if (n < 9 * first_num * digits){
    //             return int(to_string(first_num + n / digits)[n % digits]) - '0';
    //         }
    //         n -= (9 * first_num * digits);
    //     }

    //     return 0;
    // }
};