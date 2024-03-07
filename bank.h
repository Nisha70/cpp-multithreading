#include<bits/stdc++.h>
using namespace std;
#ifndef bank_h
#define bank_h
map<string,int> m;
class Bank{
	private:
		string name;
		int code;
	public:
		Bank(){
		}
		Bank(string name,int code){
		name=name;code=code;
	}
		void getbranch(){
			cout<<name<<' '<<code;
		}
		static void addbranch(string name,int code)
		{
			m.insert(pair<string,int>(name,code));
		}
		void allbranch()
		{
			map<string,int>::iterator o;
			for( o=m.begin(); o!=m.end(); o++)
			{
				cout<<o->first<<' '<<o->second;
			}
		}
};
#endif
