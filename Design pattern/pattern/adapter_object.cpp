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
class adapter:public target{
    public:
    adapter(){
        adapte=new adaptee;
    }
    ~adapter(){
        delete adapte;
    }
    void request()
    {
        adapte->specific_request();
        cout<<"this is request"<<endl;
    }
    private:
    adaptee * adapte=nullptr;
};

int main()
{
    target *t=new adapter;
    t->request();
}
