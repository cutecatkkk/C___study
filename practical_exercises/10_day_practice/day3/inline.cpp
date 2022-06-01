#include<iostream>
using namespace std;
//şŻĘýÉůĂ÷
inline double CalArea(double radius);
int main(int argc, char const *argv[])
{
    double r(3.0);
    double area;
    area = CalArea(r);
    cout<<area<<endl;
    system("pause");
    return 0;
}
//źÓšŘźü×Öinline
inline double CalArea(double radius)
{
    return 3.14*radius*radius;
}