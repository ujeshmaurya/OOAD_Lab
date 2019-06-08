#include<bits/stdc++.h>
using namespace std;

class Rectangle                                                                                                          
{
	protected:
		int length;
		int breadth;
		int area;
	public:
		Rectangle()
		{
			length = 0;
			breadth = 0;
			area = 0;
		}
		void getData(int length, int breadth)
		{
			this->length = length;
			this->breadth = breadth;
		}
		void showData()
		{
			cout<<"\n\nLength = "<<length<<"\nBreadth = "<<breadth<<endl;
		}
		void calculate()
		{
			area = length * breadth;
			cout << "Area = " << area << endl;
		}
};

class Block : public Rectangle
{
	private:
		int height;
		int volume;
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
		void calculate()
		{
			volume = length * breadth * height;
			cout << "Volume = " << volume << endl << endl;
		}
};

int main()
{
	Block obj;
	obj.getData(4,5);
	obj.getHeight(6);
	obj.showData();
	obj.showHeight();
	obj.calculate();
	return 0;
}
