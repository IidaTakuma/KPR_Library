#include <bits/stdc++.h>

using namespace std;

class Matrix3D
{
public:
    static const int ROW = 3;
    static const int COL = 3;
    union
    {
        struct
        {
            float a, b, c,
                d, e, f,
                g, h, i;
        };
        float val[ROW][COL];
    };

    Matrix3D(float x00, float x01, float x02,
             float x10, float x11, float x12,
             float x20, float x21, float x22)
    {
        val[0][0] = x00;
        val[0][1] = x01;
        val[0][2] = x02;
        val[1][0] = x10;
        val[1][1] = x11;
        val[1][2] = x12;
        val[2][0] = x20;
        val[2][1] = x21;
        val[2][2] = x22;
    }
    Matrix3D()
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                val[i][j] = 0;
            }
        }
    }

    float *operator[](int i)
    {
        return val[i];
    }

    float &operator()(int i, int j)
    {
        return val[i][j];
    }

    Matrix3D &operator=(const Matrix3D &A)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                this->val[i][j] = A.val[i][j];
            }
        }
        return *this;
    }

    Matrix3D operator+() { return *this; } //+Matrix3D
    Matrix3D operator-()
    { //-Matrix3D A;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                A.val[i][j] = -val[i][j];
            }
        }
        return A;
    }
};