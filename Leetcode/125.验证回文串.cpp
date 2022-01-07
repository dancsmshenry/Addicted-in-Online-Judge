class Solution {
public:
    bool isPalindrome(string s) {
        //对于字符串的题目，一般有两种方法解决，第一种是预处理，就用一个新的容器对数据进行处理，然后再处理
        //第二种，就是边遍历就边处理，不过最好还是预处理会比较好写一点
        string s1 = "";
        for (char ch:s){
            if (isalnum(ch)){
                s1 += tolower(ch);
            }
        }
        
        int left = 0, right = s1.size() - 1;
        while (left < right){
            if (s1[left] != s1[right]){
                return false;
            }
            left ++ ;
            right -- ;
        }

        return true;
    }
};