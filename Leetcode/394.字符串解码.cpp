class Solution {
public:
    string decodeString(string s) {
        string result = "";
        if (s.size() == 0){
            return result;
        }

        for (int i = 0; i < s.size();){
            while ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')){
                char c = s[i];
                result += c;
                i ++ ;
            }

            if (s[i] <= '9' && s[i] >= '0'){
                int sum = 0;
                while (s[i] <= '9' && s[i] >= '0') sum = sum * 10 + s[i ++ ] - '0';

                int j = 0, i1 = i + 1;
                do{                    
                    if (s[i] == '[') j ++ ;
                    if (s[i] == ']') j -- ;
                    i ++ ;
                }while (j != 0);
                
                string s1 = decodeString(s.substr(i1, i - i1 - 1));
                for (int i2 = 0; i2 < sum; i2 ++ ){
                    result += s1;
                }
            }
        }
        
        return result;
    }
};