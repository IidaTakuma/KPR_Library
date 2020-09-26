/**
 * created: 10.06.2020
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

// N: かける数, P: 指数, M: MOD
ll RepeatSquaring(ll N, ll P, ll M)
{
    if (P == 0)
        return 1;
    if (P % 2 == 0)
    {
        ll t = RepeatSquaring(N, P / 2, M);
        return t * t % M;
    }
    return N * RepeatSquaring(N, P - 1, M);
}

int main()
{
    ll num = RepeatSquaring(2, 1000000000, MOD);
    cout << num << endl;
    return 0;
}