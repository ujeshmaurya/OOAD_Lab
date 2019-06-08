#include<bits/stdc++.h>
 using namespace std;

class matrix
{
	private:
		int mat1[100][100];
		int mat2[100][100];
		int n;
		int m;
	public:
		void getmatrix();
		
		void showmatrix();
		
		void addmatrix();
};

void matrix::getmatrix()
{
	cout<<"Enter no. of rows: ";
	cin>>n;
	cout<<"Enter no. of columns: ";
	cin>>m;
	cout<<"Enter matrix 1: \n";
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mat1[i][j];
	cout<<"Enter matrix 2: \n";
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mat2[i][j];
}
void matrix::showmatrix()
{
	cout<<"Matrix 1 is : \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<mat1[i][j]<<" ";
		cout<<endl;		
	}
	cout<<endl;
	cout<<"Matrix 2 is : \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<mat2[i][j]<<" ";
		cout<<endl;		
	}
	cout<<endl;
}
void matrix::addmatrix()
{
	cout<<"Addition of Matrix 1 and Matrix 2 is : \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<mat1[i][j]+mat2[i][j]<<" ";
		cout<<endl;		
	}
}
int main()
{
	matrix m;
	m.getmatrix();
	m.showmatrix();
	m.addmatrix();
	return 0;
}
