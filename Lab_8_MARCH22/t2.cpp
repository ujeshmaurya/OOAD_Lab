#include <bits/stdc++.h>

using namespace std;

class Student 
{
	friend istream & operator >> (istream &, Student &);
	friend ostream & operator << (ostream &, Student &);
	int id;
	double gpa;
	public:
		Student(int id = 0, double gpa = 0) 
		{
			this->id=id;
			this->gpa=gpa;
			validate();
		}
		void validate() 
		{
			if (id > 9999 || gpa < 0 || gpa > 4.0) throw(*this);
		}
};

istream & operator >> (istream & obj, Student &S) 
{
	cout<<"Enter Student ID ";
	obj>>S.id;
	cout<<"Enter Grade Point Average ";
	obj>>S.gpa;
	S.validate();
	return obj;
}

ostream & operator << (ostream & obj, Student &S) 
{
	obj<<"Student ID "<<S.id<<", Grade Point Average "<<S.gpa;
	return obj;
}

int main() 
{
	Student S;
	try 
	{
		S=Student(13381, 3.5);
	} 
	catch (Student object) 
	{
		cout<<"\nError!! Constructor Failed\n"<<endl;
		cout<<S<<endl;
		try 
		{
			cin>>S;
		} 
		catch(Student object) 
		{
			cout<<"\n\nError!! Extraction Operator Failed\n"<<endl;
			S=Student();
		}
	}
	cout<<"Student Details :";
	cout<<S<<endl<<endl;
	return 0;
}
