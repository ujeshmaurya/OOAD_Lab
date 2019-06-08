#include<bits/stdc++.h>

using namespace std;

class gadget
{
	private:
			string name;
			double price;
			string model;
	public:
			gadget(string a,double b,string c)
			{
				name=a;
				price=b;
				model=c;
			}
			gadget()
			{
			}
			void display()
			{
				cout<<"Name: "<<name<<"\nModel: "<<model<<"\nPrice: "<<price<<endl<<endl;
			}
			gadget operator +(gadget a)
			{
				string nam=name+" "+a.name;
				string mod=model+" "+a.model;
				gadget temp(nam,price,mod);
				temp.price+=a.price;
				return temp;
			}
};
int main()
{
	gadget laptop("laptop",50000.0,"15-AC033tx"),desktop("desktop",20000.0,"HP"),TV("Television",30000.0,"Panasonic");
	laptop.display();
	desktop.display();
	TV.display();
	gadget total;
	total=laptop+desktop+TV;
	total.display();
	return 0;
}
