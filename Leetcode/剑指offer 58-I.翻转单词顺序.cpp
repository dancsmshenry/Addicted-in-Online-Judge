class Solution {
public:
    string reverseWords(string s) {
        vector<string> record(1, "");
        string res = "";

        for (int i = 0; i < s.size(); ++ i ) {
            char temp = s[i];
            if (temp == ' ') {
                record.push_back("");
            } else {
                record[record.size() - 1] += temp;
            }
        }

        for (int i = record.size() - 1; i >= 0; -- i) {
            if (record[i] != "") {
                res += (record[i] + " ");
            }
        }

        return res.substr(0, res.size() - 1);
    }
};