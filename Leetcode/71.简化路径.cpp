class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";
        path.push_back('/');
        int n = path.size();

        for (int i = 1; i < n; i ++ ){
            switch (path[i]){
                case '/':
                    if (res[res.size() - 1] != '/') {//去除多斜杠
                        res += '/';
                    }
                    break;
                case '.': 
                    if (i + 1 < n && path[i + 1] == '/') {//去除/./
                        i ++ ;
                    } else if (i + 1 < n && path[i + 1] == '.' && (i + 2 == n || path[i + 2] == '/')){//去除/../
                        if (res.size() == 1){}
                        else {
                            do{
                                res.pop_back();
                            }while (res[res.size() - 1] != '/');
                            i += 2;
                        }
                    } else {//保留/......./的情况
                        do{
                            res += path[i];
                            i ++ ;
                        } while (path[i] != '/');
                        i -- ;
                    }
                    break;
                default: //保留路径
                    do{
                        res += path[i];
                        i ++ ;
                    } while (path[i] != '/');
                    i -- ;
            }
        }

        if (res[res.size() - 1] == '/' && res.size() > 1) res.pop_back();//去除最后的斜杠
        return res;
    }
};

//官方的写法class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& strs) -> vector<string> {
            vector<string> res;
            string mid = "";
            for (auto& str: strs) {
                if (str == '/') {
                    res.push_back(mid);
                    mid = "";
                } else {
                    mid += str;
                }
            }
            res.push_back(mid);
            return res;
        };

        vector<string> paths = split(path);
        vector<string> s;

        for (auto& p: paths) {
            if (p == "..") {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else if (p != "." && p != "") {
                s.push_back(p);
            }
        }

        string res = "";
        for (auto& s1: s) {
            res += ("/" + s1);
        }

        return (res.size() != 0) ? res : "/";
    }
};