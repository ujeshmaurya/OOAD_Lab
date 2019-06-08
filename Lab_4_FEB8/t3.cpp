#include<bits/stdc++.h>

using namespace std;

class emp
{
	private:
			string name;
			double salary;
			string id;
	public:
			emp(string a,double b,string c)
			{
				name=a;
				salary=b;
				id=c;
			}
			void display()
			{
				cout<<"Name: "<<name<<"\nID: "<<id<<"\nSalary: "<<salary<<endl;
			}
			void operator +(double a)
			{
				salary+=a;
			}
};
int main()
{
	emp manager("RamGopalVerma",20000.0,"2014RCE5690");
	double inc;
	cout<<"Enter amount to increment in manager's salary : ";
	cin>>inc;
	manager+inc;
	manager.display();
	return 0;
}
