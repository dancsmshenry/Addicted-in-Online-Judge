#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * 给定一个数 n，如 23121，给定一组数 A，{2, 4, 9}，返回用A可以组成的小于 n 的最大数，A 不为空，答案 22999，
 **/

class test {
    int findmax(unordered_set<int>& numbers, int number) {
        vector<int> res;
        int result = 0;
        return result;
    }

    vector<int> solve(vector<int>& f, int maxn) {//maxn是set中的最大值
        vector<int> res;
        int flag = -1;
        for (int i = 0; i < f.size(); ++ i) {
            int number = find(f[i]);
            if (number <= f[i] && (flag == -1 || number < flag)) {
                res.push_back(number);
                if (flag != -1) 
            } else {
                if (res.size() == 0) {
                    vector<int> result(f.size() - 1, maxn);
                    return result;
                }
                flag = res.back();
                res.pop_back();
                i -= 2;
            }
        }
    }

    int find(int target) {


    }
};