#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * 初期化
    * Segtree<X, モノイド, 単位元>
 * メンバ関数 
    * set(i, x): i番目の要素をxに更新．O(log(n))
    * get(i): i番目の要素を取得. O(1)
    * prod(l, r): op([a[l]...a[r - 1])を返す. O(log(n))
    * all_prod(): op(a[0]...a[n - 1])を返す. O(1)
**/

template <class X, X (*op)(X, X), X (*e)()>
struct SegTree
{
private:
    int _n, log, size;
    vector<X> d;

public:
    SegTree() : SegTree(0) {}
    explicit SegTree(int n) : SegTree(vector<X>(n, e())) {}
    explicit SegTree(const vector<X> &v) : _n(int(v.size()))
    {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<X>(2 * size, e());
        for (int i = 0; i < _n; ++i)
        {
            d[size + i] = v[i];
        }
        for (int i = size - 1; i >= 1; --i)
        {
            update(i);
        }
    }

    void set(int p, X x)
    {
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; ++i)
            update(p >> i);
    }

    X get(int p)
    {
        return d[p + size];
    }

    X prod(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        X sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r)
        {
            if (l & 1)
                sml = op(sml, d[l++]);
            if (r & 1)
                smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    X all_prod()
    {
        return d[1];
    }

private:
    void update(int k)
    {
        d[k] = op(d[2 * k], d[2 * k + 1]);
    }

    int ceil_pow2(int n)
    {
        int x = 0;
        while ((1U << x) < (unsigned int)(n))
            x++;
        return x;
    }
};

// セグメント木の二項演算
int op(int a, int b)
{
    return a ^ b;
}

// 単位元
int e()
{
    return 0;
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    SegTree<int, op, e> seg(a);

    for (int q = 0; q < Q; ++q)
    {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1)
        {
            // 元の値
            int v = seg.get(x);

            // 変更後の値
            v ^= y;

            // 更新
            seg.set(x, v);
        }
        else
        {
            cout << seg.prod(x, y) << endl;
        }
    }
}
