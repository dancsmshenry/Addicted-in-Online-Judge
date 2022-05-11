class Solution {
public:
    int pre(int x) {
        return (x + 1) >> 1;
    }
    
    int countOdds(int low, int high) {
        return pre(high) - pre(low - 1); // 这里是low-1是因为要包括low本身的
    }
};