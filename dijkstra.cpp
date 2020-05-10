/**
 * created: 30.03.2020
 * reference: https://www.slideshare.net/yosupo/ss-46612984
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

using P = pair<ll, ll>;
const int V = 10000;
vector<P> G[V]; // pair<辺の距離, 行き先の頂点> (隣接リスト)
ll dist[V];     // dist[i]はsから頂点iへの最短距離が入る
bool used[V];
void dijkstra(ll s)
{ // s: 始点
    fill_n(dist, V, INT_MAX);
    fill_n(used, V, false);
    priority_queue<P, vector<P>, greater<P>> q; // 値が小さい順に取り出されるpriority_queue
    q.push(P(0, s));
    while (!q.empty())
    {
        ll d, t; // d: sからの距離 t: 行き先
        tie(d, t) = q.top();
        q.pop();
        if (used[t])
            continue; // 既に探索済か
        used[t] = true;
        dist[t] = d;
        for (P e : G[t])
        {
            if (dist[e.second] <= d + e.first)
                continue;
            q.push(P(d + e.first, e.second));
        }
    }
}

/**
 * sample: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
**/

int main()
{
    cin >> n;
    ll u, k, v, c;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v >> c;
            G[u].push_back(make_pair(c, v));
        }
    }
    dijkstra(0); // 頂点0からの最短経路を求める

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    return 0;
}