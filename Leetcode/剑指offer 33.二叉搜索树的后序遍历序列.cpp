class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        /*左右根*/
        return solve(postorder, 0, postorder.size() - 1);
    }

    bool solve(vector<int>& postorder, int left, int right){
        if (left >= right){
            return true;
        }

        int root = postorder[right], flag = right - 1;
        while (flag >= left && postorder[flag] > root){
            flag -- ;
        }

        for (int i = left; i <= flag; i ++ ){
            if (postorder[i] >= root){
                return false;
            }
        }
        return solve(postorder, left, flag) && solve(postorder, flag + 1, right - 1);
        // return solve(postorder, left, flag - 1) && solve(postorder, flag, right - 1);
        /*第一次debug：边界设立出现问题，有一种情况，此时的right左边的数字全部都比postorder大，那么flag就会到-1
        那么flag,right - 1这边就会报错，因为后面i是从left开始的
        就需要改为left,flag和flag + 1,right - 1*/
    }
};


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> s1{};
        int root = INT_MAX;
        int n = postorder.size();

        for (int i = n - 1; i >= 0; -- i) {
            if (postorder[i] > root) {
                return false;
            }
            while(!s1.empty() && s1.top() > postorder[i]) {
                root = s1.top();
                s1.pop();
            }
            	
            s1.push(postorder[i]);
        }

        return true;
    }
};