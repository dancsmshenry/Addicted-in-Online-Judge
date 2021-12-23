class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int res = 1, flag = 0;
        vector<int> result;

        for (const int& i: a){
            if (i != 0){
                res *= i;
            }else{
                flag ++ ;
            }
        }

        for (const int& i: a){
            if (flag > 0){
                if (flag == 1){
                    int mid = (i == 0 ? res : 0);
                    result.push_back(mid);
                    continue;
                }
                result.push_back(0);
            }else{
                result.push_back(res / i);
            }
        }
        
        return result;
    }
};