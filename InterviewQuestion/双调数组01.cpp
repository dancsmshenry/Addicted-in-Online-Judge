/**
 * 一个先递增后递减的数组，求其最大值
 * 分为有重复版和无重复版
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //无重复版
    int maxn1(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                right = mid + 1;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                left = mid - 1;
            } else {
                return nums[mid];
            }
        }

        return -1;
    }

    //有重复版，感觉如果是有重复的话，就很难用二分来解决了....（left和right都不能因为重复而乱移位置..）
    int maxn2(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            if (nums[left] == nums[right]) {
                int temp = nums[left];
                res.push_back(temp);
                while (left <= right && nums[right] == temp) {
                    right -- ;
                }
                while (left <= right && nums[left] == temp) {
                    left ++ ;
                } 
            } else if (nums[left] < nums[right]) {
                int temp = nums[left];
                res.push_back(temp);
                while (left <= right && nums[left] == temp) {
                    left ++ ;
                }
            } else {
                int temp = nums[right];
                res.push_back(temp);
                while (left <= right && nums[right] == temp) {
                    right -- ;
                }
            }
        }

        return res[res.size() - 1];
    }
};

int main() {
    
}