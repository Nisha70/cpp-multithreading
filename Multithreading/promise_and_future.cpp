#include<iostream>
#include<thread>
#include<future>
#include<chrono>
using namespace std;
void  dotask(int n,std::promise<int> &p)
{
    int value=n*n;
    this_thread::sleep_for(std::chrono::seconds(2));
    p.set_value(value);
    this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    auto prom= promise<int>();
    auto fut=prom.get_future();
    auto t=thread(&dotask,5,std::ref(prom));
    int result=fut.get();
    cout<<result<<endl;
    t.join();
    

}
