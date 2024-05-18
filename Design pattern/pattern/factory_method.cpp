//builder design pattern
#include<iostream>
#include<string>
using namespace std;
class product{
    public:
    product(){};
    virtual ~product(){}
    virtual void check_product()=0;
};
class product_a:public product{
    public:
    product_a(){}
    ~product_a(){}
    void check_product()
    {
        cout<<"product_a has been created"<<endl;
    }

};
class product_b:public product 
{   public:
    product_b(){}
    ~product_b(){}
    void check_product()
    {
        cout<<"product_b has been created"<<endl;
    }
};
class creator{
    public:
    creator(){}
    virtual ~creator(){}
    virtual product_a * create_product_a()=0;
    virtual product_b * create_product_b()=0;
};
class concrete_creator:public creator{
    public:
    concrete_creator(){}
    ~concrete_creator(){}
    product *p=nullptr;
    product_a * create_product_a()
    {
        return new product_a;
    }
    product_b * create_product_b()
    {
        return new product_b;
    }
};
int main()
{
    creator * c=new concrete_creator;
    product *sd=c->create_product_a();
    sd->check_product();

    product * se=c->create_product_b();
    se->check_product();

}
