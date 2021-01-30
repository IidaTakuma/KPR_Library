#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 28;
const int MAX_V = 17;

int grid[MAX_V][MAX_V];    // 隣接行列
int dp[1 << MAX_V][MAX_V]; // dp[通った状態の集合][頂点]

// 最短ハミルトン路
void hamilton(int n)
{
    for (int i = 0; i < n; ++i)
    {
        dp[1 << i][i] = 1;
    }

    for (int s = 0; s < (1 << n); ++s) // 状態
    {
        for (int v = 0; v < n; ++v) // 遷移前の頂点
        {
            if (dp[s][v] >= INF)
                continue;
            for (int next_v = 0; next_v < n; ++next_v) // 遷移先
            {
                if (v == next_v)
                    continue;
                if ((s >> next_v) % 2 == 0)
                {
                    int new_s = s + (1 << next_v);
                    int new_cost = dp[s][v] + grid[v][next_v];
                    dp[new_s][next_v] = min(dp[new_s][next_v], new_cost);
                }
            }
        }
    }
}