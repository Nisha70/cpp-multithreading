
#ifndef ATMm
#define ATMm
#include<bits/stdc++.h>
using namespace std;
 namespace g{

class visa_card_holder;
class ATM
{
	private:
		int total_cash;
		int withdraw_limit;
	public:
		string card_reader_has_card;
		
	public:
		ATM();
		~ATM();
		string wellstocked();
		string no_card();
		void withdraw(visa_card_holder &r);
		void refill_dispenser();
		void retrieve_card_that_have_been_swallowed();
		void retrieve_cheques_that_have_been_deposited();
};

class visa_card_holder
{
	public:
		int card_number;
		string card_holder_name;
	protected:
		string valid_upto;
		int pin;
	public:
		void set_pin(const int pinn,const string valid);
		void insert_to_atm();
		void show();
		void removecard();
		
		
	
};
struct card_details
{
	int card_number;
	string card_holder_name;
	string valid_upto;
	int pin;	
};
class visa_sa
{
	private:
		vector<card_details> a;
	public:
		void add_visa_card(card_details &g);
		string authentication(visa_card_holder aa,int pin);
		
};
class maintain_operator
{
	public:
		string name;
	public:
		void maintainence();
		
		 
		
};

	
		


}
#endif

