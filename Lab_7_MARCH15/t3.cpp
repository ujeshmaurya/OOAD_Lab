#include<bits/stdc++.h>
using namespace std;
class Person
{
	protected:
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
class Employee : public Person
{
	private:
		double hourlyRate;
		int dept;
	public:
		using Person::setField;
		Employee()
		{
			this->dept = 0;
			this->hourlyRate = 0.0;
		}
		void setField(int id,string fname,string lname,int dept,double hourlyRate)
		{
			this->dept = dept;
			this->hourlyRate = hourlyRate;
			this->fname = fname;
			this->lname = lname;
			this->id = id;
		}
		void outputData()
		{
			cout<<"\n\nIdentity no. : "<<id<<"\nName : "<<fname<<" "<<lname;
			cout<<"\nDepartment = "<<dept<<"\nHourly rate = "<<hourlyRate<<endl<<endl	;
		}
};
int main()
{
	Employee c1;
	c1.setField(1,"Ujesh","Maurya");
	c1.outputData();
	c1.setField(1,"Ujesh","Maurya",1338,800.70);
	c1.outputData();
}
