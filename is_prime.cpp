#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll x)
{
    if (x < 2)
        return false;
    else if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (ll i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isPrime(3) << endl;
    return 0;
}