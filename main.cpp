
#include <bits/stdc++.h>
using namespace std;

void xuat(double a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
class Obj
{
    double x;
    double y;
    double z = 0;

public:
    Obj() {}

    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    void setZ(double z)
    {
        this->z = z;
    }
    double getX()
    {
        return this->x;
    }
    double getY()
    {
        return this->y;
    }
    double getZ()
    {
        return this->z;
    }
};
double timMin(double a[], int n)
{
    double min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    return min;
}

double timMax(double a[], int n)
{
    double max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

// double KhoangCachCacDiem(Obj point[5000], Obj newPoint[200], double KhoangCach[200][5000], int iX)
// {
//     for (int i = 0; i < iX; i++)
//     {
//         for (int j = 0; j < 4457; j++)
//         {
//             KhoangCach[i][j] = sqrt((point[j].getX() - newPoint[i].getX()) * (point[j].getX() - newPoint[i].getX()) + (point[j].getY() - newPoint[i].getY()) * (point[j].getY() - newPoint[i].getY()));
//         }
//     }
// }
// void swap(double &a, double &b)
// {
//     double temp = a;
//     a = b;
//     b = temp;
// }
// double _4DiemGanNhat(Obj point[5000], double KhoangCach[200][5000], int iX, Obj _4Diem [200][4])
// {
//     for (int i = 0; i < iX; i++)
//     {
//         for (int j = 0; j < 4456; j++)
//         {
//             for (int t = j + 1; t < 4457; t++)
//             {
//                 if (KhoangCach[i][j] > KhoangCach[i][t])
//                 {
//                     swap(KhoangCach[i][j], KhoangCach[i][t]);
//                     swap(point[j], point[t]);
//                 }
//             }
//         }
//         _4Diem [i][0] = point[4456];
//         _4Diem [i][1] = point[4455];
//         _4Diem [i][2] = point[4454];
//         _4Diem [i][3] = point[4453];

//         double m1 = KhoangCach[i][4456], m2 = KhoangCach[i][4455], m3 = KhoangCach[i][4454], m4 = KhoangCach[i][4453];
//         for (int j = 4456; j >= 0; j--)
//         {
//             if (KhoangCach[i][j] <= m1 && point[j].getZ() != _4Diem [i][0]){
//                 _4Diem [i][0] = point[j];
//                 m1=KhoangCach[i][j];
//             }
                
//             else if (KhoangCach[i][j] <= m2 && point[j].getZ() != _4Diem [i][1]){
//                 _4Diem [i][0] = point[j];
//                 m2=KhoangCach[i][j];
//             }
                
//             else if (KhoangCach[i][j] <= m3 && point[j].getZ() != _4Diem [i][2]){
//                 _4Diem [i][0] = point[j];
//                 m3=KhoangCach[i][j];
//             }
                
//             else if (KhoangCach[i][j] <= m4 && point[j].getZ() != _4Diem [i][3]){
//                 _4Diem [i][0] = point[j];
//                 m4=KhoangCach[i][j];
//             }
                
//         }
//     }
// }

int main()
{
    int n = 4457;
    double x, y, z;
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
    double arrx[4500] = {};
    double arry[4500] = {};
    double arrz[4500] = {};

    freopen("slthu.txt", "r", stdin);
    for (int i = 0; i < 4457; i++)
        cin >> arrx[i] >> arry[i] >> arrz[i];

    double minx = timMin(arrx, n), miny = timMin(arry, n);
    double maxx = timMax(arrx, n), maxy = timMax(arry, n);

    double newX[4500] = {};
    double newY[4500] = {};
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

    Obj newPoint[200];
    int i = 0;
    while (i < iX)
    {
        newPoint[i].setX(newX[i]);
        newPoint[i].setY(newY[i]);
        i++;
    }
    for (int i = 0; i < 100; i++)
    {
        cout << point[i].getX() << " " << point[i].getY() << " " << point[i].getZ() << endl;
    }
    // double KhoangCach[200][5000];
    // KhoangCachCacDiem(point, newPoint, KhoangCach, iX);
    // for (int i = 0; i < iX; i++)
    // {
    //     for (int j = 0; j < 4457; j++)
    //     {
    //         cout << 1 << endl;
    //     }
    // }

    // Obj _4Diem [200][4];
    // _4DiemGanNhat(point,KhoangCach,iX,_4Diem);
    system("pause");
    return 0;
}