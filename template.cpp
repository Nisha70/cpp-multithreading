#include <iostream>
#include <string>
using namespace std;
template<class t>
void func(t a)
{
	cout<<a<<endl;
}
template<class t,class u>
//inline function
inline void func2(t a,u b)
{
	cout<<a<<' '<<b<<endl;
}
//using reference
template<class c>
c & func3(c & a,c & b)
{
	a=a+b;
	return a;
}
int main()
{
	func(10);
	func("gi");
	func(10.333);
	func2(4,"hi");
	func2(4,2);
	string d="hi";
	string s="jck";
	cout<<func3(d,s);
	
}
