#include<bits/stdc++.h>

using namespace std;
class bill
{
	private:
		string name;
		int units,u1,u2,u3;
		float total,t1,t2,t3,tax;
		bool tt;
	public:
		bill(string a,int x);
		void calcBill();
		float getTotal();
		int getUnits();
		void printBill();
};
bill::bill(string a,int x)
{
	name=a;
	units=x;
	total=0.0;
	t1=0.0;
	t2=0.0;
	t3=0.0;
	tax=0.0;
	tt=false;
}
int bill::getUnits()
{
	return units;
}
float bill::getTotal()
{
	return total;
}
void bill::calcBill()
{
	float ans=0.0;
	int temp=units;
	tax=0.0;
	u1=u2=u3=0;
	if(temp<=100)
	{
		ans=0.6*(float)temp;
		t1=ans;
		u1=temp;
		temp=0;
	}
	else if(temp>100&&temp<=300)
	{
		ans=0.6*(float)100;
		temp-=100;
		t1=ans;
		u1=100;
		ans+=0.8*(float)(temp);
		u2=temp;
		t2=ans-t1;
		temp=0;
	}
	else if(temp>300)
	{
		ans=0.6*(float)100;
		temp-=100;
		t1=ans;
		u1=100;
		ans+=0.8*(float)200;
		u2=200;
		t2=ans-t1;
		temp-=200;
		ans+=0.9*(float)(temp);
		u3=temp;
		t3=ans-t1-t2;
		temp=0;
	}
	if(ans<50)
		ans=50.0;
	if(ans>300)
	{
		ans=ans+(ans*0.15);
		tax=ans*0.15;
		tt=true;
	}
	total=ans;
}
void bill::printBill()
{
	cout<<"Name";
	for(int i=0;i<name.length()-4;i++)
		cout<<" ";
	cout<<"\tUnits";
	cout<<"\tBill\n";
	cout<<name<<"\t"<<units<<"\t";
	cout<<u1<<"*0.6= "<<t1<<"\n";
	if(u2>0)
	{
		for(int i=0;i<name.length()-4;i++)
		cout<<" ";
		cout<<"\t     \t";
		cout<<u2<<"*0.8= "<<t2<<"\n";
	}
	if(u3>0)
	{
		for(int i=0;i<name.length()-4;i++)
		cout<<" ";
		cout<<"\t     \t";
		cout<<u3<<"*0.9= "<<t3<<"\n";
	}
	if(tt)
	{
		for(int i=0;i<name.length()-4;i++)
		cout<<" ";
		cout<<"\t     \t";
		cout<<"Tax surcharge= "<<tax<<"\n";
	}
	for(int i=0;i<name.length()-4;i++)
	cout<<" ";
	cout<<"\t     \t";
	cout<<"Total= "<<total<<endl;
}
int main()
{
	string a;
	int x;
	cout<<"Enter name and units:\n";
	//scanf(" %[^\n]s",a);
	//getline(cin,a);
	cin>>a>>x;
	bill b(string(a),x);
	b.calcBill();
	b.printBill();
	return 0;
}

