class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hashmap1, hashmap2;

        split(hashmap1, s1);
        split(hashmap2, s2);
        
        vector<string> res;
        for (auto& h: hashmap1) {
            if (h.second == 1 && !hashmap2.count(h.first)) {
                res.push_back(h.first);
            }
        }
        for (auto& h: hashmap2) {
            if (h.second == 1 && !hashmap1.count(h.first)) {
                res.push_back(h.first);
            }
        }

        return res;
    }

    void split(unordered_map<string, int>& hashmap, string s) {
        int i = 0;
        while (i < s.size()) {
            string mid = "";
            while (i < s.size() && s[i] != ' ') {
                mid += s[i];
                i ++ ;
            }
            i ++ ;
            hashmap[mid] ++ ;
        }
    }
};