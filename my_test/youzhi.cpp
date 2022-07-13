#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a=2;
    int &&r1=std::move(a);
    int &&r2=1;
    cout<<r1<<" "<<&r1<<endl;
    return 0;
}
