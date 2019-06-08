#include<bits/stdc++.h>

using namespace std;

class sale
{
	private:
			int rn;
			int amt;
	public:
			sale()
			{
			}
			friend istream& operator >>(istream&, sale&);
			friend ostream& operator <<(ostream&, sale&);
};
istream& operator >>(istream &a,sale &s)
{
	a>>s.rn;
	a>>s.amt;
}
ostream& operator <<(ostream &a,sale &s)
{
	a<<"Receipt No.: "<<s.rn<<endl;
	a<<"Amount: "<<s.amt<<endl;
}
int main()
{
	sale p;
	cin>>p;
	cout<<p;
	return 0;
}
