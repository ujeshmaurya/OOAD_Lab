#include<bits/stdc++.h>

using namespace std;

class sub
{
	private:
			int x;
			int y;
			int z;
	public:
			sub(int a,int b,int c)
			{
				x=a;
				y=b;
				z=c;
			}
			void display()
			{
				cout<<"Values: "<<x<<" "<<y<<" "<<z<<endl;
			}
			void operator -()
			{
				x=-x;
				y=-y;
				z=-z;
			}
};
int main()
{
	sub obj(1,2,3);
	-obj;
	obj.display();
	return 0;
}
