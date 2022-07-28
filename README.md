# Addicted-in-Online-Judge
This is a repository which records some solutions, notes and ideas about the problems in online judge.







# Target

### 第三阶段

- 周五（07.08）完成考试之后，开始参加每周的周赛

- 练习在nowcoder等平台上的输入输出

  - ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    // 这几行代码可以使得 cin cout 的速度和 scanf printf 大致一样快
    // 普通的 cin cout 会比 scanf printf 慢非常多
    void fast_read()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    int main()
    {
        fast_read();
    
        // 读入整个数组为一个字符串
        string array;
        cin >> array;
        // 将整个字符串拆分成各个数
        vector<string> nums;
        for (int i = 1, j = 1; j < array.size(); j++) {
            if (array[j] == ',' || array[j] == ']') {
                string num = array.substr(i, j - i);
                nums.push_back(num);
                i = j + 1;
            }
        }
        // 按自定义规则排序
        sort(nums.begin(), nums.end(), [&](const string& a, const string& b){
            return a + b > b + a;
        });
        // 打印结果
        string res = "";
        for (auto& num : nums) res += num;
        cout << res << endl;
        return 0;
    }
    ```

- SQL康复训练

- review每个专题  



### 第n个阶段

- 有一些算法有点难以理解，~~但是在各大卷王群里却又非常的常见~~，所以record一下，后续方便学习
- 二叉树各大遍历的mirror遍历
- 回文子串的马拉车算法  









# Thinking

- y总说过的一句话：我们不要自己去创造算法，而是应该尽可能模仿前人总结好的，特别经得起推敲的算法模板
- tag总结：https://www.zhihu.com/question/386655212/answer/2000784992
- 善于总结观察，做到看到题目就明白是用哪种方法，尝试一题多解
- 任何答案后续的优化都是出于反复的思考，总结出来的经验
  - 所以，做题的时候，首要任务是把问题解决，然后再利用平时的经验来对问题进行优化
- 发现字节很喜欢考leetcode的变种题，就是把两道leetcode组合在一起，非常的考验做题家的总结和应对能力
- 还有，有些题目（求两数组的中位数）其实在自己训练的时候，是要自己动脑筋去想去理解的，但是对于面试来说，其实只需要朗诵即可....（虽然听起来很功利，但是对于我这种能力不太行的人来说，是这样的...）
- 多学有关cpp和stl的语法以及有关类型的api，建议都用cppreference去查
- 学会看leetcode的报错
- https://leetcode-cn.com/circle/discuss/qJXzLU/
- https://www.nowcoder.com/discuss/996978








### 刷lc的几个步骤

- 第一点，cpp的语法要基本过关，不能因为错误的语法导致无法free bug（这会给面试官很差的印象）
- 第二点，读懂题目的要求，注意数据范围、时空间复杂度等限制，并且要能够辨认当前的题目是什么tag（什么tag就用什么套路和模板，适时要根据题目做出适当的变化，比如说一些边界情况）
- 第三点，能够用熟悉的语言描述出自己的想法（这里很多时候用到的其实都是肌肉记忆，就和背书一样）
- 第四点，自己写一些数据做测试样例，校验答案  

  



### 临场反应

- 注意变量命名的细节
- 控制每次写题的时间
- 重点还是要多背模板
- 在面对不会（没背过）的题目的时候，首要问题是free bug的情况下解决问题，后续再想去优化
