#include <bits/stdc++.h>

using namespace std;

/* 
 * created: 23.01.2021
 * reference: http://i-health.u-aizu.ac.jp/CompuGeo/2017/handouts/chapter2/Chapter2H2.pdf
 * sample task: https://atcoder.jp/contests/abc016/tasks/abc016_4
 */

struct Point
{
    double x;
    double y;
    Point()
    {
        Point(0, 0);
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
};

// 面積計算(符号付き)
double calc_S(Point a, Point b, Point c)
{
    return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2;
}

// 線分abと線分cdの交差判定
bool isCross(Point a, Point b, Point c, Point d)
{
    double S_abc = calc_S(a, b, c);
    double S_abd = calc_S(a, b, d);
    double S_cda = calc_S(c, d, a);
    double S_cdb = calc_S(c, d, b);

    // 線分の交差判定
    if ((S_abc * S_abd < 0) && (S_cda * S_cdb) < 0)
    {
        return true; // 交差
    }
    if (S_abc == 0 || S_abd == 0 || S_cda == 0 || S_cdb == 0)
    {
        return true; // 三点が同一直線状に存在
    }
    return false;
}

int main()
{
    Point a, b;
    int n;
    cin >> a.x >> a.y >> b.x >> b.y >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    int cross_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (isCross(a, b, p[i], p[(i + 1) % n]))
        {
            cross_cnt++;
        }
    }
    cout << (cross_cnt / 2) + 1 << endl;
    return 0;
}

/* ========================================================================================

// 2点を結ぶ2つの直線の交差を判定
bool judge(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
    int ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    int tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    int tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    int td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return ((tc * td < 0) && (ta * tb < 0));
}

// 端点がわかっている線分(1 to 2)and(3 to 4)の交差を判定
bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    // 並行な場合
    int rm = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3);
    if (rm == 0)
        return false;
    int sm = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3);
    if (sm == 0)
        return false;
    // 媒介変数の値が0より大きく1以下なら交差
    double r = (double)((y4 - y3) * (x3 - x1) - (x4 - x3) * (y3 - y1)) / rm;
    double s = (double)((y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1)) / sm;
    return (0 < r && r <= 1 && 0 < s && s <= 1);
};

======================================================================================== */