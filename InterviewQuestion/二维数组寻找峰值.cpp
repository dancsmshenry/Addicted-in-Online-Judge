#include <iostream>
#include <vector>

using namespace std;

/**
 * 在二维数组中寻找峰值，峰值是指该值大于四个方向上的值；如果是边界，就默认是大于的
*/

class Solution {
    //主函数
    int solve(vector<vector<int>> &arr, int minColumn) {
        return findAPeakBaseTwoDimensional(arr, arr[0].size() / 2);
    }

    int findAPeakBaseTwoDimensional(vector<vector<int>> &arr, int minColumn) {
        int column = arr[0].size();
        int maxRowIndex = getMaxRowIndex(arr, minColumn);
        int target = arr[maxRowIndex][minColumn];

        //与左边对比，小则向左找峰值
        if (minColumn > 0 && target < arr[maxRowIndex][minColumn - 1]) {
            return findAPeakBaseTwoDimensional(arr, minColumn - 1);
        }

        //与右边对比，小则向右找峰值
        if (minColumn + 1 < column && target < arr[maxRowIndex][minColumn + 1]) {
            return findAPeakBaseTwoDimensional(arr, minColumn + 1);
        }
        //垂直方向上它是最大，水平方向上也是最大，所以它就是peak
        return target;
    }

    int getMaxRowIndex(vector<vector<int>> &arr, int minColumn) {
        int left = 0, right = arr[0].size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid][minColumn] > arr[mid + 1][minColumn]) {//这里不能mid-1，因为如果是2，3的话，mid-1会取到1的
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return arr[left][minColumn];
    }
};