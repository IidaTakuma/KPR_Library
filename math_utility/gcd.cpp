/**
 * created: 23.05.2020
**/

/**
 * gcd : 配列の最大公約数を求める
 * __gcd : 2数の最大公約数を求める(STL)
**/

#include <bits/stdc++.h>
using namespace std;

int gcd(vector<int> vec)
{
    int ret = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        ret = __gcd(ret, vec[i]);
    }
    return ret;
}

int main()
{
    vector<int> vec = {12, 20, 24};
    cout << gcd(vec) << endl;
    return 0;
}