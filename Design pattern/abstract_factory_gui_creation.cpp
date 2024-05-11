#include<iostream>
using namespace std;
class  button
{
    public:
    button(){}
    ~button(){}
    virtual void create_button()=0;

};
class win_button:public button{
    public:
    win_button(){}
    ~win_button(){}
    void create_button()
    {
        cout<<"windows button created"<<endl;
    }
};
class macos_button:public button
{
    public:
    macos_button(){}
    ~macos_button(){}
    void create_button()
    {
        cout<<"macos button created"<<endl;
    }   

};

class checkbox
{   public:
    checkbox(){}
    ~checkbox(){}
    virtual void create_checkbox()=0;

};
class win_checkbox:public checkbox
{
    public:
    win_checkbox(){}
    ~win_checkbox(){}
    void create_checkbox()
    {
        
        cout<<"windows checkbox created"<<endl;
    }
    
};
class macos_checkbox:public checkbox
{
    public:
    macos_checkbox(){}
    ~macos_checkbox(){}
    void create_checkbox()
    {
        cout<<"macos checkbox created"<<endl;
    }
};



class guifactory
{
    public:
    guifactory(){}
    virtual ~guifactory(){}
    virtual button * create_button()=0;
    virtual checkbox * create_checkbox()=0;

};
class win_gui_factory:public guifactory
{
    public:
    win_gui_factory(){}
    ~win_gui_factory(){}
    button * create_button() override
    {
        return new win_button;
    }
    checkbox * create_checkbox() override
    {
        return new win_checkbox;
    }
    
};
class mac_gui_factory:public guifactory
{
    public:
    mac_gui_factory(){}
    ~mac_gui_factory(){}
    button * create_button() override
    {
        return new macos_button;
    }
    checkbox * create_checkbox() override
    {
        return new macos_checkbox;
    }
    
};
int main()
{
    guifactory * gui_factori=new win_gui_factory;
    button * bb=gui_factori->create_button();
    bb->create_button();
    checkbox * cc=gui_factori->create_checkbox();
    cc->create_checkbox();


    gui_factori=new mac_gui_factory;
    button * bbb=gui_factori->create_button();
    bbb->create_button();
    checkbox *ccc=gui_factori->create_checkbox();
    ccc->create_checkbox();

   
}