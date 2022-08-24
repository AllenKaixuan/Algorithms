/*
0-1背包问题，采用动态规划算法，采用两个变量描述
子问题：
1.物品数量
2.剩余空间
动态规划基本方程：
1.不把第i个物品放入
2.放入该物品，改变数量及空间
*/
#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) //从0开始，直到n
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

// 空间复杂度优化，因为每次只使用本列以及上一列的数据，因此可以只
// 使用两列数组，每次迭代更新即可

int knapSackOpt2D(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[2][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i % 2][w] = 0; // 通过i%2来控制
            else if (wt[i - 1] <= w)
                K[i % 2][w] = max(
                    val[i - 1] + K[(i - 1) % 2][w - wt[i - 1]],
                    K[(i - 1) % 2][w]);
            else
                K[i % 2][w] = K[(i - 1) % 2][w];
        }
    }
    return K[n % 2][W];
}

// 使用memorization方法，不用像tabulation求出所有值

int knapSackRec(int W, int wt[],
                int val[], int i,
                int **dp)
{
    if (i < 0)
        return 0;
    if (dp[i][W] != -1) // 存储中间计算结果
        return dp[i][W];

    if (wt[i] > W)
    {

        dp[i][W] = knapSackRec(W, wt,
                               val, i - 1,
                               dp);
        return dp[i][W];
    }
    else
    {
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i],
                                            wt, val,
                                            i - 1, dp),
                       knapSackRec(W, wt, val,
                                   i - 1, dp));

        return dp[i][W];
    }
}

int knapSackMemo(int W, int wt[], int val[], int n)
{
    // 初始化dp表
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);

    return 0;
}