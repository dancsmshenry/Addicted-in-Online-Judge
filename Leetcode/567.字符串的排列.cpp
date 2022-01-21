class Solution {
public:
    bool checkInclusion(string s1, string s2){
        //双指针维护滑动窗口
        if (s1.size() > s2.size()){//长度小于的直接false
            return false;
        }
        unordered_map<char, int> hashmap;
        for (auto s: s1){
            hashmap[s] ++ ;
        }
        for (int i = 0; i < s1.size(); i ++ ){//init滑动窗口
            hashmap[s2[i]] -- ;
        }

        //开始右移
        int left = 0, right = s1.size() - 1;
        while (right < s2.size()){
            if (check(hashmap)){
                return true;
            }else{
                hashmap[s2[left]] ++ ;
                left ++ ;
                right ++ ;
                hashmap[s2[right]] -- ;
            }
        }

        return false;
    }

    //检查是否是子串
    bool check(unordered_map<char, int>& hashmap){
        for (auto[_, pos]: hashmap){
            if (pos < 0 || pos > 0) return false;
        }
        return true;
    }
};