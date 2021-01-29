#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1000000007;

void warshall_floyd(int n, vector<vector<ll>> &G)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return;
}

int main()
{
    int n = 5;
    vector<vector<ll>> G(n, vector<ll>(n, INF));
    // グラフの構築
    G[0][1] = 2;
    G[1][2] = 3;
    G[2][3] = 1;
    G[0][3] = 7;
    G[2][4] = 2;
    warshall_floyd(n, G);
    assert(G[0][4] == 7);
    assert(G[0][3] == 6);
    return 0;
}