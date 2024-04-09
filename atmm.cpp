

#include"atm.h"
using namespace g;
//visa authention system object;
visa_sa auth;
//CREATING ATM OBJECT
ATM atm;
//maintain_operator object
maintain_operator mo;


//atm constructor
ATM::ATM()
{
	total_cash=5000000;
	atm.card_reader_has_card="no";
	atm.withdraw_limit=10000;
}
//atm destructor
ATM::~ATM()
{
	
}

//checking atm has already a card inserted
string ATM::no_card()
{
	if(atm.card_reader_has_card=="yes")
	{
		return "yes";
	}
	else
	{
		return "no";
	}
}


//removing already existing card
void ATM::retrieve_card_that_have_been_swallowed()
{
	atm.card_reader_has_card="no";
	cout<<"retrieved the card"<<endl;;
}

//removing deposit cheques after work completed
void ATM::retrieve_cheques_that_have_been_deposited()
{
	cout<<"retrieved cheques"<<endl;
}

//refilling cash
void ATM::refill_dispenser(){
	total_cash=5000000;
}

//checking available cash 
string ATM::wellstocked(){
	if(total_cash>10000)
	{
		return "well-stocked";
	}
	else{
		return "no_cash";
	}
}

//withdraw amount from card
void ATM::withdraw(visa_card_holder &e)
{
	
	
	int pin;
	cout<<"\nenter your pin:";
	cin>>pin;
	string s=auth.authentication(e,pin);
	if(s=="verified")
	{
		cout<<"\nenter the amount  you want to withdraw";
		int money;
		cin>>money;
		if(money>atm.withdraw_limit)
		{
			cout<<"exceeds withdraw limit\n";
		}
		else{
		
		total_cash-=money;
		cout<<"collect your money::";
		cout<<money;
		
	}
		
	}
	else if(s=="wrong_pin")
	{
		
		cout<<"wrong pin"<<endl;
		atm.withdraw(e);
	}
	else
	{
		cout<<"not verified"<<endl;
	}
	
	
}



//setting pin of card outside access is blocked
void visa_card_holder::set_pin(const int pinn,const string valid)
{
	
	this->pin=pinn;
	this->valid_upto=valid;
	struct card_details g;
	g.card_holder_name=this->card_holder_name;
	g.card_number=this->card_number;
	g.pin=pinn;
	g.valid_upto=valid;
	
	
	auth.add_visa_card(g);
	
}

//inserting atm card
void visa_card_holder::insert_to_atm()
{
	
	visa_card_holder t;
	t.card_holder_name=this->card_holder_name;
	t.card_number=this->card_number;
	t.pin=this->pin;
	t.valid_upto=this->valid_upto;
	string stock=atm.wellstocked();
	//well stocked atm checking
	if(stock=="well-stocked")
	{
		string atm_has_already_card=atm.no_card();
		if(atm_has_already_card=="yes")
		{
			
			cout<<"\ncalling for maintainence.\n";
			mo.maintainence();
			atm.withdraw(t);
		}
		else{
			atm.card_reader_has_card="yes";
				atm.withdraw(t);
		}
		
	}
	else
	{
		cout<< stock<<endl;
	}

}

//showing details of card
void visa_card_holder::show()
{
	cout<<this->card_holder_name<<' '<<this->card_number<<' '<<this->pin<<' '<<this->valid_upto<<endl;
}

//add card details to authorisation system
void visa_sa::add_visa_card(card_details &aa)
{
	auth.a.push_back(aa);
}


//checking the validity of info provided
string visa_sa::authentication(visa_card_holder aa,int pin)
{
			
			for(int i=0; i<auth.a.size(); i++)
			{
				if(aa.card_number==auth.a[i].card_number)
				{
					if(auth.a[i].pin==pin)
					{
					return "verified";}
					else
					{
						return "wrong pin";
					}
					
				}
			}
				return "not_verified";
			
}


//removing card from atm
void visa_card_holder::removecard()
{
	atm.card_reader_has_card="no";
}


//calling maintainence operator for required work
void maintain_operator::maintainence()
{
	string stoc=atm.wellstocked();
	if(stoc!="well-stocked")
	{
	atm.refill_dispenser();}
	atm.retrieve_card_that_have_been_swallowed();
	atm.retrieve_cheques_that_have_been_deposited();
	
}


