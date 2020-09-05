#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char del)
{
    vector<string> ret;
    string subStr;
    for (const char c : str)
    {
        if (c == del)
        {
            ret.push_back(subStr);
            subStr.clear();
        }
        else
        {
            subStr += c;
        }
    }
    ret.push_back(subStr);
    return ret;
}