#include<bits/stdc++.h>

using namespace std;

class pizza
{
	private:
			string topping;
			int size;
			int price;
	public:
			//pizza();
			~pizza();
			//pizza(string);
			void display();
			//pizza(string,int);
			pizza(string sbc="cheese",int n=12,int p=350)
			{
				topping=sbc;
				size=n;
				price=p;
			}
			void setvalue();
};


void pizza::setvalue()
{
		cout<<"Enter the topping: ";
		cin>>topping;
		cout<<"Enter the size: ";
		cin>>size;
		if(topping=="cheese"&&size<=12)
			price=350;
		else if(topping=="cheese"&&size>12)
			price=350+40;
		else if(topping!="cheese"&&size<=12)
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
		pizza a;
		a.setvalue();
		a.display();
	}
	return 0;
}
