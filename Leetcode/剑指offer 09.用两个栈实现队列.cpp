class CQueue{
private:
    stack<int> stack1,stack2;
public:
    /*创建栈的时候，把栈里面所有的元素都踢出来*/
    CQueue(){
        while (!stack1.empty()){
            stack1.pop();
        }
        while (!stack2.empty()){
            stack2.pop();
        }
    }
    
    /*stack1是用来存储后续放进来的元素*/
    void appendTail(int value){
        stack1.push(value);
    }
    
    /*
        对于删除，我们是将stack1反转到stack2
        即反转后，stack2的pop就是踢出队列的第一个元素
        所以首先判断stack2里面有没有元素，如果没有的话，就把stack1的元素倒入stack2中
        （因为可能stack2的元素在此之前被踢出完了，所以就先判断一波，如果为空，就把stack1的元素放入）

        再判断stack2里面有没有元素，如果有的话，就直接踢出第一个即可
        如果没有，就证明stack1中也没有元素了，就返回-1
    */
    int deleteHead(){
        if (stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()){
            return -1;
        }else{
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */