class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       /*
        这道题一开始觉得有点像区间型动态规划，
        即对于区间i-j来说，是否存在k，使得i-k,k+1-j都为true
        如果是，那区间i-j就都是true

        后面看了题解，又发现这是背包问题了...
       */

        vector<bool> f(s.size() + 1, false);
        /*init*/
        f[0] = true;

        /*dp*/
        for (int i = 1; i <= s.size(); i ++ ){   
            for (int j = 0; j < i; j ++ ){       
                string word = s.substr(j, i - j);
                if (f[j] && find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                    f[i] = true;
                }
            }
        }

        return f[s.size()];
    }
};