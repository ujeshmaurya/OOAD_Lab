#include<bits/stdc++.h>

using namespace std;

class meal
{
	private:
		string name;
		int calorie;
	public:
		meal(string a="pizza", int b=200)
		{
			name=a;
			calorie=b;
		}
		friend istream& operator >>(istream&, meal&);
		friend ostream& operator <<(ostream&, meal&);
		friend meal operator +(meal a,meal b);
};

istream& operator >>(istream &a,meal &s)
{
	a>>s.name;
	a>>s.calorie;
}
ostream& operator <<(ostream &a,meal &s)
{
	a<<"Meal name : "<<s.name<<endl;
	a<<"Calorie : "<<s.calorie<<endl;
}

meal operator +(meal a,meal b)
{
	meal temp("Daily_Total",a.calorie+b.calorie);
	return temp;
}

int main()
{
	meal bf,lunch,dinner;
	cout<<"Enter breakfast(name and calorie):\n";
	cin>>bf;
	cout<<"Enter lunch(name and calorie):\n";
	cin>>lunch;
	cout<<"Enter dinner(name and calorie):\n";
	cin>>dinner;
	
	cout<<"\nBreak fast is:\n";
	cout<<bf;
	cout<<"\nLunch is:\n";
	cout<<lunch;
	cout<<"\nDinner is:\n";
	cout<<dinner;
	
	meal total=bf+lunch+dinner;
	
	cout<<"\nTotal is: \n";
	cout<<total;
	return 0;
}
