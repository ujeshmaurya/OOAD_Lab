#include<bits/stdc++.h>

using namespace std;

class pizza
{
	private:
			string topping;
			int size;
			int price;
	public:
			pizza();
			~pizza();
			pizza(string);
			void display();
			pizza(string,int);
};
pizza::pizza()
{
	topping="cheese";
	size=12;
	price=350;
}

pizza::pizza(string x)
{
	topping=x;
	size=12;
	if(x=="cheese")
		price=350;
	else
		price=350+80;
}

pizza::pizza(string x,int y)
{
	topping=x;
	size=y;
	if(x=="cheese"&&y<=12)
		price=350;
	else if(x=="cheese"&&y>12)
		price=350+40;
	else if(x!="cheese"&&y<=12)
		price=350+80;
	else
		price=350+80+40;
}

pizza::~pizza()
{
	
}

void pizza::display()
{
	cout<<"Your order is a "<<size<<" inch "<<topping<<" pizza of Rs. "<<price<<endl;
}

int main()
{
	cout<<"The standard pizza is:\nA 12-inch pizza(cheese). Price 350 Rs.\nDo you want the standard pizza?\n";
	string c;
	cin>>c;
	if(c=="y")
	{
		pizza a;
		a.display();
	}
	else
	{
		cout<<"Enter the topping: ";
		string x;
		cin>>x;
		cout<<"Do you want to enter size of pizza(y/n): ";
		string cc;
		cin>>cc;
		if(cc=="y")
		{
			cout<<"Enter the size: ";
			int n;
			cin>>n;
			pizza a(x,n);
			a.display();
		}
		else
		{
			pizza a(x);
			a.display();
		}	
	}
	return 0;
}
