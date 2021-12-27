class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>{};
        }

        //init，一方面即把从0开始的滑动窗口初始化在最开始的位置，用scount数组存储滑动窗口中的内容；另一方面，用pcount存储原来p有的内容，方面后续进行对比
        vector<int> ans;
        vector<int> sCount(26), pCount(26);
        for (int i = 0; i < pLen; ++i){
            sCount[s[i] - 'a'] ++ ;
            pCount[p[i] - 'a'] ++ ;
        }

        //如果一开始就相等，就直接放进去
        if (sCount == pCount){
            ans.push_back(0);
        }

        //开始移动滑动窗口，左边--，右边++，如果相等就放入
        for (int i = 0; i < sLen - pLen; ++i){
            sCount[s[i] - 'a'] -- ;
            sCount[s[i + pLen] - 'a'] ++ ;

            if (sCount == pCount){
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};