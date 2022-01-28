class Solution {
public:
    string validIPAddress(string queryIP) {
        vector<string> f;
        div(f, queryIP, 0);

        if (f.size() == 4) {
            for (auto& s: f) {
                if (s.size() == 0 || s.size() > 3) return "Neither";
                int total = 0;
                for (auto& s1: s) {
                    if (!isdigit(s1)) return "Neither";
                    total = total * 10 + s1 - '0';
                }
                if (total > 255 || (s[0] == '0' && s.size() > 1)) return "Neither";//没想到还有00的情况...

            }
            return "IPv4";
        } else if (f.size() == 8) {
            for (auto& s: f) {
                if (s.size() == 0 || s.size() > 4) return "Neither";
                for (auto& s1: s) {
                    if (isdigit(s1)) continue;
                    if ((s1 > 'F' && s1 <= 'Z') || (s1 >'f' && s1 <= 'z')) return "Neither";
                }
            }
            return "IPv6";
        }

        return "Neither"; 
    }

    void div(vector<string>& f, string& queryIP, int begin) {
        string res = "";
        while (begin < queryIP.size() && queryIP[begin] != '.' && queryIP[begin] != ':') {
            res += queryIP[begin];
            begin ++ ;
        }
        f.push_back(res);
        if (queryIP.size() <= begin) {
            return ;
        }
        div(f, queryIP, begin + 1);
    }
};