#include <iostream>

using namespace std;
/**
 * 1到100每次去除奇数项后剩下的数，求推导公式
 * 镜像问题：1到100每次去除偶数项，最后剩下的数是多少(最后剩下的那个数必然是1)
 * 进阶问题：镜像问题下，最后剩下的两个数是多少？
 * 答案：是[1, 去掉奇数项后剩下的数+1]
*/

class Solution {
public:
    int solve_ou(int number) {
        if (number == 1) {
            return 0;
        }
        number /= 2;
        int count = 1;
        while (number > 0) {
            count *= 2;
            number /= 2;
        }

        return count;
        //所以递推公式是2^(length(number) - 1)，其中length(number)表示number的二进制长度
    }
};

int main() {
    Solution s;
    cout << s.solve_ou(15) << endl;
}