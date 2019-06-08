#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string name,number;
	ifstream fin("input.txt");
	fin>>name>>number;
	cout << setw(35) << left << "NAME " << setw(35) << right << "NUMBER\n\n";	
	while(fin)
	{
		cout << setw(35) << left << name << " " << setw(35) << right << number << "\n";	
		fin >> name >> number;	
	}
	fin.close();
	return 0;
}
