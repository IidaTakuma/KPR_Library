#include <bits/stdc++.h>

using namespace std;

/* 2点を結ぶ2つの直線の交差を判定 */
bool judge(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
    int ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    int tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    int tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    int td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return ((tc * td < 0) && (ta * tb < 0));
}

/* 端点がわかっている線分(1 to 2)and(3 to 4)の交差を判定 */
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

int main()
{
    return 0;
}