#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll combination(int n, int r)
{
    ll numerator = 1;
    ll denominator = 1;
    for (int i = 0; i < r; i++)
    {
        numerator *= n - i;
        if (numerator % (i + 1) == 0)
        {
            numerator /= (i + 1);
        }
        else
        {
            denominator *= (i + 1);
        }
    }
    return numerator / denominator;
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << combination(n, r) << endl;
    return 0;
}