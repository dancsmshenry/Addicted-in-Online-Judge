class Solution {
public:
    bool CheckPermutation(string s1, string s2){
        int n1 = s1.size() - 1, n2 = s2.size() - 1;
        unordered_map<char, int> hashmap;
        
        while (n1 >= 0 || n2 >= 0){
            if (n1 >= 0){
                hashmap[s1[n1]] ++ ;
            }
            if (n2 >= 0){
                hashmap[s2[n2]] -- ;
            }
            n1 -- ;
            n2 -- ;
        }

        for (auto[_, pos]: hashmap){
            if (pos > 0 || pos < 0){
                return false;
            }
        }
        return true;
    }
};