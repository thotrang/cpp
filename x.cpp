#include <bits/stdc++.h>
using namespace std;

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

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
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
void buocNhay(float newA[], float nhay, float min, float max)
{
    int i = 0;
    while (min <= max)
    {
        newA[i] = min;
        min += nhay;
        i++;
    }
}

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
    for (int i = 0; i < 100; i++)
    {
        cout << point[i].getX() << " " << point[i].getY() << " " << point[i].getZ() << endl;
    }
    return 0;
}