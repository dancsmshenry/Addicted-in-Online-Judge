#include <bits/stdc++.h>

using namespace std;

// �⼸�д������ʹ�� cin cout ���ٶȺ� scanf printf ����һ����
// ��ͨ�� cin cout ��� scanf printf ���ǳ���
void fast_read() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_read();

    // ������������Ϊһ���ַ���
    string array{};
    cin >> array;
    // �������ַ�����ֳɸ�����
    vector<string> nums;
    for (int i = 1, j = 1; j < array.size(); ++ j) {
        if (array[j] == ',' || array[j] == ']') {
            string num = array.substr(i, j - i);
            nums.push_back(num);
            i = j + 1;
        }
    }
    // ���Զ����������
    sort(nums.begin(), nums.end(), [&](const string& a, const string& b){
        return a + b > b + a;
    });
    // ��ӡ���
    string res{};
    for (auto& num : nums) {
        res += num;
    }

    cout << res << endl;
    return 0;
}