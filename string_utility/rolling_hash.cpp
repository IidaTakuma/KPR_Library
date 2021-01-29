#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

/** Rolling Hash **/

// params start
const int LENGTH = 5001; // 文字列の長さ
// params end

const ull MASK30 = (1UL << 30) - 1;
const ull MASK31 = (1UL << 31) - 1;
const ull MOD = (1UL << 61) - 1;
const ull MASK61 = MOD;
const ull POSITIVIZER = MOD * ((1UL << 3) - 1);
const unsigned int Base = 1000000007;
ull powMemo[LENGTH];
ull hashes[LENGTH];

//mod 2^61-1を計算する関数
ull CalcMod(ull x)
{
    ull xu = x >> 61;
    ull xd = x & MASK61;
    ull res = xu + xd;
    if (res >= MOD)
        res -= MOD;
    return res;
}

//a*b mod 2^61-1を返す関数(最後にModを取る)
ull Mul(ull a, ull b)
{
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return CalcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
}

ull Slice(int start, int length)
{
    return CalcMod(hashes[start + length] + POSITIVIZER - Mul(hashes[start], powMemo[length]));
}

void rolling_hash(string const &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i + 1] = CalcMod(Mul(hashes[i], Base) + s[i]);
    }
    powMemo[0] = 1;
    for (int i = 1; i < LENGTH; i++)
    {
        powMemo[i] = CalcMod(Mul(powMemo[i - 1], Base));
    }
}

int main()
{
    string S;
    cin >> S;
    // 初期化
    rolling_hash(S);
    if (Slice(1, 3) == Slice(4, 3))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}