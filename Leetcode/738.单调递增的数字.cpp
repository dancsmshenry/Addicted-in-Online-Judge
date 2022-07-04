class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string arr = to_string(n);
        int i = 0;
        while (i + 1 < arr.size() && arr[i] <= arr[i + 1]) {
            ++ i;
        }

        // 此时的i，必然是arr[i] > arr[i + 1]，或者说i = arr.size() - 1，所以需要判断一下
        if (i < arr.size() - 1) {
            while (i >= 0 && arr[i] > arr[i + 1]) {
                arr[i] -= 1;
                -- i;
            }

            // 这里+2，是因为其中一个1是要补偿上面-1，另一个1是要移动到变为9开始的位置
            for (i += 2; i < arr.size(); ++ i) {
                arr[i] = '9';
            }
        }

        return stoi(arr);
    }
};

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string res = to_string(n);

        int i = 1;
        while (i < res.length() && res[i] >= res[i - 1]) {
            ++ i;
        }

        if (i < res.length()) {
            while (i > 0 && res[i] < res[i - 1]) {
                res[i - 1] -= 1;
                -- i;
            }

            for (++ i; i < res.length(); ++ i) {
                res[i] = '9';
            }
        }

        return stoi(res);
    }
};