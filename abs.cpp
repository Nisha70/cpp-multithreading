#include<bits/stdc++.h>
using namespace std;
class producta
{
	public:
	virtual ~producta()	{}
	virtual void show() = 0;
};
class productax:public producta
{
	public:
		productax(){}
		~productax(){}
		void show()
		{
			cout<<"productax"<<endl;
		}
};
class productay:public producta
{
		public:
		productay(){}
		~productay(){}
		void show()
		{
			cout<<"productay"<<endl;
		}
};
class productb
{
	public:
		
		virtual ~productb(){}
		virtual void display()=0;
};
class productbx:public productb
{
	public:
		productbx(){}
		~productbx(){}
		void display()
		{
			cout<<"productbx"<<endl;
		}
		
};
class productby:public productb
{
		public:
		productby(){}
		~productby(){}
		void display()
		{
			cout<<"productby"<<endl;
		}
};
class abstract_factory
{
	public:
	abstract_factory(){}
	virtual ~abstract_factory(){}
	public:
		virtual producta * createproducta()=0;
		virtual productb * createproductb()=0;
		
};
class factoryx:public abstract_factory
{
	
	public:
		factoryx(){}
		~factoryx(){}
		
		producta * createproducta(){
			return new productax;
		}
		productb * createproductb()
		{
			return new productbx;
		}
};

class factoryy:public abstract_factory
{
		public:
		factoryy(){}
		~factoryy(){}
		producta * createproducta(){
			return new productay;
		}
		productb * createproductb()
		{
			return new productby;
		}
};
int main()
{
	//factory type x 
	abstract_factory *absfact1=new factoryx;
	//product type x from product a
	producta *ptr=absfact1->createproducta();
	
	cout<<"producta:";
	ptr->show();
	//factory type y
	abstract_factory *absfact2=new factoryy;
	//product type y from b
	productb *pt=absfact2->createproductb();
	
	cout<<"productb:";
	pt->display();
	
	delete ptr;
	delete pt;
	delete absfact1;
	delete absfact2;
	return 0;
	
}
