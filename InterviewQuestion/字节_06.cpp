#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

//  一个整数数组s，无序，可能有重复。给一个k，找出和为k的倍数的最短子数组
//  输入：s = [1, 5, 4, 3, 2]，k = 9
//  输出： [5, 4]

std::vector<int> solve(std::vector<int>& nums, int k) {
    std::unordered_map<int, std::vector<int>> records;
    int count{};
    int n = nums.size();
    records[0].push_back(-1);

    for (int i = 0; i < n; ++ i) {
        count += nums[i];
        records[(count % k + k) % k].push_back(i);
    }

    int begin{}, length = INT_MAX;
    for (auto& record: records) {
        int n1 = record.second.size();
        for (int i = 0; i < n1; ++ i) {
            for (int j = i + 1; j < n1; ++ j) {
                if (record.second[j] - record.second[i] < length) {
                    begin = record.second[i] + 1;
                    length = record.second[j] - record.second[i];
                }
            }
        }
    }

    return std::vector<int>(nums.begin() + begin, nums.begin() + begin + length);
}

int main() {
    std::vector<int> nums{9,1,5,4,3,2};
    int k{9};
    std::vector<int> res = solve(nums, k);
    for (auto& num: res) {
        std::cout << num << " " << std::endl;
    }
}