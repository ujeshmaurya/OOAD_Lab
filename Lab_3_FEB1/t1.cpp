#include<bits/stdc++.h>

using namespace std;

class user
{
	private:
			
	public:
		int userid;
			user();
			~user();
			static int counta,countb;
};
int user::counta=0;
int user:: countb=0;
user::user()
{
	counta++;
	cout<<"Objects Created\nObjects created count : "<<counta<<endl;
}

user::~user()
{
	countb++;
	cout<<"Objects Destroyed id= "<<userid<<"\nObjects destroyed count : "<<countb<<endl;
}

int main()
{
	
	//while(1)
	{
		cout<<"Enter how many objects u want to create: ";
		int n;
		cin>>n;
		user a[n];
		for(int i=0;i<n;i++)
			a[i].userid=i+1;
	}
	return 0;
}
