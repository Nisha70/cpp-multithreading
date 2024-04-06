#include<bits/stdc++.h>
#include<thread>
using namespace std;
void func()
{
	cout<<"it is not simple.\n";
	
}
void fun2(string &f)
{
	cout<<f;
}
int main()
{
	thread t(func);
	string s="it is simple.\n";
	thread t2(fun2,std::ref(s));
	t.join();
	t2.join();
}