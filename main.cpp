// float KhoangCachCacDiem(Obj point[5000], Obj newPoint[5000], float KhoangCach[5000][5000],int iX)
// {
//     for (int i = 0; i < iX; i++)
//     {
//         for(int j=0;j< 4457;j++ ){
//             KhoangCach[i][j] = sqrt((point[j].getX - newPoint[i].getX) * (point[j].getX - newPoint[i].getX) + (point[j].getY - newPoint[i].getY) * (point[j].getY - newPoint[i].getY));
//         }

//     }
// }
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
    float z = 0;

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

float KhoangCachCacDiem(Obj point[5000], Obj newPoint[200], float KhoangCach[200][5000],int iX)
{
    for (int i = 0; i < iX; i++)
    {
        for(int j=0;j< 4457;j++ ){
            KhoangCach[i][j] = sqrt((point[j].getX - newPoint[i].getX) * (point[j].getX - newPoint[i].getX) + (point[j].getY - newPoint[i].getY) * (point[j].getY - newPoint[i].getY));
        }

    }
}

// void swap(float &a, float &b)
// {
//     float temp = a;
//     a = b;
//     b = temp;
// }
int main()
{
    int n = 4457;
    float x, y, z;
    Obj point[5000];
    ofstream outfile;
    freopen("slthu.txt", "r", stdin);

    for (int i = 0; i < 4457; i++)
    {
        cin >> x >> y >> z;

        point[i].setX(x);
        point[i].setY(y);
        point[i].setZ(z);
    }
    float arrx[5000] = {};
    float arry[5000] = {};
    float arrz[5000] = {};

    freopen("slthu.txt", "r", stdin);
    for (int i = 0; i < 4457; i++)
        cin >> arrx[i] >> arry[i] >> arrz[i];

    float minx = timMin(arrx, n), miny = timMin(arry, n);
    float maxx = timMax(arrx, n), maxy = timMax(arry, n);

    float newX[10000] = {};
    float newY[10000] = {};
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
    float KhoangCach[200][5000];
    KhoangCachCacDiem(point,newPoint,KhoangCach,iX);
    
   cout << "\n Xuat mang: " << endl;


    system("pause");
    return 0;
}