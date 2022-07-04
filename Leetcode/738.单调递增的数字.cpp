class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string arr = to_string(n);
        int i = 0;
        while (i + 1 < arr.size() && arr[i] <= arr[i + 1]) {
            ++ i;
        }

        // ��ʱ��i����Ȼ��arr[i] > arr[i + 1]������˵i = arr.size() - 1��������Ҫ�ж�һ��
        if (i < arr.size() - 1) {
            while (i >= 0 && arr[i] > arr[i + 1]) {
                arr[i] -= 1;
                -- i;
            }

            // ����+2������Ϊ����һ��1��Ҫ��������-1����һ��1��Ҫ�ƶ�����Ϊ9��ʼ��λ��
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