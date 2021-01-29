#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> par; // 親(根ではない)
    vector<int> siz; // 木のサイズ

public:
    // コンストラクタ
    UnionFind(int n)
    {
        par.assign(n, 1);
        siz.assign(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
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
    int size(int x)
    {
        return siz[find(x)];
    }
};
int main()
{
    UnionFind uf(10);
    uf.unite(1, 2);
    assert(uf.same(0, 1) == false);
    assert(uf.same(1, 2) == true);
    assert(uf.find(2) == 1);
    assert(uf.size(1) == 2);
}