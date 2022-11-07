class Solution {
private:
    vector<string> ans{};

    void dfs(string &s, string temp, int index, int count, int smallpoint) {
        int j = temp.size() - 1;
        while (j > 0 && temp[j] != '.' && temp[j] != '(' && temp[j] != ' ') -- j;
        if (index == s.size() - 1) {
            if (count == 1) {
                if (temp[j] == '.' && temp.back() != '0') ans.push_back(temp + ")");
                else if (temp[j] == ' ' && (temp[j + 1] != '0' || temp.size() - 2 == j)) ans.push_back(temp + ")");
            }
            return ;
        }
        dfs(s, temp + s[index], index + 1, count, smallpoint);
        if ((temp[j] == '(' || temp[j] == ' ') && temp[j + 1] == '0' && temp.size() - 2 != j) return ; // 整数部分前面有多余的0
        else if (temp[j] == '.' && (temp.back() == '0')) return ; //    小数部分后面有多余的0
        if (count == 0 && index > 1 && temp.back() != '.') dfs(s, temp + ", ", index, 1, 0);
        if (smallpoint == 0 && temp.back() != ' ' && temp.back() != '(') dfs(s, temp + ".", index, count, 1);
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        dfs(s, "(", 1, 0, 0);
        return ans;
    }
};