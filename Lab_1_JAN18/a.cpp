#include<bits/stdc++.h>
 using namespace std;

class person
{
	private:
		string name;
		int age;
	public:
		void getdetails()
		{
			cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter age: ";
			cin>>age;
		}
		void showdetails()
		{
			cout<<"Thank you "<<name<<" ,Your age is "<<age<<" years."<<endl;
		}
};
int main()
{
	person a;
	a.getdetails();
	a.showdetails();
	return 0;
}
