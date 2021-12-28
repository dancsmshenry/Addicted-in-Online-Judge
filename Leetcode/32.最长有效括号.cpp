class Solution {
public:
    int longestValidParentheses(string s) {
        //格式正确且连续的.....       
       stack<int> s1;
       int result = 0;
       s1.push(-1);

        /*这道题的思路很巧妙，维护栈的方式很好
        比如说，这里的栈放的是数组的坐标，方便求出最长有效括号的长度
        对于一段连续的有效括号来说，它的最前面无非就几种情况
        第一种，栈是空的，我们是记录坐标的长度的，那应该怎么做？题解提供的办法就是放一个-1进去维护（太妙了）
        第二种，最左边是(，那好办，所以我们就用当前的)的左边减去栈顶的坐标
        为什么，因为对应当前的连续括号来说，他的左边界应该就是这个栈顶坐标（注意，期间会因为)把很多的(给踢出去的
        第三种，)，那好办，因为这个根本不会被放进去，所以就变为上述第一二种的情况了*/
       for (int i = 0; i < s.size(); i ++ ){
           if (s[i] == '('){
               s1.push(i);
           }else{
               s1.pop();
               if (!s1.empty()){
                   result = max(result, i - s1.top());
               }else{
                   s1.push(i);
               }
           }
       }
        
        return result;
    }
};