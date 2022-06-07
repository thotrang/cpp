#include <bits/stdc++.h>
using namespace std;

class Obj
{
    float x;
    float y;
    float z;

	public:
		Obj(){}
	   
	    setX(float x)
	    {
	        this->x = x;
	    }
	    setY(float y)
	    {
	        this->y = y;
	    }
	    setZ(float z)
	    {
	        this->z = z;
	    }
	    getX()
	    {
	        return this->x;
	    }
	    getY()
	    {
	        return this->y;
	    }
	    getZ()
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
float TinhKhoangCach(float xA, float yA, float xB, float yB)
{
   return sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
}
// tính kho?ng cách t? A m?i so v?i các di?m cu
// so sánh l?y 4 di?m g?n nh?t mà z c?a 4 di?m khác nhau

void swap(float &a, float &b){
    float temp =a;
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
// float 4Diem (float z[5000], float KhoangCach[5000], float arr4DiemX[4], float arr4DiemY[4], float arr4DiemZ[4], float x[5000],float y[5000])  
// {
//    //s?p x?p l?i kho?ng cách t? nh? d?n l?n
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
//    // dua 4 ph?n t? vào arr4diem
//    for(int i=0;i<4457;i++){

//    }
//     return 0;
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
    for (int i = 0; i < 10; i++)
    {
        cout << point[i].getX() << " " << point[i].getY() << " " << point[i].getZ() << endl;
    }
    return 0;
}
