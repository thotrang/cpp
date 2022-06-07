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


// float TinhKhoangCach(float xA, float yA, float xB, float yB)
// {
//     return sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
// }


// float KhoangCachCacDiem(float x[5000], float y[5000], float xA, float yA, float KhoangCach[5000])
// {
//     for (int i = 0; i < 4457; i++)
//     {
//         KhoangCach[i] = TinhKhoangCach(x[i], y[i], xA, yA);
//     }
// }
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
    int iX=0;
    while(minx<=maxx){
       newX[iX]=minx;
       minx+=0.00005;
       iX++;
    }
        int iY=0;
    while(miny<=maxy){
       newY[iY]=miny;
       miny+=0.00007;
       iY++;
    }

    Obj newPoint[10000];
    int i=0;
    while (i < iX)
    {
        newPoint[i].setX(newX[i]);
        newPoint[i].setY(newY[i]);
        i++;
    }
    for (int i = 0; i < iX; i++)
    {
        cout << newPoint[i].getX() << " " << newPoint[i].getY() << "" << endl;
    }

    system("pause");
    return 0;
}
