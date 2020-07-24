/**
 * created: 23.05.2020
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 数値を受け取り素因数分解の結果を返す
// 計算量はおおよそO(√N)
// 形式：12 -> [[2, 2], [3, 1]]
vector<pair<ll, ll>>
factorization(ll num)
{
    map<ll, ll> mp;

    ll tmp = num;
    for (ll i = 2; i * i <= num; i++)
    {
        while (tmp % i == 0)
        {
            mp[i]++;
            tmp /= i;
        }
    }
    if (tmp != 1)
    {
        mp[tmp]++;
    }
    vector<pair<ll, ll>> ret;
    for (auto m : mp)
    {
        ret.push_back(make_pair(m.first, m.second));
    }
    return ret;
}

int main()
{
    int num = 12;
    auto fac = factorization(12);
    for (auto f : fac)
    {
        cout << '[' << f.first << ", " << f.second << ']';
    }
    cout << endl;
}
