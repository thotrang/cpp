
#include <bits/stdc++.h>
using namespace std;

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
class Obj
{
    float x;
    float y;
    float z;

public:
    Obj() {}

    void setX(float x)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    void setZ(float z)
    {
        this->z = z;
    }
    float getX()
    {
        return this->x;
    }
    float getY()
    {
        return this->y;
    }
    float getZ()
    {
        return this->z;
    }
};
float timMin(float a[], int n)
{
    float min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    return min;
}

float timMax(float a[], int n)
{
    float max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n = 4457;
    float x, y, z;
    Obj point[4500];
    ofstream outfile;
    freopen("slthu.txt", "r", stdin);

    for (int i = 0; i < 4457; i++)
    {
        cin >> x >> y >> z;

        point[i].setX(x);
        point[i].setY(y);
        point[i].setZ(z);
    }
    float arrx[4500] = {};
    float arry[4500] = {};
    float arrz[4500] = {};

    freopen("slthu.txt", "r", stdin);
    for (int i = 0; i < 4457; i++)
        cin >> arrx[i] >> arry[i] >> arrz[i];
    // for (int i = 0; i < 100; i++)
    // {
    //     cout<<setprecision(8);
    //     cout << arrx[i] << "  " << arry[i] << "  " << arrz[i] << endl;
    // }

    float minx = timMin(arrx, n), miny = timMin(arry, n);
    float maxx = timMax(arrx, n), maxy = timMax(arry, n);

    float newX[4500] = {};
    float newY[4500] = {};
    int iX = 0;
    while (minx <= maxx)
    {
        newX[iX] = minx;
        minx += 0.00005;
        iX++;
    }
    int iY = 0;
    while (miny <= maxy)
    {
        newY[iY] = miny;
        miny += 0.00007;
        iY++;
    }

    Obj newPoint[150];
    int i = 0;
    while (i < iX)
    {
        newPoint[i].setX(newX[i]);
        newPoint[i].setY(newY[i]);
        i++;
    }
    Obj Z[200][4];

    float KhoangCach[4500] = {};
    for (int i4 = 0; i4 < iX; i4++)
    {
        for (int kc = 0; kc < 4457; kc++) // tính khoảng cách newpoint với point
        {
            KhoangCach[kc] = sqrt((point[kc].getX() - newPoint[i4].getX()) * (point[kc].getX() - newPoint[i4].getX()) + (point[kc].getY() - newPoint[i4].getY()) * (point[kc].getY() - newPoint[i4].getY()));
        }

        for (int j4 = 0; j4 < 4456; j4++) // sắp xếp lại vị trí khoảng cách và point từ bé đến lớn
        {
            for (int t4 = j4 + 1; t4 < 4457; t4++)
            {
                if (KhoangCach[j4] > KhoangCach[t4])
                {
                    swap(KhoangCach[j4], KhoangCach[t4]);
                    swap(point[j4], point[t4]);
                }
            }
        }

        Z[i4][0] = point[4456]; // tìm 4 điểm của point gần với newpoint với z ko trùng nhau
        Z[i4][1] = point[4455];
        Z[i4][2] = point[4454];
        Z[i4][3] = point[4453];

        float m1 = KhoangCach[4456], m2 = KhoangCach[4455], m3 = KhoangCach[4454], m4 = KhoangCach[4453];

        for (int j5 = 4456; j5 >= 0; j5--)
        {
            if (KhoangCach[j5] <= m1 && point[j5].getZ() != Z[i4][0].getZ() && point[j5].getZ() != Z[i4][1].getZ() && point[j5].getZ() != Z[i4][2].getZ() && point[j5].getZ() != Z[i4][3].getZ())
            {
                Z[i4][0] = point[j5];
                m1 = KhoangCach[j5];
            }

            else if (KhoangCach[j5] <= m2 && point[j5].getZ() != Z[i4][0].getZ() && point[j5].getZ() != Z[i4][1].getZ() && point[j5].getZ() != Z[i4][2].getZ() && point[j5].getZ() != Z[i4][3].getZ())
            {
                Z[i4][0] = point[j5];
                m2 = KhoangCach[j5];
            }

            else if (KhoangCach[j5] <= m3 && point[j5].getZ() != Z[i4][0].getZ() && point[j5].getZ() != Z[i4][1].getZ() && point[j5].getZ() != Z[i4][2].getZ() && point[j5].getZ() != Z[i4][3].getZ())
            {
                Z[i4][0] = point[j5];
                m3 = KhoangCach[j5];
            }

            else if (KhoangCach[j5] <= m4 && point[j5].getZ() != Z[i4][0].getZ() && point[j5].getZ() != Z[i4][1].getZ() && point[j5].getZ() != Z[i4][2].getZ() && point[j5].getZ() != Z[i4][3].getZ())
            {
                Z[i4][0] = point[j5];
                m4 = KhoangCach[j5];
            }
        }
    }
    for (int iz = 0; iz < iX; iz++)
    {
        float a1 = (newPoint[iz].getX() * (Z[iz][0].getZ() - Z[iz][1].getZ()) - Z[iz][0].getZ() * Z[iz][1].getY() + Z[iz][1].getZ() * Z[iz][0].getX()) / (Z[iz][0].getX() - Z[iz][1].getX());
        float a2 = (newPoint[iz].getX() * (Z[iz][2].getZ() - Z[iz][3].getZ()) - Z[iz][2].getZ() * Z[iz][3].getY() + Z[iz][3].getZ() * Z[iz][2].getX()) / (Z[iz][2].getX() - Z[iz][3].getX());
        float a3 = (newPoint[iz].getY() * (Z[iz][0].getY() - Z[iz][1].getY()) - Z[iz][0].getZ() * Z[iz][1].getY() + Z[iz][3].getZ() * Z[iz][0].getY()) / (Z[iz][0].getY() - Z[iz][1].getY());
        float a4 = (newPoint[iz].getY() * (Z[iz][1].getY() - Z[iz][0].getY()) - Z[iz][1].getZ() * Z[iz][1].getY() + Z[iz][2].getZ() * Z[iz][0].getY()) / (Z[iz][0].getY() - Z[iz][1].getY());

        float a5 = (a1 + a2 + a3 + a4) / 4;
        newPoint[iz].setZ(a5);
        cout<<setprecision(7);
        cout << newPoint[iz].getX() << "  " << newPoint[iz].getY() << "  " << newPoint[iz].getZ() << endl;
    }

    system("pause");
    return 0;
}
