#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 数値の各桁の和を求める
int digitSum(ll n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

// 数値の桁数を求める
int digit(ll n)
{
    int res = 0;
    while (n > 0)
    {
        ++res;
        n /= 10;
    }
    return res;
}