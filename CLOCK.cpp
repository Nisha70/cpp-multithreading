#include<bits/stdc++.h>
using namespace std;
int main() {
	int hours,minute,second;
	cin>>hours>>minute>>second;
	while(1) {
		cout<<hours<<":"<<minute<<":"<<second;
		sleep(1);

		if(second<59) {
			second++;
		} else {

			if(minute<59 && second==59) {

				minute++;
				second=0;
			} else {

				if(hours<23 && minute==59 && second==59) {
					hours++;
					minute=0;
					second=0;

				} else {

					hours=0;
					minute=0;
					second=0;
				}
			}
		}
		system("cls");


	}
}