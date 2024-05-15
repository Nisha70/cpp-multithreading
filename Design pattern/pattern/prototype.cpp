#include<iostream>
using namespace std;
class shape
{
    public:
    shape(){};
    virtual ~shape(){}
    virtual shape * clone()=0;
    virtual void show_details()=0;
};
class rectangle:  public shape
{
    protected:
    int length;
    int breadth;
    public:
    rectangle(int l,int b){length=l;
    breadth=b;}
    rectangle * clone()
    {
        return new rectangle(*this);
    }
    void show_details(){
        cout<<length<<' '<<breadth<<endl;
    }

    
};
class Square:public  shape
{
    public:
    int length;
    Square(int l)
    {
        
        length=l;
    }
    ~Square(){}
    shape * clone()
    {
        return new Square(*this);
    }
    void show_details()
    {
        cout<<length<<endl;
    }

};
class client
{
    private:
        shape * shapee=nullptr;
    public:
        client(){}
        ~client()
        {
            if(shapee)//if shapee is not null
            {
                delete shapee;
            }
        }
        void set_shape(shape *s)
        {
            if(shapee)//if shapee is not null
            {
                delete shapee;
            }
            shapee=s;
        }
        shape *clone()
        {
            if(!shapee)//if shapee is null
            {
                return nullptr;
            }
            return shapee->clone();
        }
};
int main()
{
    client cli;
    cli.set_shape(new rectangle(10,15));
   shape *rectangle1=cli.clone();
   (rectangle1->show_details());

   cli.set_shape(new Square(14));
   shape * square1=cli.clone();
   square1->show_details();


}
