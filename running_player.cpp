#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
//accessing shared variable
//performing two task at same time runnig and time increment

static int stop=0;
using namespace std;
void time_till_now() {
	int t=0;
	while(1) {

		sleep(1);
		t++;
		if(stop==1)
		{
			cout<<"\ntime :"<<t<<endl;
			break;
		}
	}

}
void running() {
	cout<<"running"<<endl;
	cout<<"\nask to stop\n";
	int  s;
	cin>>s;
	if(s==1)
	{
		//if stop is performed it show total running time 
		stop=1;
		cout<<"\nstop running"<<endl;
		
	}
}
int main() {
	//running player
	thread t1(running);
	//calculate time of total run
	thread t2(time_till_now);
	
	t1.join();
	t2.join();


}