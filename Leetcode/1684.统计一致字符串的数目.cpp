class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int set_{};
        for (auto& a: allowed) {
            set_ |= 1 << (a - 'a');
        }

        int ans{};
        for (auto& word: words) {
            for (auto& w: word) {
                if ((set_ & (1 << (w - 'a'))) == 0) {
                    -- ans;
                    break;
                }
            }
            ++ ans;
        }
        return ans;
    }
};

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set_;
        for (auto& a: allowed) {
            set_.insert(a);
        }

        int ans{};
        for (auto& word: words) {
            for (auto& w: word) {
                if (!set_.count(w)) {
                    -- ans;
                    break;
                }
            }
            ++ ans;
        }

        return ans;
    }
};