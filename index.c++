#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
// void nhap(float a[], int n)
// {
//    for (int i = 0; i < n; i++)
//    {
//       cout << "Nhap vao phan tu a[" << i << "] : ";
//       cin >> a[i];
//    }
// }
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

// void ThemPT(float a[100], int m, float t)
// {
//    m++;
//    a[m] = t;
// }
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

float TinhKhoangCach(float xA, float yA, float xB, float yB)
{
   return sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
}
// tính khoảng cách từ A mới so với các điểm cũ
// so sánh lấy 4 điểm gần nhất mà z của 4 điểm khác nhau

void swap(int &a, int &b){
    int temp =a;
    a=b;
    b=temp;
}
float KhoangCachCacDiem(float x[5000], float y[5000], float xA, float yA, float KhoangCach[5000])
{
   for (int i = 0; i < 4457; i++)
   {
      KhoangCach[i] = TinhKhoangCach(x[i], y[i], xA, yA);
   }
}
// float 4Diem(float z[5000], float KhoangCach[5000], float arr4DiemX[4], float arr4DiemY[4], float arr4DiemZ[4], float x[5000],float y[5000])
// {
//    //sắp xếp lại khoảng cách từ nhỏ đến lớn
//    for(int i=0;i<4456;i++){
//       for(int j=i+1;j<4457;j++){
//             if(KhoangCach[i]>KhoangCach[j]){
//                 swap(KhoangCach[i], KhoangCach[j]);
//                 swap(z[i],z[j]);
//                  swap(x[i],x[j]);
//                  swap(y[i],y[j]);
//             }
//       }      
//    }
//    // đưa 4 phần tử vào arr4diem
//    for(int i=0;i<4457;i++){

//    }

// }
int main()
{
   int n, m, p;
   n = m = p = 4457;

   float x[5000] = {};
   float y[5000] = {};
   float z[5000] = {};

   freopen("slthu.txt", "r", stdin);
   for (int i = 0; i < 4457; i++)
      cin >> x[i] >> y[i] >> z[i];

   float minx = timMin(x, n), miny = timMin(y, m), minz = timMin(z, p);

   float maxx = timMax(x, n), maxy = timMax(y, m), maxz = timMax(z, p);

   float newX[] = {minx}, newY[] = {miny}, newZ[] = {minz};

   buocNhay(newX, 0.00005, minx, maxx);
   buocNhay(newY, 0.00007, miny, maxy);

   float arr[5000] = {};
   KhoangCachCacDiem(x, y, 18.25387, 42.63422, arr);
   xuat(newX, 20);
   xuat(newY,10);

   system("pause");
   return 0;
}

//