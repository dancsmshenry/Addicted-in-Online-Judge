class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        int i = 0;

        while (i < tokens.size()){
            string& s = tokens[i ++ ];//用引用的方法来接受string[]的字符
            if (isnumber(s)){
                s1.push(stoi(s));//这能够取到正负号的
            }else{
                int i1 = s1.top();
                s1.pop();
                int i2 = s1.top();
                s1.pop();
                if (s == "+"){
                    s1.push(i2 + i1);
                }else if (s == "-"){
                    s1.push(i2 - i1);
                }else if (s == "*"){
                    s1.push(i2 * i1);
                }else if (s == "/"){
                    s1.push(i2 / i1);
                }
            }
        }

        return s1.top();
    }

    bool isnumber(string s){
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }
};