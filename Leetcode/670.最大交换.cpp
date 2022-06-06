class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) {
            return 0;
        }

        string str = to_string(num);
        int n = str.length();
        for (int i = 0; i < n; ++ i) {
            int maxn = str[i] - '0', index = i;
            for (int j = i + 1; j < n; ++ j) {
                maxn = max(maxn, str[j] - '0');
                index = (maxn == str[j] - '0') ? j : index;
            }
            if (maxn > str[i] - '0') {
                swap(str[i], str[index]);
                return stoi(str);
            }
        }

        return stoi(str);
    }
};

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> record(10, -1);
        string str = to_string(num);
        int n = str.length();

        for (int i = 0; i < n; ++ i) {
            record[str[i] - '0'] = i;
        }

        for (int i = 0; i < n; ++ i) {
            for (int j = 9; j >= 0; -- j) {
                if (record[j] > i && j > str[i] - '0') {
                    swap(str[i], str[record[j]]);
                    return stoi(str);
                }
            }
        }

        return stoi(str);
    }
};