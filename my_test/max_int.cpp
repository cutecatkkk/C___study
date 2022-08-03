#include<iostream>
#include <numeric>

int main(int argc, char const *argv[])
{
    int l=1,r=INT_MAX;
    std::cout<<((l+r)>>1)<<std::endl;
    std::cout<<(l+(r-l)/2)<<std::endl;
    return 0;
}
