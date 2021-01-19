/* 
 * 問題サンプル
     * ABC_188_F Peddler
     * https://atcoder.jp/contests/abc188/tasks/abc188_e
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 58;

// グラフから出次数を計算する関数
vector<int> calc_indegree(vector<vector<int>> &G)
{
    vector<int> ret(G.size(), 0);
    for (vector<int> v : G)
    {
        for (int to : v)
        {
            ret[to]++;
        }
    }
    return ret;
}

// トポロジカルソートを実行する関数
vector<int> topological_sort(vector<vector<int>> &G, vector<int> &indegree)
{
    vector<int> sorted_vertices;

    queue<int> que;
    for (int i = 0; i < (int)G.size(); ++i)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (int i = 0; i < (int)G[v].size(); ++i)
        {
            int u = G[v][i];
            indegree[u]--;
            if (indegree[u] == 0)
                que.push(u);
        }
        sorted_vertices.push_back(v);
    }
    return sorted_vertices;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        graph[x].push_back(y);
    }

    vector<int> indegree = calc_indegree(graph);
    vector<int> sorted_vertices = topological_sort(graph, indegree);

    // ある町までの仕入れの最安値を記録する
    // 最安値のみを伝播する

    vector<ll> mini(n, LINF); // その頂点までが利用しうる最小の仕入れ値

    ll ans = -LINF;

    for (auto i : sorted_vertices)
    {
        ans = max(ans, a[i] - mini[i]);
        for (int v : graph[i])
        {
            mini[v] = min(mini[v], min(mini[i], a[i])); // 次の頂点の最小値を更新する
        }
    }
    cout << ans << endl;
    return 0;
}