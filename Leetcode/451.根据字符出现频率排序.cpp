// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> hashmap;
//         int maxn = 0;
//         for (auto& s1: s) {
//             hashmap[s1] ++ ;
//             maxn = max(maxn, hashmap[s1]);
//         }

//         vector<vector<char>> bucket(maxn + 1);
//         for (auto& h: hashmap) {
//             bucket[h.second].push_back(h.first);
//         }

//         string res = "";
//         for (int i = maxn; i > 0; i -- ) {
//             for (auto& b: bucket[i]) {
//                 string mid(i, b);
//                 res += mid;
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashmap;
        for (auto& s1: s) {
            hashmap[s1] ++ ;
        }
        sort(s.begin(), s.end(), [&](const char& s1, const char& s2) {
            if (hashmap[s1] == hashmap[s2]) {
                return s1 > s2;
            }
            return hashmap[s1] > hashmap[s2];
        });

        return s;
    }
};