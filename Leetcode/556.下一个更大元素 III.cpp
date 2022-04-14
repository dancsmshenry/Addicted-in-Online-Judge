class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int size = str.length();
        
        int i = size - 1;
        while (i >= 0 && str[i] >= str[i + 1]) -- i;
        if (i < 0) {
            return -1;
        }

        int j = size - 1;
        while (j >= 0 && str[i] >= str[j]) -- j;
        swap(str[j], str[i]);
        reverse(str.begin() + i + 1, str.end());
        
        long long res = 0;
        for (int l = 0; l < size; ++ l) res = res * 10 + str[l] - '0';
        if (res > INT_MAX) return -1;
        return res;
    }
};