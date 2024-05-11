#include<iostream>
using namespace std;
class abstract_product_a
{
    public:
    abstract_product_a()
    {
        cout<<"abstract product a created"<<endl;
    }
    virtual ~abstract_product_a()
    {
        cout<<"abstract product a deleted"<<endl;
    }
    virtual void show()=0;
    
};
class product_a_type_1:public abstract_product_a
{
    public:
    product_a_type_1()
    {
        cout<<"product a type 1 created"<<endl;
    }
    ~product_a_type_1()
    {
        cout<<"product a type 1 deleted"<<endl;
    }
    void show()
    {
        cout<<"show product a type 1"<<endl;
    }
};
class product_a_type_2:public abstract_product_a
{
    public:
    product_a_type_2()
    {
        cout<<"product a type 2 created"<<endl;
    }
    ~product_a_type_2()
    {
        cout<<"product a type 2 deleted"<<endl;
    }
    void show()
    {
        cout<<"show product a type 2"<<endl;
    }
};
class abstract_product_b
{
    public:
    abstract_product_b()
    {
        cout<<"abstract product b created"<<endl;
    }
    virtual ~abstract_product_b()
    {
        cout<<"abstract product b deleted"<<endl;
    }
    virtual void show()=0;

    
};
class product_b_type_1:public abstract_product_b
{
    public:
    product_b_type_1()
    {
        cout<<"product b type 1 created"<<endl;
    }
    ~product_b_type_1()
    {
        cout<<"product b type 1 deleted"<<endl;
    }
    void show()
    {
        cout<<"show product b type 1"<<endl;
    }
};
class product_b_type_2:public abstract_product_b
{
    public:
    product_b_type_2()
    {
        cout<<"product b type 2 created"<<endl;
    }
    ~product_b_type_2()
    {
        cout<<"product b type 2 deleted"<<endl;
    }
     void show()
    {
        cout<<"show product b type 2"<<endl;
    }
};
class Abstract_factory
{
    public:
    Abstract_factory()
    {
        cout<<"abstract factory called"<<endl;
    }
    virtual ~Abstract_factory(){
        cout<<"abstract factory deletion called"<<endl;
    }
    virtual abstract_product_a * create_product_a()=0;
    virtual abstract_product_b * create_product_b()=0;

};
class factory_1:public Abstract_factory
{
    public:
        factory_1(){
            cout<<"factory 1 is creating a product"<<endl;
        }
        ~factory_1(){
            cout<<"factory 1 is deleting a product"<<endl;
        }
        abstract_product_a * create_product_a()
        {
            return new product_a_type_1;
        }
        abstract_product_b * create_product_b()
        {
            return new product_b_type_1;
        }
};
class factory_2:public Abstract_factory
{
    public:
        factory_2(
        ){
            cout<<"factory 1 is creating a product"<<endl;
        }
        ~factory_2(){
           // cout<<"factory 1 is deleting a product"<<endl;
        }
        abstract_product_a * create_product_a()
        {
            return new product_a_type_2;
        }
        abstract_product_b * create_product_b()
        {
            return new product_b_type_2;
        }
};


int main(){
    Abstract_factory * factory=new factory_1;
   abstract_product_a * product_a=factory->create_product_a();
    abstract_product_b * product_b=factory->create_product_b();
    product_a->show();
    product_b->show();
    delete factory;
    delete product_a;
    delete product_b;

}


/*
abstract factory called
factory 1 is creating a product
abstract product a created
product a type 1 created
abstract product b created
product b type 1 created
show product a type 1
show product b type 1
factory 1 is deleting a product
abstract factory deletion called
product a type 1 deleted
abstract product a deleted
product b type 1 deleted
abstract product b deleted

*/
