#include<bits/stdc++.h>
#include<thread>
#include<fstream>
#include<chrono>
using namespace std;
void func()
{
	
	cout<<"thread is detach.\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout<<"thread too long.\n";
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
	t.detach();
	t2.join();
	//if we dont wait for detach thread it will not get a chance to print 
	this_thread::sleep_for(chrono::seconds(3));
}