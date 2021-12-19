class Solution {
public:
    // 这能超时啊.....
    // string addSpaces(string s, vector<int>& spaces) {
    //     for (int i = 0; i < spaces.size(); i ++ ){
    //         s.insert(spaces[i] + i, " ");
    //     }
    //     return s;
    // }
    
    string addSpaces(string s, vector<int>& spaces){
        string result = "";
        int j = 0;
        for (int i = 0; i < spaces.size(); i ++ ){
            while (j < s.size() && j < spaces[i]) result += s[j ++ ];
            result += " ";
        }
        while (j < s.size()) result += s[j ++ ];

        return result;
    }
};