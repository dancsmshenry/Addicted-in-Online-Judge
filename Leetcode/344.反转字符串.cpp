class Solution {
public:
    void reverseString(vector<char>& s){
        for (int begin = 0, end = s.size() - 1; begin < end; begin ++, end -- ){
            swap(s[begin], s[end]);
        }

        return ;
    }
};