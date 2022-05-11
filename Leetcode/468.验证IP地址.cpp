class Solution {
public:
    string validIPAddress(string queryIP) {
        vector<string> f;
        split(f, queryIP, 0);

        if (f.size() == 4) {
            for (auto& s: f) {
                if (s.size() == 0 || s.size() > 3) return "Neither";
                int number = 0;
                for (auto& s1: s) {
                    if (!isdigit(s1)) return "Neither";
                    number = number * 10 + s1 - '0';
                }
                if (number > 255 || (s[0] == '0' && s.size() > 1)) return "Neither";
            }
            return "IPv4";
        } else if (f.size() == 8) {
            for (auto& s: f) {
                if (s.size() == 0 || s.size() > 4) return "Neither";
                for (auto& s1: s) {
                    if ((s1 > 'F' && s1 <= 'Z') || (s1 >'f' && s1 <= 'z')) return "Neither";
                }
            }
            return "IPv6";
        }

        return "Neither"; 
    }

    void split(vector<string>& f, string& queryIP, int begin) {
        string res = "";
        int n = queryIP.size();
        while (begin < n && queryIP[begin] != '.' && queryIP[begin] != ':') {
            res += queryIP[begin];
            ++ begin;
        }
        f.push_back(res);
        if (n <= begin) {
            return ;
        }
        split(f, queryIP, begin + 1);
    }
};