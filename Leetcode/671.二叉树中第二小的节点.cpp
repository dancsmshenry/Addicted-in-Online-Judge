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
public:
    int ans = -1; // һ��ʼΪ-1����ʾ��ǰ��û�и��¹�
    int rootvalue; // ��¼��ǰ����Сֵ

    int findSecondMinimumValue(TreeNode* root) {
        rootvalue = root->val; // �趨��ǰ����Сֵ
        dfs(root); // ����
        return ans;
    }

    void dfs(TreeNode* node) {
         if (!node) { // ����ǿս��Ļ�����ֱ���˳�
            return;
        }

        if (ans != -1 && node->val >= ans) { 
            // �����ǰ��ans�����¹��ˣ����ҵ�ǰ����ֵ����ans�����ʾ��������еĽ�㶼��ansҪ��
            // �Ϳ��Բ����������ˣ�ֱ���˳�
            // �������������Ҫô����ans=-1����ǰ��û�и��¹�ans
            // Ҫô����node ->val < ans����ʾ���������ѵı�Ҫ��˵�����ڱ�ans��ҪС�����Ǳ�rootvalue������֣�
            return;
        }

        if (node->val > rootvalue) {
            // �����ǰ��ֵ����Сֵ��Ļ����͸���ans���ص㻹������һ���������˺ܶණ����
            ans = node->val;
        }

        dfs(node->left); // ����
        dfs(node->right); // ����
    }
};