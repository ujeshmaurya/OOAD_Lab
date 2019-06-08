#include <bits/stdc++.h>

using namespace std;

class Television 
{
	friend istream & operator >> (istream &, Television &);
	friend ostream & operator << (ostream &, Television &);
	int m_no;
	double size, cost;
	public:
		int set_data(int m_no, double size, double cost) 
		{
			this->m_no=m_no;
			this->size=size;
			this->cost=cost;
		}
};

istream & operator >> (istream & obj, Television &T) 
{
	cout << "Enter Model Number ";
	obj >> T.m_no;
	cout << "Enter Screen Size ";
	obj >> T.size;
	cout << "Enter cost ";
	obj >> T.cost;
	if (T.m_no > 9999) throw(1);
	else if (T.size < 12 || T.size > 70) throw(2);
	else if (T.cost < 0 || T.cost > 5000) throw(3);
	return obj;
}

ostream & operator << (ostream & obj, Television &T) 
{
	obj <<"Model No "<<T.m_no<<", Screen Size "<<T.size<<" Inches, cost Rs. "<<T.cost<<endl;;
	return obj;
}

int main() 
{
	Television T;
	try 
	{
		cin >> T;
	} 
	catch (int error) 
	{
		cout << "Error!! Incorrect ";
		if (error == 1) cout << "Model Number" << endl;
		else if (error == 2) cout << "Screen Size" << endl;
		else if (error == 3) cout << "cost" << endl;
		T.set_data(0, 0, 0);
	}
	cout << "Specifications of Telelvision:\n" << endl;
	cout << T << endl;
	return 0;
}
