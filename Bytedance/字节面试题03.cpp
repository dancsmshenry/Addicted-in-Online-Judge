#include <iostream>
#include <stack>

using namespace std;

/*jd：用一个栈实现以下功能：能够在O（1）的时间内获取当前栈中的max和min
思路：每个节点设为结构体，每个结构体中有max和min，每次放入新的节点的时候，就利用栈顶结点和当前的值来维护当前的max和min*/

class Node {
public:
    int max_number;
    int min_number;
};

class Stack {
public:
    stack<Node> s1;

    void push(int number) {
        if (s1.empty()) {
            s1.push({number, number});
        } else{
            s1.push({max(number, s1.top().max_number), min(number, s1.top().min_number)});
        }

        return ;
    }

    void pop() {
        s1.pop();
        return ;
    }

    int get_max() {
        if (s1.empty()) {
            return INT_MAX;
        }
        return s1.top().max_number;
    }

    int get_min() {
        if (s1.empty()) {
            return INT_MIN;
        }
        return s1.top().min_number;
    }
};

int main() {

}