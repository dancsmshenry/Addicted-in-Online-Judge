#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * ababababababab
 * 要求O（n）算法，求最长字串，包含相同数目的a和b的字符
 * 
 * 我的第一感觉是和523一样
 * 
 * 群友给的答案：
 * 把a看作+1，b看作-1，然后边扫边记，对于每一个当前前缀和sum，找到一个sum'使得sum-sum'=0
 * 
 * 这一套题523+560，都是很经典的前缀和+哈希表
 * 
 * 我的一个思路就是
 * 对于当前的前缀和，先查看是否有当前的值的负值在hashamp里面，如果有，就把它们的差值记录，然后和res比较大小；没有就算了
 * 然后，看看hashmap中有没有当前的值，如果没有就放入；否则就不管（注意，为了获得最大的子串，这里就是要不管的）
*/

class Solution {
public:
    string findd_max(string s) {
        unordered_map<int, int> hashmap;
        int count = 0;
        int i = 0, n = s.size();
        string res = "";

        while (i < n) {
            if (s[i] == 'a') count ++ ;
            else count -- ;
            if (hashmap.count(-count)) {
                //update res
                if (i - hashmap[-count] > res.size()) {
                    res = s.substr(hashmap[-count], i - hashmap[-count]);
                }
            }
            if (!hashmap.count(count)) {
                hashmap[count] = i;
            }
            ++ i;
        }

        return res;
    }
};


int main() {
    string s = "aaaabbbbabababababbabababa";

    Solution s1;
    cout << s1.findd_max(s) << endl;
}