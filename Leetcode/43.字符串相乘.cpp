class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        return num1.size() > nums2.size() ? solve(num1, num2) : solve(num2, num1);//num1的长度大于num2
    }

    string solve(string num1, string num2) {
        vector<int> res;
        string result = "";
        for (int i = num2.size() - 1; i >= 0; -- i) {
            int count = 0;
            for (int j = num1.size() - 1; j >= 0; -- j) {
                int s1 = num1[j] - '0';
                int s2 = num2[i] - '0';
                if (num2.size() - i + num1.size() - j - 2 >= res.size()) {
                    res.push_back((s1 * s2 + count) % 10);
                    count = (s1 * s2 + count) / 10;
                } else {
                    res[num2.size() - i + num1.size() - j - 2] += ((s1 * s2 + count) % 10);
                    count = (s1 * s2 + count) / 10;
                }
            }
            if (count > 0) {
                if (num1.size() + num2.size() - i - 1 >= res.size()) {
                    res.push_back(count);
                } else {
                    res[num1.size() + num2.size() - i - 1] += count;
                }
            }
        }

        for (int i = 0, count = 0; i < res.size(); i ++ ){
            int count1 = (res[i] + count) / 10;
            res[i] = (res[i] + count) % 10;
            count = count1;
            if (i == res.size() - 1 && count > 0){
                res.push_back(count);
                break;//这里最后没有break，导致我debug了快半个钟.....
            }
        }

        for (int i = res.size() - 1; i >= 0; i -- ){
            result += to_string(res[i]);
        }

        return result;
    }
};