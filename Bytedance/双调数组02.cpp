/**
 * 算法题： 一个数组[1,2,3,4,4,2,2]，先递增后递减， 求不重复元素的个数。空间复杂度要求O(1), 时间复杂度O(n)
 * 或者说求不重复的元素是哪些
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int>& arrs) {
        int n = arrs.size();
        int left = 0, right = n - 1;
        vector<int> res;

        while (left < right) {
            if (arrs[left] == arrs[right]) {
                int temp = arrs[left];
                while (left < right && arrs[left] == temp) left ++ ;
                while (left < right && arrs[right] == temp) right -- ;
            } else if (arrs[left] > arrs[right]) {
                res.push_back(arrs[right]);
                right -- ;
            } else {
                res.push_back(arrs[left]);
                left ++ ;
            }
        }

        return res.size();
    }
};

int main() {
    vector<int> arrs = {1,2,3,4,4,5,6,7,8,9,8,8,7,6,5,4,4,4,3,3,2,2};
    Solution s1;
    cout << s1.find(arrs) << endl;
}