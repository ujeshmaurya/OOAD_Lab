#include <bits/stdc++.h>

using namespace std;
string artists[]={"Monet","Picasso","Rembrandt"};
class Painting 
{
	protected:
		string title, name;
		double value;
	public:
		Painting(string title = "", string name = "") 
		{
			this->title=title;
			this->name=name;
			this->value=400;
		}
		void display() 
		{
			cout<<"Painting Description";
			cout<<"Title: "<<title<<endl;
			cout<<"Artist Name: "<<name<<endl;
			cout<<"Value: "<<value<<endl;
		}
};

class FamousPainting: public Painting 
{
	public:
		FamousPainting(string title, string name): Painting(title, name) 
		{
			this->value=25000;
		}
};

bool check_artist(string name) 
{
	for(int i=0;i<3;i++) 
		if (artists[i]==name) 
			return true;
	return false;
}

int main() 
{
	int MAX;
	cout<<"Enter no. of paintings: ";
	cin>>MAX;
	Painting *paintings[MAX];
	string title, name;
	for(int i=0;i<MAX;i++) 
	{
		cout<<"Enter Title of Painting #"<<(i + 1)<<" ";
		cin>>title;
		cout<<"Enter Artist Name #"<<(i + 1)<<" ";
		cin>>name;
		if (!check_artist(name)) 
			paintings[i]=new Painting(title, name);
		else 
			paintings[i]=new FamousPainting(title, name);
	}
	for(int i=0;i<MAX;i++) 
	{
		paintings[i]->display();
	}
	return 0;
}
