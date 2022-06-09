
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

   float minx = timMin(arrx, n), miny = timMin(arry, n);
   float maxx = timMax(arrx, n), maxy = timMax(arry, n);

   float newX[4500] = {};
   float newY[4500] = {};

   for (int i = 0; i < 120; i++)
   {
      newX[i] = minx;
      minx += 0.00005;
      newY[i] = miny;
      miny += 0.00007;
   }

   Obj newPoint[150];
    for (int i = 0; i < 120; i++)
    {
        newPoint[i].setX(newX[i]);
        newPoint[i].setY(newY[i]);
    }
   Obj _4Diem[200][4];

   float KhoangCach[4500] = {};
   for (int i4 = 0; i4 < 120; i4++)
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

      _4Diem[i4][0] = point[4456]; // tìm 4 điểm của point gần với newpoint với z ko trùng nhau
      _4Diem[i4][1] = point[4455];
      _4Diem[i4][2] = point[4454];
      _4Diem[i4][3] = point[4453];

      float m1 = KhoangCach[4456], m2 = KhoangCach[4455], m3 = KhoangCach[4454], m4 = KhoangCach[4453];

      for (int j5 = 4456; j5 >= 0; j5--)
      {
         if (KhoangCach[j5] <= m1 && point[j5].getZ() != _4Diem[i4][0].getZ())
         {
            _4Diem[i4][0] = point[j5];
            m1 = KhoangCach[j5];
         }

         else if (KhoangCach[j5] <= m2 && point[j5].getZ() != _4Diem[i4][1].getZ())
         {
            _4Diem[i4][1] = point[j5];
            m2 = KhoangCach[j5];
         }

         else if (KhoangCach[j5] <= m3 && point[j5].getZ() != _4Diem[i4][2].getZ())
         {
            _4Diem[i4][2] = point[j5];
            m3 = KhoangCach[j5];
         }

         else if (KhoangCach[j5] <= m4 && point[j5].getZ() != _4Diem[i4][3].getZ())
         {
            _4Diem[i4][3] = point[j5];
            m4 = KhoangCach[j5];
         }
      }
   }
   for (int m1 = 0; m1 < 120; m1++)
   {
      for (int m2 = 0; m2 < 4; m2++)
      {
         cout << _4Diem[m1][m2].getX() << " " << _4Diem[m1][m2].getY() << " " << _4Diem[m1][m2].getZ() << endl;
      }
      cout << endl;
   }

   system("pause");
   return 0;
}