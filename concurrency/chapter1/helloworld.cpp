#include<iostream>
#include<thread>

using namespace std;

void hello(){
    cout<<"hello world"<<endl;
}

int main(int argc, char const *argv[])
{
    thread t(hello);
    t.join();
    return 0;
}
