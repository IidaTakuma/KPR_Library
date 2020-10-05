/**
 * created: 05.10.2020
 * reference1: https://algo-logic.info/segment-tree
 * reference2: https://atcoder.github.io/ac-library/master/document_ja/segtree.html
 * sample problem: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
**/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * Segtree<X>(n, fx, ex):モノイド(集合X，二項演算fx，単位元ex)についてサイズnで構築
 * set(int i, int x), build(): i番目の要素をxにセット．まとめてセグ木を構築する．O(n)
 * update(i, x): i番目の要素をxに更新．O(log(n))
 * query(a, b): [a, b)全てにfxを作用させた値を取得．O(log(n))
 * [未実装]find_rightest(a, b, x): [a, b) で{モノイドの作用}の要素を持つ最右位置を求める．O(log(n))
 * [未実装]find_leftest(a, b, x): [a, b) で{モノイドの作用}の要素を持つ最左位置を求める．O(log(n))
**/
template <typename X>
struct SegTree
{
    using FX = function<X(X, X)>; // X・X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    // コンストラクタ
    SegTree(int n_, FX fx_, X ex_)
        : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_)
    {
        int x = 1;
        while (n_ > x)
            x *= 2;
        n = x;
    }

    void set(int i, X x)
    {
        dat[i + n - 1] = x;
    }

    void build()
    {
        for (int k = n - 2; k >= 0; --k)
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x)
    {
        i += n - 1;
        dat[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2; // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b)
    {
        return query_sub(a, b, 0, 0, n);
    }

    X query_sub(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return ex;
        else if (a <= l && r <= b)
            return dat[k];
        else
        {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    // int find_rightest(int a, int b, T x)
    // {
    //     return find_rightest_sub(a, b, x, 0, 0, n);
    // }

    // int find_leftest(int a, int b, T x)
    // {
    //     return find_leftest_sub(a, b, x, 0, 0, n);
    // }

    // int find_rightest_sub(int a, int b, T x, int k, int l, int r)
    // {
    //     // 自分の位置がxより大きい or [a, b)が[l, r)の範囲外ならreturn a-1
    //     if (dat[k] > x || r <= a || b <= l)
    //         return a - 1;
    //     else if (k >= n - 1) // 自分が葉ならその位置をreturn
    //         return (k - (n - 1));
    //     else
    //     {
    //         int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
    //         if (vr != a - 1) // 右の部分木を見て a-1 以外ならreturn
    //             return vr;
    //         else // 左の部分木を見て値をreturn
    //             return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
    //     }
    // }
};

int main()
{
    auto fx = [](int a, int b) -> int { return min(a, b); }; // モノイド
    int n, q;
    cin >> n >> q;
    SegTree<int> st(n, fx, INT32_MAX);

    // クエリを処理する
    for (int i = 0; i < q; ++i)
    {
        int mode, x, y;
        cin >> mode >> x >> y;
        if (mode == 0)
        {
            st.update(x, y);
        }
        else if (mode == 1)
        {
            cout << st.query(x, y + 1) << endl;
        }
    }
    return 0;
}
