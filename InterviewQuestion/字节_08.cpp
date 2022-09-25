#include <iostream>
#include <vector>

using namespace std;

/**
 * 有100个格子，每个格子上有一个蘑菇，蘑菇分为好蘑菇和毒蘑菇，好蘑菇增加体力值n,毒蘑菇消耗体力值n
 * 人的初始体力值为m
 * 跳的格子的距离与消耗的体力值成正比，正比关系是1:1
 * 问题:输入一个人的初始体力值m和格子初始化序列list
 * 求问:写一个函数，判断该人是否能否跳到终点?如果不能，函数返回-1，如果可以，返回剩余的最大体力值。
 */

/**
 * 详细思路：
 * 从可以走到的方块范围内寻找，从左往右
 * 如果是好蘑菇（食用蘑菇），就跳过去吃它；如果能走的范围内都是毒蘑菇，就直接返回-1
 * 我的理解是:
 * 如果到达一个点的时候体力是零,那也算是到达了这个点
 * 同时,如果到达了这个格子,就必须吃下这个蘑菇
 * 
 * 在nowcoder上看到的一种题解,有点简洁https://www.nowcoder.com/discuss/405132
 */

class Solution {
public:
    // spirit表示当前的体力，arr表示路上的蘑菇，数值正负表示是加体力还是减体力
    int drugmushroom(int spirit, vector<int> &arr) {
        int n = arr.size();
        int step = -1; //表示当前的下标

        for (int i = 1; i + step < n && i <= spirit; ++ i) {
            if (arr[i + step] > 0) {
                spirit = spirit + arr[i + step] - i;
                step += i;
                i = 0;
            }
        }

        if (step >= n - 1) {
            return spirit;
        }
        spirit = spirit - (n - 1 - step) + arr[n - 1];
        if (spirit >= 0) {
            return spirit;
        } 

        return -1
    }
};