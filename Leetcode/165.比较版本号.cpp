class Solution {
public:
    int compareVersion(string version1, string version2) {
        //一遇到字符串的题目，脑袋就短路....
        int n = version1.size(), m = version2.size();

        for (int v1 = 0, v2 = 0; v1 < n || v2 < m; v1 ++, v2 ++ ){
            int num1 = 0, num2 = 0;
            while (v1 < n && version1[v1] != '.'){
                num1 = num1 * 10 + version1[v1] - '0';
                v1 ++ ;
            }
            while (v2 < m && version2[v2] != '.'){
                num2 = num2 * 10 + version2[v2] - '0';
                v2 ++ ;
            }
            if (num1 > num2){
                return 1;
            }
            if (num1 < num2){
                return -1;
            }
        }

        return 0;
    }
};