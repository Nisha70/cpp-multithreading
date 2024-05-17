//builder design pattern
#include<iostream>
#include<string>
using namespace std;
class product
{
    private:
     string part_a;
     string  part_b;
     string part_c;
    public:
    product(){}
    ~product(){}
    void Part_a(string &pa)
    {
        part_a=pa;
    }
    void Part_b(string &pb)
    {
        part_b=pb;
    }
    void Part_c(string &pc)
    {
        part_c=pc;
    }
    void check_product()
    {
        cout<<part_a<<"+"<<part_b<<"+"<<part_c<<endl;
    }
};
class builder
{
    public:
    builder(){}
    virtual ~builder(){}
    product get_product(){
        return product;
    }
    virtual void create_part_a()=0;
    virtual void create_part_b()=0;
    virtual void create_part_c()=0;
    protected:
    product product;

};
class concrete_builder1:public builder
{
    
    public:
    concrete_builder1(){}
    ~concrete_builder1(){}
    void create_part_a(){
        string a="1-A";
        product.Part_a(a);
    }
    void create_part_b()
    {
        string b="1-B";
        product.Part_b(b);
    }
    void create_part_c()
    {
        string c="1-C";
        product.Part_c(c);
    }
};
class concrete_builder2:public builder{
    
    public:
    concrete_builder2(){}
    ~concrete_builder2(){}
    void create_part_a(){
        string a="2-A";
        product.Part_a(a);
    }
    void create_part_b()
    {
        string b="2-B";
        product.Part_b(b);
    }
    void create_part_c()
    {
        string c="2-C";
        product.Part_c(c);
    }
};
class director{
    public:
    director(){}
    ~director(){
        if(Builder)
        {
            delete Builder;
        }
    }
    void set_builder(builder * b)
    {
        if(Builder)
        {
            delete Builder;
        }
        Builder=b;
    }
    product get_product()
    {
        return Builder->get_product();
    }
    void construct()
    {
        Builder->create_part_a();
        Builder->create_part_b();
        Builder->create_part_c();
    }
    private:
    builder * Builder=nullptr;
};
int main()
{
    director d;
   d.set_builder(new concrete_builder1);
   d.construct();
   product p=d.get_product();
   p.check_product();

    d.set_builder(new concrete_builder2);
    d.construct();
    product pp=d.get_product();
    pp.check_product();
}
