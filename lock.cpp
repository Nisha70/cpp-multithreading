#include<bits/stdc++.h>
using namespace std;

class employee_card {
	public:
		int emp_id;
		string name;

};
class database {
	private:
		vector<employee_card> e;
	public:
		void add_employee(employee_card ee) {
			e.push_back(ee);
		}
		void delete_employee(employee_card ww) {
			int i,g=0;;
			for(i=0; i<e.size(); i++) {
				if(e[i].emp_id==ww.emp_id) {
					cout<<"deleted"<<endl;
					g=1;
					break;
				}
			}

			if(g==0) {
				cout<<"not present"<<endl;
			}
		}
		void scan(employee_card ww) {
			int i,g=0;;
			for(i=0; i<e.size(); i++) {
				if(e[i].emp_id==ww.emp_id) {
					cout<<"door unlocked"<<endl;

					g=1;
					break;
				}
			}

			if(g==0) {

				cout<<"you cannot enter you are not part of organisation -- door locked --- alert system on"<<endl;


			}
		}
};
class scanner {
	public:
		scanner(database d,employee_card emp) {

			d.scan(emp);
		}
};
int main() {
	//employee creation
	employee_card n;
	n.emp_id=123;
	n.name="Mha";

	//database creation
	database d;
	//to same database add employee details
	d.add_employee(n);


	//scan the employee_card return door unlocked
	scanner(d,n);
	
	//new employee
	employee_card t;
	t.emp_id=345;
	t.name="kio";
	
	//scan the employee_card return otherwise
	scanner(d,t); 
	
}