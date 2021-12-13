class Solution {
public:
    string minWindow(string s, string t) {
        /*双指针+哈希*/
        /*
            在模拟过程中的问题就是：如果right指针右移的字母，已经出现过了（即此时record[s[right]]小于等于0的时候），并且参与了count的计数，那应该如何操作呢？
            答：如果已经记录过了，就不会计入count了，但是record会记录下来，这样后续left从这里经过的时候，只要record是负数，就不会影响count
        */
        unordered_map<char, int> record;
        for (auto& i:t){
            record[i] ++ ;
        }

        int left = 0, right = 0;
        int n = s.size(), count = t.size(), length = INT_MAX, begin = 0;
        while (right < n){
            if (record.count(s[right])){
                count  = record[s[right]] > 0 ? count - 1 : count;
                record[s[right]] -- ;
            }
            right ++ ;
            while (count == 0){
                if (right - left < length){
                    begin = left;
                    length = right - left;
                }
                if (record.count(s[left])){
                    count = record[s[left]] >= 0 ? count + 1 : count;
                    record[s[left]] ++ ;
                }
                left ++ ;
            }
        }

        return length == INT_MAX ? "" : s.substr(begin, length);
    }
};