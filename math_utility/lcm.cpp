/**
 * created: 23.05.2020
**/

/**
 * lcm : 配列の最小公倍数を求める
 * __lcm : 2数の最小公倍数を求める
**/

#include <bits/stdc++.h>
using namespace std;

int __lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

int lcm(vector<int> vec)
{
    int ret = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        ret = __lcm(ret, vec[i]);
    }
    return ret;
}

int main()
{
    vector<int> vec = {2, 10, 13, 50};
    cout << lcm(vec) << endl;
    return 0;
}