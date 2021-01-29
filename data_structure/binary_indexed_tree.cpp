/**
 * created: 04.10.2020
 * reference1: https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
 * reference2: https://www.slideshare.net/hcpc_hokudai/binary-indexed-tree
 * sample problem: https://atcoder.jp/contests/practice2/tasks/practice2_b
**/

// ACLとの相違点
// 1-indexである
// オーバーフロー時の動作を明記していない

#include <bits/stdc++.h>
using namespace std;

// 1-indexed
class BIT
{
public:
    long long n;           // データの長さ
    vector<long long> bit; // データの格納先
    BIT(long long n)
        : n(n), bit(n + 1, 0) {} // コンストラクタ

    // bit[i]にxを加算する
    void add(long long i, long long x)
    {
        if (i == 0)
            return;
        for (long long k = i; k <= n; k += (k & -k))
            bit[k] += x;
    }

    // bit_1 + bit_2 + ... + bit_i をO(log(n))で求める
    long long sum(long long i)
    {
        long long s = 0;
        if (i == 0)
            return s;
        for (long long k = i; k > 0; k -= (k & -k))
            s += bit[k];
        return s;
    }

    // a_1 + a_2 + ... + a_i >= xとなるような最小のiを求める(a_k >= 0)
    // xが0以下の場合は該当するもの無し->「0」を返す
    long long lower_bound(long long x)
    {
        if (x <= 0)
            return 0;
        else
        {
            long long i = 0, r = 1;
            // 最大としてありうる区間の長さを取得する
            // n以下の最小の二乗の冪(BITで管理する数列の区間で最大のもの)を求める
            while (r < n)
                r = r << 1;
            // 区間の長さは調べるごとに半分になる
            for (int len = r; len > 0; len = len >> 1)
            {
                // その区間を採用する場合
                if (i + len < n && bit[i + len] < x)
                {
                    x -= bit[i + len];
                    i += len;
                }
            }
            return i + 1;
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        bit.add(i, a);
    }
    for (int i = 0; i < q; ++i)
    {
        int mode;
        cin >> mode;
        if (mode == 0)
        {
            int p, x;
            cin >> p >> x;
            bit.add(p + 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(r) - bit.sum(l) << endl;
        }
    }
    return 0;
}