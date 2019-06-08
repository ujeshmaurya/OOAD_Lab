#include<bits/stdc++.h>

using namespace std;

class arr
{
	private:
		int n;
		vector<int> a;
	public:
		void getinput();
		friend class add;
};
void arr::getinput()
{
	cout<<"Enter the array size: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
}
class add
{
	private:
		int sum;
	public:
		add(){
			sum=0;
		}
		void sumofvector(arr &x)
		{
			vector<int>::iterator i;
			for(i=x.a.begin(); i!=x.a.end(); i++)
			{
				sum+=*i;
			}
			cout<<"Average is: "<<(float)sum/(float)x.n<<endl;
		}
};
int main()
{
	arr obj;
	obj.getinput();
	add obj1;
	obj1.sumofvector(obj);
	return 0;
}
