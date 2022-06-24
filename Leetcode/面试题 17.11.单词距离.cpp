class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int index1 = -1, index2 = -1;
        int res = INT_MAX;

        for (int i = 0; i < n; ++ i) {
            if (word1 == words[i]) {
                index1 = i;
            }
            if (word2 == words[i]) {
                index2 = i;
            }

            if (index1 != -1 && index2 != -1) {
                res = min(res, abs(index2 - index1));
            }
        }

        return res;
    }
};

//  ½ø½×ÎÊÌâ
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> hashmap;
        int n = words.size();
        for (int i = 0; i < n; ++ i) {
            hashmap[words[i]].push_back(i);
        }

        vector<int> v1 = hashmap[word1], v2 = hashmap[word2];
        int i = 0, n1 = v1.size(), j = 0, n2 = v2.size();
        int res = INT_MAX;
        while (i < n1 && j < n2) {
            res = min(res, abs(v1[i] - v2[j]));
            if (v1[i] > v2[j]) {
                ++ j;
            } else {
                ++ i;
            }
        }

        return res;
    }
};