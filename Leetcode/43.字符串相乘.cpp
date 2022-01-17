class Solution {
public:
    string multiply(string num1, string num2){
        //高精度乘法（为什么会在294这个样例卡住...）
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() > num2.size()){
            return solve(num1, num2);
        }

        return solve(num2, num1);
    }

    string solve(string num1, string num2){//num1的长度大于num2
        vector<int> res;
        string result = "";
        for (int i = num2.size() - 1; i >= 0; i -- ){
            int mid = 0;
            for (int j = num1.size() - 1; j >= 0; j -- ){
                int s1 = num1[j] - '0', s2 = num2[i] - '0';
                if (num2.size() - i + num1.size() - j - 2 >= res.size()){
                    res.push_back((s1 * s2 + mid) % 10);
                    mid = (s1 * s2 + mid) / 10;
                }else{
                    res[num2.size() - i + num1.size() - j - 2] += ((s1 * s2 + mid) % 10);
                    mid = (s1 * s2 + mid) / 10;
                }
            }
            if (mid > 0){
                if (num1.size() + num2.size() - i - 1 >= res.size()){
                    res.push_back(mid);
                }else{
                    res[num1.size() + num2.size() - i - 1] += mid;
                }
            }
        }

        for (int i = 0, mid = 0; i < res.size(); i ++ ){
            int mid1 = (res[i] + mid) / 10;
            res[i] = (res[i] + mid) % 10;
            mid = mid1;
            if (i == res.size() - 1 && mid > 0){
                res.push_back(mid);
                break;//这里最后没有break，导致我debug了快半个钟.....
            }
        }

        for (int i = res.size() - 1; i >= 0; i -- ){
            result += to_string(res[i]);
        }

        return result;
    }
};