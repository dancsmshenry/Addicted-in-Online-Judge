class Solution {
public:
    char firstUniqChar(string s) {
        /*用哈希表记录数据*/
        unordered_map<char, int> map;

        for (char i:s){
            map[i] ++ ;
        }

        for (char i:s){
            if (map[i] == 1){
                return i;
            }
        }
        
        return ' ';
    }
};