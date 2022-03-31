/**
 * 对一个先递增后递减的数组去重。 双指针O(n)
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> find(vector<int>& arrs) {
        int n = arrs.size();
        int left = 0, right = n - 1;
        vector<int> res;

        while (left < right) {
            if (arrs[left] == arrs[right]) {
                res.push_back(arrs[left]);
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

        return res;
    }
};

int main() {
    vector<int> arrs = {1,2,3,4,4,5,6,7,8,9,8,8,7,6,5,4,4,4,3,3,2,2};
    Solution s1;
    vector<int> res = s1.find(arrs);
    for (auto& num: res) {
        cout << num << " ";
    } 
}