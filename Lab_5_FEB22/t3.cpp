#include<bits/stdc++.h>

using namespace std;

class wreport
{
	private:
		int day;
		int ht;
		int lt;
		int rain;
		int snow;
	public:
		wreport()
		{
			day = 99;
			ht = 9999;
			lt = -9999;
			rain = 0;
			snow = 0;
		}
		friend istream& operator >>(istream&, wreport&);
		friend ostream& operator <<(ostream&, wreport&);
		friend wreport cmp(wreport ,wreport );
};

istream& operator >>(istream &a,wreport &s)
{
	cout<<"Enter Day : ";
	a>>s.day;
	cout<<"Enter high temp. : ";
	a>>s.ht;
	cout<<"Enter low temp. : ";
	a>>s.lt;
	cout<<"Enter amount of rain : ";
	a>>s.rain;
	cout<<"Enter amount of snow : ";
	a>>s.snow;
	cout<<endl;
}

ostream& operator <<(ostream &a,wreport &s)
{
	a<<"Day of month : "<<s.day<<endl;
	a<<"High Temperature : "<<s.ht<<endl;
	a<<"Low Temperature : "<<s.lt<<endl;
	a<<"Rain : "<<s.rain<<endl;
	a<<"Snow : "<<s.snow<<endl;
}

wreport cmp(wreport a,wreport b)
{
	wreport temp;
	temp.day=99;
	temp.ht=max(a.ht,b.ht);
	temp.lt=min(a.lt,b.lt);
	temp.snow=a.snow+b.snow;
	temp.rain=a.rain+b.rain;
	return temp;
}

int main()
{
	int n;
	cout<<"Enter number of days: ";
	cin>>n;
	cout<<"Enter weather data of "<<n<<" days:\n";
	wreport a[n],finalreport;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	finalreport=a[0];
	for(int i=1;i<n;i++)
	{
		finalreport=cmp(finalreport,a[i]);
	}
	cout<<"\nFinal Report:\n";
	cout<<finalreport;
	return 0;
}
