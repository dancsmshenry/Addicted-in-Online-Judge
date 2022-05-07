class Solution {
private:
    int flag = 0;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        flag = image[sr][sc];
        if (image[sr][sc] != newColor) { // ���������ӣ������ǰ��ɫ��newcolor��ȣ��Ͳ���dfs��..
            dfs(image, sr, sc, newColor);
        }
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor) {
        image[sr][sc] = newColor;
        for (auto&& direction: directions) {
            int i = sr + direction[0], j = sc + direction[1];
            if (i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && image[i][j] == flag) {
                dfs(image, i, j, newColor);
            }
        }
    }
};