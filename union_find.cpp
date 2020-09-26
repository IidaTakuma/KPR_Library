/**
 * created: 22.06.2020
 * reference: ありほん
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 100000; // 要素数の最大

int par[MAX_N]; // 親
int siz[MAX_N]; // 木のサイズ

// n要素で初期化
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }
}

// 木の根を求める
int find(int x)
{
    while (par[x] != x)
        x = par[x] = par[par[x]];
    return x;
}

// xとyの属する集合を併合
bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;

    if (siz[x] < siz[y])
        swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
}

// 頂点xと頂点yが同じ木に属するかを判定する
bool same(int x, int y)
{
    return find(x) == find(y);
}

// xが属する木の大きさを返す
ll size(int x)
{
    return siz[find(x)];
}

int main()
{
}