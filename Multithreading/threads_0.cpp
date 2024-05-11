//MULTITHREADING 
#include<iostream>
#include<thread>
using namespace std;
void  dotask()
{
    cout<<"thread call ";
    for(int i=0; i<=20; i++)
    {
        cout<<i<<' ';
    }
    cout<<'\n';
}
int main()
{
    thread t(&dotask);
    cout<<"main call ";
    for(int i=0; i<=20; i++)
    {
        cout<<i<<' ';
    }
    cout<<'\n';
    t.join();
    return 0;
}
