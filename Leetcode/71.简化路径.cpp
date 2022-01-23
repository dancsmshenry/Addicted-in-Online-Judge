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

//官方的写法
class Solution {
public:
    string simplifyPath(string path){
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(cur);
                    cur = "";
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(cur);
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        
        for (auto& name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }else if (name != "." && !name.empty()) {
                stack.push_back(name);
            }
        }

        string res = "";
        for (auto& s1: stack) {
            res += ('/' + s1);
        }
        if (res.empty()) {
            res = '/';
        }

        return res;
    }
};