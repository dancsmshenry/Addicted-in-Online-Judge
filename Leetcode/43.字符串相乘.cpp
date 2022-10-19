class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        if (num2.length() > num1.length()) {
            return multiply(num2, num1);
        }

        vector<int> res(num1.size() + num2.size(), 0);
        string result = "";
        for (int i = num2.size() - 1; i >= 0; -- i) {
            int count{};
            for (int j = num1.size() - 1; j >= 0; -- j) {
                int index = num2.size() - i + num1.size() - j - 2;
                res[index] = res[index] + count + (num1[j] - '0') * (num2[i] - '0');
                count = res[index] / 10;
                res[index] %= 10;
            }
            res[num2.size() - i - 1 + num1.size()] += count;
        }

        while (res.back() == 0) res.pop_back();
        for (int i = res.size() - 1; i >= 0; -- i) {
            result += to_string(res[i]);
        }

        return result;        
    }
};