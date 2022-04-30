/**
 * 先递增后递减的数组中总共有多少个不同数字
 * 
 * 其实有点像合并两个有序链表：
 * 如果左右相等，就从两侧去把相同的都删除掉
 * 否则就只删除一侧的节点
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return n;
        }
        int left = 0, right = n - 1;
        int sum = 0;

        while (left <= right) {
            sum ++ ;
            if (arr[left] == arr[right]) {
                int temp = arr[left];
                while (left <= right && arr[right] == temp) {
                    right -- ;
                }
                while (left <= right && arr[left] == temp) {
                    left ++ ;
                } 
            } else if (arr[left] < arr[right]) {
                int temp = arr[left];
                while (left <= right && arr[left] == temp) {
                    left ++ ;
                }
            } else {
                int temp = arr[right];
                while (left <= right && arr[right] == temp) {
                    right -- ;
                }
            }
        }

        return sum;
    }
};

int main() {
    
}