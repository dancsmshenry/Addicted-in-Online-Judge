class Solution {
public:
    int countDigitOne(int n) {
        //注意，如果一个数是longlong，另一个数是int，那么他们相互处理后，得到的是int...
        long long n1 = n, t = 1;
        long long result = 0;

        while (n1 > 0){
            /*number1是获得当前数字之前的数字，number2是当前数字，number3是当前数字之后的数字
            例如12345，如果当前数字是3，那么number1就是12，number3就是45*/
            long long number1 = n / (t * 10), number2 = n1 % 10, number3 = n % t;
            /*当前数字大于1，则只需要代表已经轮完了后面数字的一轮了，所以就number1+1
            =1，就代表还没轮完，所以就number1*t+number3+1，注意后续这里还要加上1，因为10-12之间，十位是有3个1的
            等于0，就代表只是轮完了前面的一轮*/
            if (number2 > 1){
                result += ((number1 + 1) * t);
            }else if (number2 == 1){
                result += ((number1 * t) + number3 + 1);
            }else if (number2 == 0){
                result += (number1 * t);
            }
            t *= 10;
            n1 /= 10;
        }

        return result;
    }
};