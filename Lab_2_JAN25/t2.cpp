#include<bits/stdc++.h>

using namespace std;

class complex_num{
	private:
		int real;
		int comple;
	public:
		complex_num();
		~complex_num();
		int getreal();
		int getcomple();
		void getno();
		friend void addno(complex_num,complex_num,complex_num*);
		void printno();
};

complex_num::complex_num()
{
	real=comple=0;
}

complex_num::~complex_num()
{
	//cout<<"Objects Destroyed\n";
}

void complex_num::getno()
{
	cout<<"Enter the real part:\t";
	cin>>real;
	cout<<"Enter the imaginary part: ";
	cin>>comple;
}
void addno(complex_num a,complex_num b,complex_num* c)
{
	c->real=a.real+b.real;
	c->comple=a.comple+b.comple;
}
void complex_num::printno()
{
	cout<<"Complex No.: \t"<<real<<" + i"<<comple<<"\n";
}
int main()
{
	complex_num a,b,c;
	cout<<"Enter first complex number:\n";
	a.getno();
	cout<<"Enter second complex number:\n";
	b.getno();
	cout<<"First complex number is: ";
	a.printno();
	cout<<"Second complex number is: ";
	b.printno();
	addno(a,b,&c);
	cout<<"Addition of these numbers: ";
	c.printno();
	return 0;
}
