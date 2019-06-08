#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

template<typename t>
class Stack
{
	private:
			t s[MAX];
			int top;
			bool overflow()
			{
				if(top>=MAX-1)
					return true;
				return false;
			}
			bool underflow()
			{
				if(top==-1)
					return true;
				return false;
			}
	public:
			Stack()
			{
				top=-1;
			}
			void push(t x)
			{
				if(!overflow())
					s[++top]=x;
				else
					cout<<"Stack Overflow Error\n";
			}
			t pop()
			{
				if(!underflow())
					return s[top--];
				else
				{
					cout<<"Stack Underflow Error\n";
					return 0;
				}
			}
			t peek()
			{
				if(!underflow())
					return s[top];
				else
				{
					cout<<"Stack Underflow Error\n";
					return 0;
				}
			}
};

int main()
{
	cout<<"Enter 1 to make integer stack\nEnter 2 to make char stack\nEnter 3 to make float stack\n";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		Stack<int> st;
		while(1)
		{
			cout << "Enter 1 to push\nEnter 2 to pop\nEnter 3 to peek on top element\nEnter 4 to exit\n\n";
			int c;
			cin>>c;
			if(c==1)
			{
				cout<< "Enter element to push on stack\n";
				int x;
				cin>>x;
				st.push(x);
			}
			else if(c==2)
			{
				cout << "Popped element is: "<< st.pop() <<endl;
			}
			else if(c==3)
			{
				cout<< "Element at top of stack is: "<< st.peek() << endl;
			}
			else if(c==4)
			{
				break;
			}
			else
			{
				cout<<"Invalid input\n";
			}
		}
	}
	else if(choice==2)
	{
		Stack<char> st;
		while(1)
		{
			cout << "Enter 1 to push\nEnter 2 to pop\nEnter 3 to peek on top element\nEnter 4 to exit\n\n";
			int c;
			cin>>c;
			if(c==1)
			{
				cout<< "Enter element to push on stack\n";
				char x;
				cin>>x;
				st.push(x);
			}
			else if(c==2)
			{
				cout << "Popped element is: "<< st.pop() <<endl;
			}
			else if(c==3)
			{
				cout<< "Element at top of stack is: "<< st.peek() << endl;
			}
			else if(c==4)
			{
				break;
			}
			else
			{
				cout<<"Invalid input\n";
			}
		}
	}
	else
	{
		Stack<float> st;
		while(1)
		{
			cout << "Enter 1 to push\nEnter 2 to pop\nEnter 3 to peek on top element\nEnter 4 to exit\n\n";
			int c;
			cin>>c;
			if(c==1)
			{
				cout<< "Enter element to push on stack\n";
				float x;
				cin>>x;
				st.push(x);
			}
			else if(c==2)
			{
				cout << "Popped element is: "<< st.pop() <<endl;
			}
			else if(c==3)
			{
				cout<< "Element at top of stack is: "<< st.peek() << endl;
			}
			else if(c==4)
			{
				break;
			}
			else
			{
				cout<<"Invalid input\n";
			}
		}
	}
	return 0;
}
