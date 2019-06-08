#include<bits/stdc++.h>

using namespace std;

class date
{
	private:
			int day;
			int month;
			int year;
	public:
			date()
			{
				day=1;
				month=1;
				year=2000;
			}
			date(int a,int b,int c)
			{
				if(a<1||a>31)	cout<<"Invalid date\n";
				if(b<1||b>12)	cout<<"Invalid month\n";
				if(c<1990||c>2020) cout<<"Invalid year\n";
				day=a;
				month=b;
				year=c;
			}
			void displaydate()
			{
				cout<<"Date is : "<<day<<" / "<<month<<" / "<<year<<endl;
			}
};

class person
{
	private:
		string fname;
		string mname;
		string lname;
	public:
			person()
			{
				fname="Ram";
				mname="Gopal";
				lname="Verma";
			}
			person(string a,string b,string c)
			{
				fname=a;
				mname=b;
				lname=c;
			}
			void displayperson()
			{
				cout<<"NAME of Subscriber: "<<fname<<" "<<mname<<" "<<lname<<"\n\n";
			}
};

class magazine
{
	private:
			person p;
			date sdate;
			date edate;
	public:
			magazine(person a,date b,date c)
			{
				p=a;
				sdate=b;
				edate=c;
			}
			void displaymagazine()
			{
				p.displayperson();
				cout<<"Starting ";
				sdate.displaydate();
				cout<<"Ending ";
				edate.displaydate();
			}
};

int main()
{
	string a,b,c;
	cout<<"Enter personal details\n";
	cout<<"First name: ";
	cin>>a;
	cout<<"Middle name: ";
	cin>>b;
	cout<<"Last name: ";
	cin>>c;
	person p(a,b,c);
	int d1,d2,m1,m2,y1,y2;
	cout<<"Enter starting date\n";
	cin>>d1>>m1>>y1;
	cout<<"Enter ending date\n";
	cin>>d2>>m2>>y2;
	date sd(d1,m1,y1);
	date ed(d2,m2,y2);
	magazine m(p,sd,ed);
	m.displaymagazine();
	return 0;
}
