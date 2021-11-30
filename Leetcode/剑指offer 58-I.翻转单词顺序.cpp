class Solution {
public:
    string reverseWords(string s) {
        vector<string> res(1, "");
        string result = "";

        for (int i = 0, j = 0; i < s.size(); i ++ ){
            /*这个位置也是一个很大的坑，即s[i]不能作为值进行比较，wc.......*/
            char s2 = s[i];
            if (s2 == ' '){
                /*这个位置满了很大很大的一个坑，因为我是遇到了空格就会新建一个string进res中，
                然而我后面因为没有考虑到其他的空格，导致后面是每遇见一个元素就插入空格，
                没想到其实会有很多没放东西的string进入了res中*/
                res.push_back("");
                j ++ ;
            }else{
                char s1 = s[i];
                res[j] += s1;
            }
        }
        
        for (int i = res.size() - 1; i >= 0; i -- ){
            if (res[i] != ""){
                result += (res[i] + " ");
            }
        }
        result = result.substr(0, result.length() - 1);

        return result;
    }
};