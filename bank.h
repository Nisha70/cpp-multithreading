#include<bits/stdc++.h>
using namespace std;
#ifndef bank_h
#define bank_h
struct date{
	int date;
	int month;
	int year;
};
class Customer
{
	public:
		int customer_id;
		string name;
		string address;
		int phone_number;
	public:
		void show()
		{
			cout<<"customer id "<<this->customer_id<<' '<<"name "<<this->name<<' '<<"address "<<this->address<<' '<<"phone number "<<this->phone_number<<endl;	
		}
};
class Loan
{
	public:
		int loan_no;
		int amount;
		string type;
		Customer customer;
		int duration;
		int current_balance;
	public:
		void setcurrentbalance()
		{
			current_balance=amount;
		}
		void addcustomer(Customer c)
		{
			customer.address=c.address;
			customer.customer_id=c.customer_id;
			customer.name=c.name;
			customer.phone_number=c.phone_number;
		}
		void prepayment()
		{
			int h=amount/duration;
			current_balance-=h;
		}
		void getemi()
		{
			cout<<amount/duration<<endl;
		}
		void currentbalance()
		{
			cout<<"current balance"<<this->current_balance<<endl;
		}
		
};
class Account{
	public:
		int account_no;
		int account_balance;
		Customer account_customer_details;
	public:
		
		void debit(int amount)
		{
			this->account_balance-=amount;
		}
		void credit(int amount)
		{
			this->account_balance+=amount;
		}
		void getbalance()
		{
			cout<<"account balance "<<this->account_balance<<endl;
		}
		void account_details()
		{
			cout<<"account no "<<this->account_no<<' '<<"account balance "<<this->account_balance<<endl;;
		}
		
};
class SavingAccount:public Account
{
	public:
		int min_balance;
		struct date date_of_opening;
		
	public:
		
		void addcustomer(Customer customer)
		{
			Account::account_customer_details.address=customer.address;
			Account::account_customer_details.customer_id=customer.customer_id;
			Account::account_customer_details.name=customer.name;
			Account::account_customer_details.phone_number=customer.phone_number;
		}
		void removecustomer(Customer Customer)
		{
			Account::account_customer_details.address="NULL";
			Account::account_customer_details.customer_id=0;
			Account::account_customer_details.name="NULL";
			Account::account_customer_details.phone_number=0;
			this->min_balance=0;
			this->date_of_opening.date=0;
			this->date_of_opening.month=0;
			this->date_of_opening.year=0;
		}
		void specific_detail()
		{
			cout<<"min balance "<<this->min_balance<<" "<<"date of opening "<<this->date_of_opening.date<<'-'<<this->date_of_opening.month<<'-'<<this->date_of_opening.year<<endl;
		}
};
class CurrentAccount:public Account
{		
		public:
		int interest_rate;
		struct date date_of_opening;
		
		public:
		void addcustomer(Customer customer)
		{
			Account::account_customer_details.address=customer.address;
			Account::account_customer_details.customer_id=customer.customer_id;
			Account::account_customer_details.name=customer.name;
			Account::account_customer_details.phone_number=customer.phone_number;
		}
		void removecustomer(Customer Customer)
		{
			Account::account_customer_details.address="NULL";
			Account::account_customer_details.customer_id=0;
			Account::account_customer_details.name="NULL";
			Account::account_customer_details.phone_number=0;
			this->interest_rate=0;
			this->date_of_opening.date=0;
			this->date_of_opening.month=0;
			this->date_of_opening.year=0;
	}
	void specific_detail()
	{
		cout<<"interest rate "<<this->interest_rate<<" "<<"date of opening "<<this->date_of_opening.date<<'-'<<this->date_of_opening.month<<'-'<<this->date_of_opening.year<<endl;
	}
	
};

class Branch
{
	public:
	int Branch_code;
	string city;
	private:
	vector<Account> account_list;
	vector<Loan> loan;
	public:
		void addaccount(Account aa)
		{
			account_list.push_back(aa);
		}
		void removeaccount(Account aa)
		{
			for(int i=0; i<account_list.size(); i++)
			{
				if(account_list[i].account_no==aa.account_no)
				{
					account_list.erase(account_list.begin()+i);
					break;
				}
			}
		}
		void getaccount(Account aa)
		{
			int j=0;
			for(int i=0; i<account_list.size(); i++)
			{
				if(account_list[i].account_no==aa.account_no)
				{
					j=1;
					account_list[i].account_customer_details.show();
					cout<<"account no "<<account_list[i].account_no<<' '<<"account_balance "<<account_list[i].account_balance<<endl;
					break;
				}
			}
			if(j==0)
			{
				cout<<"NOT PRESENT"<<endl;
			}
		}
		
		void addloan(Loan l)
		{
			loan.push_back(l);
		}
		void removeloan(Loan l)
		{
			for(int i=0; i<loan.size(); i++)
			{
				if(loan[i].loan_no==l.loan_no)
				{
					loan.erase(loan.begin()+i);
					break;
				}
			}
		}
		void getloan(Loan l)
		{
			int j=0;
			for(int i=0; i<loan.size(); i++)
			{
				if(loan[i].loan_no==l.loan_no)
				{
					cout<<"loan no "<<l.loan_no<<' '<<"loan amount "<<l.amount<<' '<<"loan type "<<l.type<<' '<<"lona duration "<<l.duration<<endl;
					l.customer.show();
					j=1;
					break;
				}
			}
			if(j==0)
			{
				cout<<"NOT PRESENT"<<endl;
			}
		}
};
class Bank
{
	public:
	string name;
	int code;
	private:
		vector<Branch> branch;
	public:
		void addbranch(Branch b)
		{
			branch.push_back(b);
		}
		void removebranch(Branch b)
		{
			for(int i=0; i<branch.size(); i++)
			{
				if(branch[i].Branch_code==b.Branch_code)
				{
					branch.erase(branch.begin()+i);
					break;
				}
			}
		}
		void getbranch(Branch b)
		{
			int o=0;
			for(int i=0; i<branch.size(); i++)
			{
				if(branch[i].Branch_code==b.Branch_code)
				{
					cout<<"branch city"<<branch[i].city<<' '<<"branch code"<<branch[i].Branch_code<<endl;
					o=1;
					break;
				}
			}
			if(o==0)
			{
				cout<<"NOT PRESENT"<<endl;
			}
		}
		void getallbranch()
		{
			for(int i=0; i<branch.size(); i++)
			{
				cout<<"branch code"<<branch[i].Branch_code<<' '<<"branch city"<<branch[i].city<<endl;
			}
		}
};
#endif
