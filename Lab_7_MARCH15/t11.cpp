#include<bits/stdc++.h>
using namespace std;
class Person
{
	private:
		int id;
		string fname,lname;
	public:
		void setField(int id,string fname,string lname)
		{
			this->id=id;
			this->fname=fname;
			this->lname=lname;
		}
		void outputData()
		{
			cout<<"\n\nIdentity no. : "<<id<<"\nName : "<<fname<<" "<<lname;
		}
};
class Customer : public Person
{
	private:
		double balance;
	public:
		void setBal(double balance)
		{
			this->balance = balance;
		}
		void outputBal()
		{
			cout<<"\nBalance = "<<balance<<"\n\n";
		}
};
int main()
{
	Customer c1;
	c1.setField(1,"Ujesh","Maurya");
	c1.setBal(50000.50);
	c1.outputData();
	c1.outputBal();
}
