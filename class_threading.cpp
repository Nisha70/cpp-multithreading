#include<bits/stdc++.h>
#include<thread>
using namespace std;

class Min
{
	public:
		void print(string &n)
		{
			cout<<n<<endl;
		}
};
int main()
{	string f="hello multithreading LOOOP";
	Min mm;
	thread t(&Min::print,&mm,std::ref(f));
	t.join();
}