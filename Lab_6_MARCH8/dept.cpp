#include<bits/stdc++.h>

using namespace std;

class department
{
	string deptname;
	string deptheadname;
	int classes;
	string *courses;
	public:
		~department();
		department();
		department(string,string,int);
		friend ostream& operator <<(ostream&, department&);
		bool operator <(department);
		bool operator >(department);
		department &operator =(department&);
};

department::department()
{
	deptname="null";
	deptheadname="null";
	classes=0;
	courses = new string [1];
	courses[0]="null";
}

department::~department()
{
	cout<<"Object destroyed\n";
}

department::department(string a,string b,int x)
{
	deptname=a;
	deptheadname=b;
	classes=x;
	cout<<"Enter the name of classes:\n";
	courses = new string [classes];
	for(int i=0;i<classes;i++)
	{
		cin>>courses[i];
	}
}

ostream& operator <<(ostream &a,department &s)
{
	a<<"Department Name: "<<s.deptname<<"\n";
	a<<"Department's Head Name: "<<s.deptheadname<<"\n";
	a<<"No. of courses offered: "<<s.classes<<"\n";
	a<<"List of all courses offered: \n";
	for(int i=0;i<s.classes;i++)
	{
		a<<s.courses[i]<<"\n";
	}
}

bool department::operator <(department a)
{
	if(this->classes < a.classes)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool department::operator >(department a)
{
	if(this->classes >= a.classes)
	{
		return true;
	}
	else
	{
		return false;
	}
}

department& department::operator =(department &obj)
{
	int x;
	deptname=obj.deptname;
	deptheadname=obj.deptheadname;
	classes=obj.classes;
	delete [] courses;
	courses = new string [classes];
	for(x=0;x<classes;x++)
	{
		courses[x]=obj.courses[x];
	}
	return *this;
}

int main()
{
	department obj[3];
	string name,hname;
	int c;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter department's name: ";
		cin>>name;
		cout<<"Enter department's head name: ";
		cin>>hname;
		cout<<"Enter no. of courses offered: ";
		cin>>c;
		department temp(name,hname,c);
		obj[i]=temp;
	}
	for(int i=0;i<3;i++)
	{
		cout<<"\n\nDepartment no. = "<<i+1<<endl;
		cout<<obj[i];
	}
	department maxx=obj[0];
	department minn=obj[0];
	for(int i=1;i<3;i++)
	{
		if(maxx<obj[i])
			maxx=obj[i];
		if(minn>obj[i])
			minn=obj[i];
	}
	cout<<"\n\nMax. Department is:\n";
	cout<<maxx;
	cout<<"\nMin. Department is:\n";
	cout<<minn;
}
