#include<fstream>
#include<bits/stdc++.h>

using namespace std;

class InsurancePolicy
{
	private:
			int policyNumber,policyValue,premium;
			string lname;
	public:
			friend istream&  operator>>(istream &in,InsurancePolicy &c);
			friend ostream&  operator<<(ostream &out,InsurancePolicy c);
			friend void check();
};
istream&  operator>>(istream &in,InsurancePolicy &c)
{
	in>>c.policyNumber;
	in>>c.policyValue;
	in>>c.premium;
	in>>c.lname;
}
ostream&  operator<<(ostream &out,InsurancePolicy c)
{
	out<<c.policyNumber<<endl<<c.policyValue<<endl<<c.premium<<endl<<c.lname<<endl;
}

void check()
{
	int i;
	cout<<"Enter the minimum policy value to search for: ";
	cin>>i;
	ifstream in("op.txt");
	InsurancePolicy obj;	
	while(in>>obj)
	{
		if(obj.policyValue>=i)
			cout<<obj<<endl;
	}
}

int main()
{
	InsurancePolicy obj;
	cout << "Enter the number of objects you want to enter: ";
	int n;
	cin>>n;
	ofstream out("op.txt",ios::app);
	for(int i=0; i<n; i++ )
	{
		cout<<"Input for policyNumber, policyValue, premium, name\n";
		cin>>obj;
		out<<obj;
	}
	ifstream in("op.txt");
	while(in>>obj)
	{
		cout<<obj<<endl;
	}
	check();
	return 0;
}
