#include<bits/stdc++.h>
#include"bank.h"
using namespace std;
int main()
{
	
	///CREATE A BANK
	Bank koma;
	koma.name="komabank";
	koma.code=1;
	
	//creating branch of koma bank
	Branch komabank1,komabank2;
	komabank1.city="komabranch1";
	komabank1.Branch_code=10;
	
	komabank2.city="komabranch2";
	komabank2.Branch_code=11;
	
	
	//creating date object 
	struct date d1,d2,d3;
	d1.date=2;
	d1.month=3;
	d1.year=1550;
	
	d2.date=9;
	d2.month=8;
	d2.year=1889;
	
	d3.date=1;
	d3.month=7;
	d3.year=1990;
	
	//creating customers object
	Customer c1,c2,c3;
	c1.customer_id=123456;
	c1.address="localstreet";
	c1.name="nunth";
	c1.phone_number=2345;
	
	
	c2.customer_id=213654;
	c2.address="localstreet1";
	c2.name="nunth2";
	c2.phone_number=789456;
	
	c3.address="local3";
	c3.customer_id=4533;
	c3.name="niut";
	c3.phone_number=7456218;
	
	
	//creating saving account
	SavingAccount sa1,sa2;
	sa1.min_balance=10;
	sa1.date_of_opening=d1;
	sa1.account_customer_details=c1;
	sa1.account_no=100;
	sa1.account_balance=78945;
	
	sa2.min_balance=20;
	sa2.date_of_opening=d2;
	sa2.account_customer_details=c2;
	sa2.account_no=110;
	sa2.account_balance=123345;
	
	
	//creating current account
	CurrentAccount ca1,ca2;
	ca1.interest_rate=2;
	ca1.date_of_opening=d2;
	ca1.account_customer_details=c3;
	ca1.account_no=200;
	ca1.account_balance=122;
	
	
	ca2.interest_rate=3;
	ca2.date_of_opening=d3;
	ca2.account_customer_details=c2;
	ca2.account_no=123;
	ca2.account_balance=456;
	//creating loan pbjects
	Loan l1,l2;
	l1.loan_no=1;
	l1.amount=2345;
	l1.type="educational";
	l1.customer=c1;
	l1.duration=25;
	l1.current_balance=2345;
	
	l2.loan_no=11;
	l2.amount=405;
	l2.type="business";
	l2.customer=c2;
	l2.duration=48;
	l2.current_balance=405;
	
	
	//adding savingaccounts to branch koma1
	komabank1.addaccount(sa1);
	komabank1.addaccount(sa2);
	komabank1.addloan(l1);
	
	//GETTING INFO FROM BRANCH
	komabank1.getaccount(sa1);
	komabank1.getloan(l1);
	
	//adding currentaccount to branch koma2
	komabank2.addaccount(ca1);
	komabank2.addaccount(ca2);
	komabank2.addloan(l2);
	
	//getting details from branch
	komabank2.getaccount(ca1);
	komabank2.getloan(l2);
	
	
	//removing account and loan from brannch and then getting info
	komabank1.removeaccount(sa2);
	komabank1.removeloan(l1);
	
	komabank2.removeaccount(ca1);
	komabank2.removeloan(l2);
	
	komabank1.getaccount(sa2);
	komabank1.getloan(l1);
	
	komabank2.getaccount(ca1);
	komabank2.getloan(l2);
	
	
	//addbranch to bank
	koma.addbranch(komabank1);
	koma.addbranch(komabank2);
	
	//removing a branch from bank
	koma.removebranch(komabank2);
	
	
	//getting branch info from bank
	koma.getbranch(komabank2);
	
	//add branch to bank
	koma.addbranch(komabank2);
	
	//all branch of bank
	koma.getallbranch();
	
	// current balance before loan prepayment
	cout<<"current balance "<<l1.current_balance<<endl;
	
	
	//before prepayment emi
	l1.getemi();
	
	
	//loan prepayment
	l1.prepayment();
	
	
	// current balance before loan prepayment
	cout<<"current balance "<<l1.current_balance<<endl;
	
	//after prepayment
	l1.getemi();
	
	
	
	Customer c;
	c.customer_id=123456;
	c.address="localstreet";
	c.name="nunth";
	c.phone_number=2345;
	
	SavingAccount sa;
	sa.min_balance=20;
	sa.date_of_opening=d1;
	sa.account_no=1000;
	sa.account_balance=789450;
	
	//adding customer to account
	sa.addcustomer(c);
	
	//account customer details
	sa.account_customer_details.show();
	
	
	//specific details of account
	sa.specific_detail();
	
	//remove customer from account
	sa.removecustomer(c);
	
	//account customer details
	sa.account_customer_details.show();
	
	//specific details of account
	sa.specific_detail();
	
}

