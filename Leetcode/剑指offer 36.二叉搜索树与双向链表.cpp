/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr){
            return nullptr;
        }

        dfs(root);

        //dfs后，head为头结点，pre为尾结点，这里是让头为节点互连
        head->left = pre;
        pre->right = head;

        return head;
    }
private:
    Node *pre, *head;
    void dfs(Node* cur) {
        if(cur == nullptr){
            return ;
        }

        //这道题的根本思路就是中序遍历，左根右，就像一条蛇一样，先一直往右边游，游到底了就逐层逐层回去
        dfs(cur->left);

        //这里有点难理解，可以这样想：
        //1、因为是中序遍历，所以会一直往左边走，一直执行dfs的语句，直到最左边的那个点，才开始执行这条语句
        //2、而一开始，pre和head都是空的
        //注意，既然是最左边的点，所以它就是head了

        //ps:因为一开始就确认了head，所以后续就不会有变化了，后面的代码就不会变动head了；
        //ps:这里的pre是用来储存对于当前结点来说的前一个结点（是不是就像蛇一样，先走了左子树，pre为左子树最大的点，然后再连上root，
        //接着root为最大的点，再连上右子树）

        //总结：head就是一直往左走，找到最左边的点；pre就是记录走过了前面那么多的路的时候，对于当前的点的前面一个点
        //所以如果pre为空，就代表head还没找到，所以定义head；不为空，而pre为前一个结点，所以就连起来（pre->right = cur;cur->left = pre;）
        if(pre != nullptr){
            pre->right = cur;
        }else{
            head = cur;
        }
        cur->left = pre;

        //此时，右边和该结点都已经处理好了，要处理右子树了，那对于右子树来说，它的pre就是当前的点
        pre = cur;

        //右走
        dfs(cur->right);
    }
};

// 非递归版
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        stack<Node*> s1;
        Node *res = nullptr, *result = nullptr;

        while (!s1.empty() || root) {
            while (root) {
                s1.push(root);
                root = root -> left;
            }
            root = s1.top();
            s1.pop();
            if (res) {
                res -> right = root;
                root -> left = res;
                res = root;
            } else {
                result = root;
                res = root;
            }
            root = root -> right;
        }
        
        res -> right = result;
        result -> left = res;
        return result;
    }
};