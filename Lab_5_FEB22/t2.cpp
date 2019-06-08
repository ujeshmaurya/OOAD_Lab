#include<bits/stdc++.h>

using namespace std;

class soccerplayer
{
	private:
		int jer;
		int goals;
		int assist;
	public:
		friend istream& operator >>(istream&, soccerplayer&);
		friend ostream& operator <<(ostream&, soccerplayer&);
		friend bool operator >(soccerplayer a,soccerplayer b);
};

istream& operator >>(istream &a,soccerplayer &s)
{
	a>>s.jer;
	a>>s.goals;
	a>>s.assist;
}
ostream& operator <<(ostream &a,soccerplayer &s)
{
	a<<"Jersey number : "<<s.jer<<endl;
	a<<"Goals : "<<s.goals<<endl;
	a<<"Assists : "<<s.assist<<endl;
}

bool operator >(soccerplayer a,soccerplayer b)
{
	if(a.goals+a.assist>b.goals+b.assist)
		return true;
	return false;
}

int main()
{
	int n;
	cout<<"Enter number of players: ";
	cin>>n;
	soccerplayer arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter jersey no., goals and assists of "<<i+1<<" player:\n";
		cin>>arr[i];
	}
	int great=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[great])
			great=i;
	}
	cout<<"\nGreatest player is: \n";
	cout<<arr[great];
	return 0;
}
