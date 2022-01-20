int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int i, j, high = gridColSize[0];
    int dp[1000][1000];
    if (gridSize == 0 || high == 0) return 0;
    dp[0][0] = grid[0][0];

    for (i = 1; i < gridSize; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (j = 1; j < high; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (i = 1; i < gridSize; i++) 
    {
        for (j = 1; j < high; j++)  
            dp[i][j] = (dp[i][j - 1] < dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j]) + grid[i][j];
    }

    return dp[gridSize - 1][high - 1];
}