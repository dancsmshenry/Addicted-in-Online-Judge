class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = (int)sqrt(c);//int强制转型
        
        while (left <= right){
            long res =  c - right * right;//防止溢出
            if (res == left * left){
                return true;
            }else if (res < left * left){
                right -- ;
            }else{
                left ++ ;
            }
        }

        return false;
    }
};