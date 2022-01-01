class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> hashmap = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
        int num1 = num, wei = 1;
        string result = "";

        while (num1 > 0){
            int i1 = num1 % 10;
            if (i1 == 0){//如果是0，直接跳过
            }else if (i1 == 1 || i1 == 5){//如果是5或者1
                result.insert(0, hashmap[i1 * wei]);
            }else if (hashmap.count((i1 + 1) * wei) != 0){//如果是4或者9
                result.insert(0, hashmap[(i1 + 1) * wei]);
                result.insert(0, hashmap[wei]);
            }else if (i1 > 0 && i1 < 4){//如果是1-3之间
                for (int i = 0; i < i1; i ++ ) result.insert(0, hashmap[wei]);
            }else if (i1 > 5 && i1 < 9){//如果是6-8之间
                for (int i = 5; i < i1; i ++ ) result.insert(0, hashmap[wei]);
                result.insert(0, hashmap[wei * 5]);
            }
            num1 /= 10;
            wei *= 10;
        }

        return result;
    }
};