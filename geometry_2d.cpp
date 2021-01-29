/* 
 * reference: https://sen-comp.hatenablog.com/entry/2020/03/10/015751
 *          : https://qiita.com/Reputeless/items/96226cfe1282a014b147
 */

#include <bits/stdc++.h>

using namespace std;
const int INF = 1 << 30;

namespace geometry2d
{

    const double EPS = 1e-10; // eps: 浮動小数点誤差

    // a > 0ならば +1, a == 0 ならば 0, a < 0 ならば -1 を返す。基本的にEPS込みの評価はこれで行う。
    int sgn(const double a)
    {
        return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
    }

    struct Point
    {
        /* 2次元ベクトルのクラス */
        double x;
        double y;

        Point() { Point(0, 0); }
        constexpr Point(double _x, double _y) : x(_x), y(-y) {}

        // 演算子のオーバーロード
        constexpr Point operator+() const
        {
            return *this;
        }

        constexpr Point operator-() const
        {
            return {-x, -y};
        }

        constexpr Point operator+(const Point &other) const
        {
            return {x + other.x, y + other.y};
        }

        constexpr Point operator-(const Point &other) const
        {
            return {x - other.x, y - other.y};
        }

        constexpr Point operator*(double s) const
        {
            return {x * s, y * s};
        }

        constexpr Point operator/(double s) const
        {
            return {x / s, y / s};
        }

