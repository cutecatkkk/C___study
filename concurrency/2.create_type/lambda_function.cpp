#include<iostream>
#include<thread>

using namespace std;

int main(int argc, char const *argv[])
{
    auto fun=[](int x){
        while(x-->0){
            cout<<"fun:"<<x<<endl;
        }
    };

    std::thread t(fun,10);

    std::thread t1_1([](int x){
        while(x-->0){
            cout<<x<<endl;
        }
    },11);

    t.join();
    t1_1.join();
    return 0;
}
