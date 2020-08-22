/**
 * created: 30.03.2020
 * reference: https://drken1215.hatenablog.com/entry/2018/06/08/210000
**/

#include <bits/stdc++.h>
using namespace std;

/* MAXが入力される値より大きくなっていることを確認する */
const int MAX = 510'000;
const int MOD = 1'000'000'007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}
