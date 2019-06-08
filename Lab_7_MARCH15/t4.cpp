#include<bits/stdc++.h>
using namespace std;

class Rectangle                                                                                                          
{
	protected:
		int length;
		int breadth;
	public:
		Rectangle()
		{
			length = 0;
			breadth = 0;
		}
		void getData(int length, int breadth)
		{
			this->length = length;
			this->breadth = breadth;
		}
		void showData()
		{
			cout<<"Length = "<<length<<"\nBreadth = "<<breadth<<endl;
		}
};

class Block : public Rectangle
{
	private:
		int height;
	public:
		Block()
		{
			height = 0;
		}
		void getHeight(int height)
		{
			this->height = height;
		}
		void showHeight()
		{
			cout<<"Height = "<<height<<endl;
		}
};

int main()
{
	Block obj;
	obj.getData(4,5);
	obj.getHeight(6);
	obj.showData();
	obj.showHeight();
	return 0;
}
