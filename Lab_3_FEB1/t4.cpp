#include<bits/stdc++.h>

using namespace std;

class inventoryitem
{
	private:
			int stocknum;
			double price;
	public:
			void setsn(int n)
			{
				stocknum=n;
			}
			void setprice(double p)
			{
				price=p;
			}
			void displayitem()
			{
				cout<<"Inventory Item stocknum = "<<stocknum<<"\nInventory Item price = "<<price<<endl<<endl;
			}
			inventoryitem()
			{
				cout<<"Inventory Item object created\n";
			}
			~inventoryitem()
			{
				cout<<"Inventory Item object destroyed\n";
			}
};

class salesperson
{
	private:
			int id;
			string name;
	public:
			void setid(int n)
			{
				id=n;
			}
			void setname(string x)
			{
				name=x;
			}
			void displayperson()
			{
				cout<<"Salesperson id = "<<id<<"\nSalesperson name = "<<name<<endl<<endl;
			}
			salesperson()
			{
				cout<<"Salespereson object created\n";
			}
			~salesperson()
			{
				cout<<"Salespereson object destroyed\n";
			}
};

class transaction
{
	private:
			int tnum;
			inventoryitem t;
			salesperson p;
	public:
			transaction(int num,int item,double amt,int id,string name)
			{
				cout<<"Transaction object created\n";
				tnum=num;
				t.setsn(item);
				t.setprice(amt);
				p.setid(id);
				p.setname(name);
			}
			void displaytransaction()
			{
				cout<<"\nTnum = "<<tnum<<endl;
				t.displayitem();
				p.displayperson();
			}
			~transaction()
			{
				cout<<"Transaction object destroyed\n";
			}
};

int main()
{
	transaction t(1,2,10.9,4,"ujesh");
	t.displaytransaction();
	return 0;
}
