class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0){
            return 0;
        }
        int res = -1;

        for (int point = 0; point + needle.size() <= haystack.size(); point ++){
            if (haystack[point] == needle[0]){
                for (int i = 0; i < needle.size(); i ++ ){
                    if (haystack[point + i] != needle[i]){
                        break;
                    }
                    if (i == needle.size() - 1){
                        res = point;
                        return res;
                    }
                }
            }
        }

        return res;
    }
};