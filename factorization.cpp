/**
 * created: 23.05.2020
**/

#include <bits/stdc++.h>
using namespace std;

// 数値を受け取り素因数分解の結果を返す
// 形式：12 -> [[2, 2], [3, 1]]
vector<pair<int, int>> factorization(int num)
{
    map<int, int> mp;
    int n = 2;
    while (num != 1)
    {
        if (num % n == 0)
        {
            mp[n]++;
            num /= n;
            continue;
        }
        n++;
    }
    vector<pair<int, int>> ret;
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