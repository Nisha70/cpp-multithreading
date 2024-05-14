#include<iostream>
using namespace std;
class singleton{
    private:
    static singleton *instance;
    singleton(){
        cout<<"singleton created"<<endl; 
    }
    
    public:
    static singleton * getinstance()
    {
        if(instance==NULL)
        {
            instance=new singleton;
        }
        return instance;
    }
    
    singleton(const singleton &)=delete;
    singleton& operator=(const singleton&)=delete;
    void some_operation()
    {
        cout<<"only one object of singleton exist"<<endl;
        
    }
};
singleton *singleton::instance=NULL;
int main()
{
    singleton *single=singleton::getinstance();
    single->some_operation();
    

}
