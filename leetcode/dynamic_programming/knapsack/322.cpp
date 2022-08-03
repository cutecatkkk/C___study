#include<iostream>
#include<climits>

using namespace std;

int main(int argc, char const *argv[])
{
    // int i=INT_MAX;
    // std::cout<<i+1<<endl;

    // int max=0x7fffffff;
    int i=10;   
    for(i;~i;--i){
        std::cout<<"i:"<<i<<"  ~i:"<<~i<<std::endl;
    }
    std::cout<<"i:"<<i<<"  ~i:"<<~i<<std::endl;
    return 0;
}
