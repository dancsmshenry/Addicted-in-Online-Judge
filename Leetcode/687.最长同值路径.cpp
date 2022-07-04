/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int result{};
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, -1);
        return result;
    }

    //  �����dfs���ط��������ǣ���ʱ��root -> val����number�����Դ�ʱdfs�ķ���ֵ������ǽڵ�ֵΪnumber�� ��һ���� ������������ܹ�ȡ������ֵ��ע������һ�㣩
    int dfs(TreeNode *root, int number) {
        //  �����ǰû�нڵ㣬��rootΪnullptr���ͷ���0
        if (!root) {
            return 0;
        }

        // ����ͺͶ�������ֱ��һ���ˣ�Ҳ��Ҫ�����ߵ�ֵ������ȥ���·��
        int n1 = dfs(root -> left, root -> val), n2 = dfs(root -> right, root -> val);
        result = max(result, n1 + n2);

        //  ���ߣ���ǰ�ڵ��ǰһ������ֵ����ͬ��Ҳ����0��ps��ΪʲôҪ�����ﷵ�أ�����Ϊ���ǻ�Ҫ������һ���Դ�ʱ��root->valΪ���ڵ��·�������Ƿ������������
        if (root -> val != number) {
            return 0;
        }

        // ���ܻ����˺���Ϊʲô����Ҫ��һ�������������n1��n2��һ�����������뷨��dfs���ص����Ե�ǰ���Ϊ���ڵ���·����
        // ��Ϊ�������ǲ�ȷ����ǰ������ڵ���ҽڵ��Ƿ���ڵ�ǰ���
        // ��������ڵĻ�����ôֱ����n1��n2����+1�ͻᵼ�½���Ĵ���
        // �ڻ���˵������Ҷ�ӽڵ�����ĸ��ڵ�����ͬ�ģ�����Ҷ�ӽ����Ϊ����д�����ص���0����ô��ʱ���ڵ�ͻ���ȥ�ж�������ҽ�㵽�׺����಻��ȣ��ͻ����coding�ϵ��鷳
        // ��Ҫ�ܽ᣺ LC124-->LC543-->LC687-->LC2246
        return max(n1, n2) + 1;
    }
};