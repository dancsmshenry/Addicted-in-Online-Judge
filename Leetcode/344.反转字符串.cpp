class Solution {
public:
    void reverseString(vector<char>& s){
        for (int begin = 0, end = s.size() - 1; begin < end; begin ++, end -- ){
            char swap = s[begin];
            s[begin] = s[end];
            s[end] = swap;
        }

        return ;
    }
};