class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        if (n < 3){
            return true;
        }
        stack<int> s;

        for (int i = 0, j = 0; j < n && i < n;){
            /*栈顶不等于popped当前的元素，就一直放进去，放到他等于位置*/
            while ((s.size() != 0 && j < n && popped[i] != s.top()) || s.empty()){
                s.push(pushed[j]);
                j ++ ;
            }
            
            /*一旦等于了，就看是把元素给放出来，同时逐个逐个的放出来*/
            while (s.size() != 0 && i < n && popped[i] == s.top()){
                s.pop();
                i ++ ;
            }
            
            /*如果后续放不出来了*/
            if (j == n && i != n){
                return false;
            }   
        }

        return true;
    }
};