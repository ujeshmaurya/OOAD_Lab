#include "head.h"

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
