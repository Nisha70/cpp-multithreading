
#include<bits/stdc++.h>
//#include"atm.h"
#include"atmm.cpp"
using namespace std;
int main()
{
	
	//create visa card 
	visa_card_holder xyz;
	//putting details
	xyz.card_holder_name="xyz";
	xyz.card_number=456;
	xyz.set_pin(322,"2/34");

	//checking details
	xyz.show();
	
	//insert visa smart card to atm machine
	xyz.insert_to_atm();
	xyz.removecard();
	
	visa_card_holder x;
	x.card_holder_name="gh";
	x.card_number=345;
	x.set_pin(222,"3/64");
	
	x.insert_to_atm();
	
	
	
	
}