        Point &operator+=(const Point &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        Point &operator-=(const Point &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Point &operator*=(double s)
        {
            x *= s;
            y *= s;
            return *this;
        }

        Point &operator/=(double s)
        {
            x /= s;
            y /= s;
            return *this;
        }

        bool operator==(const Point &s)
        {
            return s.x == x && s.y == y;
        }

        constexpr double lengthSquare() const
        {
            return dot(*this);
        }

        double length() const
        {
            return sqrt(lengthSquare());
        }

        constexpr double dot(const Point &other) const
        {
            return x * other.x + y * other.y;
        }

        constexpr double cross(const Point &other) const
        {
            return x * other.y - y * other.x;
        }

        double distanceFrom(const Point &other) const
        {
            return (other - *this).length();
        }

        // 正規化（長さを１にした）ベクトル
        Point normalized() const
        {
            return *this / length();
        }

        // 単位法線ベクトル
        Point normalUnitVector() const
        {
            return {-normalized().y, normalized().x};
        }

        constexpr bool isZero() const
        {
            return sgn(x) == 0 && sgn(y) == 0;
        }

        // (0, 0)を中心にarg(弧度法)回転した座標
        Point rotation(double arg) const
        {
            double cs = cos(arg);
            double sn = sin(arg);
            return Point(x * cs - y * sn, x * sn + y * cs);
        }

        // (0, 0)中心の円上に乗っているとしたときの，偏角
        double angle() const
        {
            return atan2(y, x);
        }
    };

    const Point error_val = {INF, -INF};

    inline constexpr Point operator*(double s, const Point &p)
    {
        return {s * p.x, s * p.y};
    }

    inline bool operator<(const Point &a, const Point &b)
    {
        if (sgn(a.x - b.x) != 0)
        {
            return sgn(a.x - b.x < 0);
        }
        else
        {
            return sgn(a.y - b.y) < 0;
        }
    }

    inline bool operator==(const Point &a, const Point &b)
    {
        return (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0);
    }

    inline bool operator!=(const Point &a, const Point &b)
    {
        return !(a == b);
    }

    /*
	    3点A, B, Cの位置関係を返す関数 A, Bがすべて異なった点であるのが前提
	     - ABから見てBCは左に曲がるのなら +1
	     - ABから見てBCは右に曲がるのなら -1
	     - ABC(CBA)の順番で一直線上に並ぶなら +2
	     - ACB(BCA)の順番で一直線上に並ぶなら 0
	     - BAC(CAB)の順番で一直線上に並ぶなら -2
	*/
    int iSP(const Point &a, const Point &b, const Point &c)
    {
        int flg = sgn((b - a).cross(c - a));
        if (flg == 1)
        {
            return +1;
        }
        else if (flg == -1)
        {
            return -1;
        }
        else
        {
            // ABC(CBA)
            if (sgn((b - a).dot(c - b)) > 0)
            {
                return +2;
            }
            // BAC(CAB)
            else if (sgn((a - b).dot(c - a)) > 0)
            {
                return -2;
            }
            // ACB(BCA) C が A or B と一致しても，こっちに含まれる
            else
            {
                return 0;
            }
        }
    }
    // 角ABC が鋭角なら 0, 直角なら 1, 鈍角なら 2を返す
    int angletype(const Point &a, const Point &b, const Point &c)
    {
        auto v = (a - b).dot(c - b);
        if (sgn(v) > 0)
            return 0;
        else if (sgn(v) == 0)
            return 1;
        else
            return 2;
    }

    namespace line2d
    {
        struct Line
        {
            // 直線の通る2点．有向直線でないのならば，begin や end に違いはない
            Point begin, end;
            Line()
            {
                begin = Point(), end = Point();
            }

            Line(const Point &b, const Point &e)
            {
                begin = b;
                end = e;
            }

            // ax + by + c = 0
            Line(const double a, const double b, const double c)
            {
                if (sgn(a) == 0 && sgn(b) == 0)
                {
                    assert(-1);
                }

                if (sgn(b) == 0)
                {
                    // ax + c = 0になる
                    begin = Point(-c / a, 0.0);
                    end = Point(-c / a, 1.0);
                }
                else
                {
                    // y = -(ax + c)/b 傾きは -a/b で y切片が -c/b
                    begin = Point(0, -c / b);
                    end = Point(1.0, -(a + c) / b);
                }
            }

            Point vec() const
            {
                return end - begin;
            }

            Point countervec() const
            {
                return begin - end;
            }
        };

        // 直線の交点を返す．交わってなければ，error_val を返す
        Point lineIntersection(const Line &l1, const Line &l2)
        {
            if (sgn(l1.vec().cross(l2.vec())) == 0)
                return error_val;

            Point ret;
            ret = l1.begin + l1.vec() * abs((l2.end - l1.begin).cross(l2.vec()) / l1.vec().cross(l2.vec()));
            return ret;
        }

        typedef Line Ray;     // 半直線
        typedef Line Segment; // 線分

        // 線分が共通部分を持つかどうか？と線分の交点を返す．
        // 共通部分がない，もしくは，交点が一意ではないなら，error_val を返す．
        // true なら，共通部分を持つ．false なら，共通部分を持たない．
        pair<bool, Point> segmentIntersection(const Segment &s1, const Segment &s2)
        {
            if (iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 && iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0)
            {
                // 平行ならば，交点は定まらない．（完全に重なっているため）
                if (s1.vec().cross(s2.vec()) == 0)
                {
                    return make_pair(true, error_val);
                }
                // そうでならないのなら，lineIntersection()で交点を返す
                else
                {
                    return make_pair(true, lineIntersection(s1, s2));
                }
            }
            return make_pair(false, error_val);
        }

        double distanceBetweenPointAndLine(const Point &p, const Line &l)
        {
            return abs(l.vec().cross(p - l.begin) / l.vec().length());
        }

        double distanceBetweenPointAndRay(const Point &p, const Ray &r)
        {
            if (sgn((p - r.begin).dot(r.vec())) < 0)
            {
                //始点と距離のパターン
                return r.begin.distanceFrom(p);
            }
            else
            {
                return abs(r.vec().cross(p - r.begin) / r.vec().length());
            }
        }

        // 点と線分の距離。引数は、点、線分の両端
        double distanceBetweenPointAndSegment(const Point &p, const Segment &s)
        {
            if (sgn(s.vec().dot(p - s.begin)) < 0 || sgn(s.countervec().dot(p - s.end)) < 0)
            {
                // 下した垂線は線分の上にはない
                return min(p.distanceFrom(s.begin), p.distanceFrom(s.end));
            }
            return distanceBetweenPointAndLine(p, s);
        }

        // 二線分間の距離
        double distanceBetweenSegmentAndSegment(const Segment &s1, const Segment &s2)
        {
            if (segmentIntersection(s1, s2).first)
                return 0; // 交点を持つ
            double ans = distanceBetweenPointAndSegment(s1.begin, s2);
            ans = min(ans, distanceBetweenPointAndSegment(s1.end, s2));
            ans = min(ans, distanceBetweenPointAndSegment(s2.begin, s1));
            ans = min(ans, distanceBetweenPointAndSegment(s2.end, s1));
            return ans;
        }

        // 正射影
        // 引数は点A, B, Cで、Aの直線BC上の正射影を求める。
        Point projection(const Point &a, const Line &l)
        {
            Point ret;
            ret = l.begin +
                  l.vec().normalized() * (a - l.begin).dot(l.vec()) / l.vec().length();
            return ret;
        }

        // 鏡映変換。引数は点A, B, Cで、直線BCにおいて、Aと線対称な点を求める。
        Point reflection(const Point &a, const Line &l)
        {
            Point ret;
            ret = a + 2 * (projection(a, l) - a);
            return ret;
        }

    } // namespace line2d
} // namespace geometry2d
