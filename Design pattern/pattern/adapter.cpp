//adapter structural design pattern
#include<iostream>
#include<string>
using namespace std;
//interface to use adapter
class target
{   public:
    target(){}
    virtual ~target(){}
    virtual void request()=0;
};
class adaptee
{   public:
    ~adaptee(){}
    void specific_request(){
        cout<<"specific request called"<<endl;
    }
};
//adapter use adaptee methods
class adapter:public target,private adaptee{
    public:
    adapter(){}
    ~adapter(){}
    void request()
    {
        specific_request();
        cout<<"this is request"<<endl;
    }
};

int main()
{
    target *t=new adapter;
    t->request();
}
