#include<bits/stdc++.h>

using namespace std;

class classroom
{
	string *student;
	int numst;
	int gradelevel;
	public:
		~classroom();
		classroom();
		void display();
		void getinput();
		classroom &operator =(classroom&);
};

classroom::classroom()
{
	numst=0;
	gradelevel=1;
}

classroom::~classroom()
{
	cout<<"Object destroyed\n";
}

void classroom::display()
{
	cout<<"Gradelevel: "<<gradelevel<<endl<<"No. of students: "<<numst<<endl;
	for(int i=0;i<numst;i++)
	{
		cout<<student[i]<<"\n";
	}
}

void classroom::getinput()
{
	cout<<"Enter grade level: ";
	cin>>gradelevel;
	cout<<"Enter no. of students in class: ";
	cin>>numst;
	cout<<"Enter students name:\n";
	student = new string [numst];
	for(int i=0;i<numst;i++)
	{
		//char temp[100];
		//scanf(" %[^\n]s",temp);
		//student[i]=string(temp);
		cin>>student[i];
	}
}

classroom& classroom::operator =(classroom &obj)
{
	int x;
	gradelevel=obj.gradelevel;
	numst=obj.numst;
	delete [] student;
	student = new string [numst];
	for(x=0;x<numst;x++)
	{
		student[x]=obj.student[x];
	}
	return *this;
}
int main()
{
	classroom one;
	cout<<"Enter for class first:\n";
	one.getinput();
	{
		classroom second;
		cout<<"Enter for class second:\n";
		second.getinput();
		cout<<"\nFirst class:\n";
		one.display();
		cout<<"\nSecond class:\n";
		second.display();
		one=second;
		cout<<"\nFirst class:\n";
		one.display();
	}
	cout<<"\nFirst class:\n";
	one.display();
	return 0;
}
