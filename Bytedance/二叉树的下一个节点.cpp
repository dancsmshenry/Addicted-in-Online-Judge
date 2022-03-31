/**
 * 给定二叉树其中的一个节点，请找出其中序遍历顺序的下一个节点并返回
 * 注意，树中的节点不仅包含左右子节点，还包含指向父节点的指针
 * 参考：https://mp.weixin.qq.com/s/yewlHvHSilMsrUMFIO8WAA
*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //父节点
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode -> right) { //如果有右子树，则找右子树的最左节点
            TreeLinkNode *mid = pNode -> right;
            while(mid -> left) {
                mid = mid -> left;
            }
            return mid;
        }

        TreeLinkNode *p = pNode;
        //如果没有左子树，那就看当前节点是不是父节点的左子树，如果是，就返回父节点；否则（当前就是右子树），就继续往上找
        while(p -> next) { //没右子树，则找第一个当前节点是父节点左孩子的节点
            if(p -> next -> left == p) {
                return p -> next;
            }
            p = p -> next;
        }

        return nullptr; //发现当前节点是中序遍历的最后一个节点，就直接返回nullptr
    }
};