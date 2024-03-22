#include<bits/stdc++.h>
using namespace std;
//test id associated to testpaper and examiner by id
class test
{
	public:
		int testid;
		string name;
		float duration;
		string  starttime;
		int numberofquestion;
};
class testpaper
{
	public:
		int testid;
		string question;
		string choice1;
		string choice2;
		string choice3;
		string choice4;
		
};
class examiner
{
	public:
		int id;
		string name;
	public:
		void preparetest()
		{
			cout<<"prepare test"<<endl;
		}
		void modifytest()
		{
			cout<<"modify test"<<endl;
		}
		void declareresult()
		{
			cout<<"declare result"<<endl;
		}
		void checkcopies()
		{
			cout<<"check copies"<<endl;
		}
};
int main()
{
	//schedulling 2 tests consider monday and friday
	//monday
	test first,second;
	first.testid=1;
	first.name="unit_test 1";
	first.numberofquestion=5;
	first.starttime="10:00";
	first.duration=2;
	//friday
	second.testid=2;
	second.name="unit_test1";
	second.numberofquestion=3;
	second.starttime="12:00";
	second.duration=4;
	
	//object of test and testpaper are associated with testid;
	//testpaper object for the test on monday
	testpaper math,science;
	math.testid=1;
	math.question="wh";
	math.choice1="3.00";
	math.choice2="3.006";
	math.choice3="3.14";
	math.choice4="5.02";
	
	science.testid=1;
	science.question="wha";
	science.choice1="unive";
	science.choice2="univet";
	science.choice3="ultriolet";
	science.choice4="ement";
	
	
	
	
	
	//testpaper object for the test on friday
	testpaper hindi,sst;
	hindi.testid=2;
	hindi.question="whandi";
	hindi.choice1="sur";
	hindi.choice2="chd";
	hindi.choice3="satlite";
	hindi.choice4="ah";
	
	sst.testid=2;
	sst.question="name";
	sst.choice1="l";
	sst.choice2="d";
	sst.choice3="u";
	sst.choice4="a";
	
	//checking association of test and testpaper using testid
	if(hindi.testid==first.testid)
	{
		cout<<"todays testpaper"<<endl;
	}
	else
	{
		cout<<"not todays testpaper"<<endl;
	}
	
	
	//two examiners 
	//for monday e1  
	examiner e1,e2;
	e1.name="reee";
	e1.id=1; //here id is testid
	
	
	
	//e2 for friday
	e2.name="eee";
	e2.id=2;	//here id is testid
	 
	//testing id of test object and examiner object
	if(e1.id==first.testid)
	{
		cout<<"allocated examiner"<<endl;
		
	}
	else
	{
		cout<<"not the assigned  examiner"<<endl;
	}
	
	
	
}
