#include<bits/stdc++.h>

using namespace std;

class mail
{
	private:
		static string msg;
		string title,name,addr;
		static int count;
	public:
		mail(){
			count++;
		}
		void getdetails();
		void printmail(); 
};
int mail::count=0;
string mail::msg="You are cordially invited to be a guest in Bltizchlag(Cultural Fest of MNIT). Please send your RSVP";
void mail::getdetails()
{
	cout<<"Enter the title:\t";
	cin>>title;
	cout<<"Enter the name:\t";
	string s;
	cin>>s;
	name=s;
	cout<<"Enter the address:\t";
	cin>>addr;
}

void mail::printmail()
{
	cout<<"\n\n\t\t\t\t\tMAIL\nDear "<<title<<" "<<name<<",\n";
	cout<<addr<<endl;
	cout<<msg<<endl;
	cout<<"\t\t\t\t\t\t\tRegards\n\t\t\t\t\t\t\tUjesh\n";
	cout<<"\tCurrent Receipt = "<<count<<endl;
}

int main()
{
	int ind=0;
	while(1)
	{
		mail ptr;
		ptr.getdetails();
		ptr.printmail();
		cout<<"If you want to exit enter 0; else 1:  ";
		int x;
		cin>>x;
		if(!x)
			break;	
		ind++;
	}
	return 0;
}
