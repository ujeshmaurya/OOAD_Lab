#include<bits/stdc++.h>

using namespace std;

class complex_num{
	private:
		int real;
		int comple;
	public:
		friend complex_num operator +(complex_num&,complex_num&);
		complex_num();
		~complex_num();
		void getno();
		void printno();
};
complex_num operator +(complex_num &a,complex_num &b)
{
	complex_num temp;
	temp.real=(b.real+a.real);
	temp.comple=(b.comple+a.comple);
	return temp;
}
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
	c=a+b;
	cout<<"Addition of these numbers: ";
	c.printno();
	return 0;
}

