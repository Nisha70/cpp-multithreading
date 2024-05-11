//MULTITHREADING 
#include<iostream>
#include<thread>
using namespace std;
void  dotask(const char *s,int n)
{
    cout<<s<<" "<<n<<endl;;
   
}
int main()
{
    thread t(&dotask,"good day",44);
   cout<<"main thread call"<<endl;
    
    t.join();
    return 0;
}
