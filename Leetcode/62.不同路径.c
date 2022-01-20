int uniquePaths(int m, int n)
{
    int i, j;
    int **f = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) 
    {
        f[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || j == 0) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
        
    }
    return f[m - 1][n - 1];
}