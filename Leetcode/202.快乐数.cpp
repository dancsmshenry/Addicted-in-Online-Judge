class Solution {
public:
    bool isHappy(int n){
        int slow = n, fast = n;
        do{
            slow = check(slow);
            fast = check(fast);
            fast = check(fast);
        }while(slow != fast);
        
        return slow == 1;
    }

    /*
        这道题的关键就是，如果数字一直操作后无法得到1的话，就会陷入一个死循环里面
        那么，如果出现了循环，那就可以用快慢指针来实现
        就快慢指针重合了的话，那么就退出循环
        这里注意，一旦出现了1的话，那么slow=fast=1
        所以最后只要判断slow是不是1就可以了
    */

    int check(int n){
        int res = 0;
        while (n > 0){
            int num = n % 10;
            res += num * num;
            n /= 10;
        }
        return res;
    }
};