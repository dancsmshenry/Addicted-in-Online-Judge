class Solution {
public:
    map<int, vector<pair<int, int>>> position;//好巧妙的数据结构啊
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, 0);

        for(pair<int, vector<pair<int, int>>> p: position){//map里面的元素用pair来访问
            sort(p.second.begin(), p.second.end());//根据vector<pair<int, int>>里面的第一个元素来排序的，即对于同一列的元素，对其行数进行排序
            vector<int> mid;
            for(pair<int, int>& x: p.second){
                mid.push_back(x.second);
            }  
            res.push_back(mid);
        }
        return res;
    }

    void dfs(TreeNode* node, int row, int col){
        if(!node) {
            return;
        }

        position[col].push_back({row, node->val});
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
};

/*
    还有一种思路：
    设置一个三元组，分别存放元素的纵坐标，横左边和value
    然后用dfs把他们全部都记录下来
    接着对存放这个三元组的vector进行排序
    先对纵坐标进行排序，纵坐标相同就用横坐标进行比较，再不行就用value进行比较
*/