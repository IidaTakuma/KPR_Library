/**
 * created: 22.06.2020
 * reference: ありほん
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100000; // 要素数の最大

int par[MAX_N]; // 親
int rk[MAX_N];  // 木の深さ(rank)

// n要素で初期化
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rk[i] = 0;
    }
}

// 木の根を求める
int find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }

    if (rk[x] < rk[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rk[x] == rk[y])
        {
            rk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
}