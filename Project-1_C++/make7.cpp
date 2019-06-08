#include<bits/stdc++.h>
#include<time.h>
#include<unistd.h>

using namespace std;
#define MAX 10

class utility
{
	public:
		void printHeader();
		void printOptions();
};

class matrix
{
	protected:
		char index_matrix[MAX][MAX];
		int size;
		int play_matrix[MAX][MAX];
		bool filled_index[MAX][MAX];
		bool visited[MAX][MAX];
	public:
		matrix(int x = 3);
		~matrix();
		void fillIndexMatrix();
		void printMatrix();
		pair<int,int> convertIndexes(char);
		char convertChar(pair<int, int>);
		void resetMatrix();
		void normaliseMatrix(int, int, int, int&);
		void changeMatrix(int, int, int);
		void resetVisited();
};

class player
{
	protected:
		string name;
		int score;
	public:
		player(string = "Noobie", int = 0);
		void getName();
		void printScore();
};

//INHERITANCE
class game : public utility, public matrix, public player
{
	private:
		int num;
		int p1,p2;
		int level;
		
	public:
		game(int level=1,int size=3);
		void randomNumber();
		void setLevel(int);
		void calcMatrix();
		void printWindow();

};

void matrix::resetVisited()
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			visited[i][j]=false;
	}
}
void matrix::normaliseMatrix(int xc, int yc, int val, int &cnt)
{
	cnt++;
	visited[xc][yc] = true;
	if(xc - 1 >= 0 && yc - 1 >= 0 && !visited[xc - 1][yc - 1] && play_matrix[xc-1][yc-1] == val)
	{
		normaliseMatrix(xc-1, yc-1, val, cnt);
	}
	if(yc - 1 >= 0 && !visited[xc][yc - 1] && play_matrix[xc][yc-1] == val)
	{
		normaliseMatrix(xc, yc-1, val, cnt);
	}
	if(xc + 1 < size && yc - 1 >= 0 && !visited[xc + 1][yc - 1] && play_matrix[xc+1][yc-1] == val)
	{
		normaliseMatrix(xc+1, yc-1, val, cnt);
	}
	if(xc + 1 < size && !visited[xc + 1][yc] && play_matrix[xc+1][yc] == val)
	{
		normaliseMatrix(xc+1, yc, val, cnt);
	}
	if(xc + 1 < size && yc + 1 < size && !visited[xc + 1][yc + 1] && play_matrix[xc+1][yc+1] == val)
	{
		normaliseMatrix(xc+1, yc+1, val, cnt);
	}
	if(yc + 1 < size && !visited[xc][yc + 1] && play_matrix[xc][yc+1] == val)
	{
		normaliseMatrix(xc, yc+1, val, cnt);
	}
	if(xc - 1 >= 0 && yc + 1 < size && !visited[xc - 1][yc + 1] && play_matrix[xc-1][yc+1] == val)
	{
		normaliseMatrix(xc-1, yc+1, val, cnt);
	}
	if(xc - 1 >= 0 && !visited[xc - 1][yc] && play_matrix[xc-1][yc] == val)
	{
		normaliseMatrix(xc-1, yc, val, cnt);
	}
}

void matrix::changeMatrix(int xc, int yc, int val)
{
	visited[xc][yc] = true;
	if(xc - 1 >= 0 && yc - 1 >= 0 && !visited[xc - 1][yc - 1] && play_matrix[xc-1][yc-1] == val)
	{
		changeMatrix(xc-1, yc-1, val);
	}
	if(yc - 1 >= 0 && !visited[xc][yc - 1] && play_matrix[xc][yc-1] == val)
	{
		changeMatrix(xc, yc-1, val);
	}
	if(xc + 1 < size && yc - 1 >= 0 && !visited[xc + 1][yc - 1] && play_matrix[xc+1][yc-1] == val)
	{
		changeMatrix(xc+1, yc-1, val);
	}
	if(xc + 1 < size && !visited[xc + 1][yc] && play_matrix[xc+1][yc] == val)
	{
		changeMatrix(xc+1, yc, val);
	}
	if(xc + 1 < size && yc + 1 < size && !visited[xc + 1][yc + 1] && play_matrix[xc+1][yc+1] == val)
	{
		changeMatrix(xc+1, yc+1, val);
	}
	if(yc + 1 < size && !visited[xc][yc + 1] && play_matrix[xc][yc+1] == val)
	{
		changeMatrix(xc, yc+1, val);
	}
	if(xc - 1 >= 0 && yc + 1 < size && !visited[xc - 1][yc + 1] && play_matrix[xc-1][yc+1] == val)
	{
		changeMatrix(xc-1, yc+1, val);
	}
	if(xc - 1 >= 0 && !visited[xc - 1][yc] && play_matrix[xc-1][yc] == val)
	{
		changeMatrix(xc-1, yc, val);
	}
	filled_index[xc][yc] = false;
	play_matrix[xc][yc] = 0;
}


void game::printWindow()
{
	getName();
	lab5:
	while(1)
	{
		resetVisited();
		bool flag=false,error=false;
		randomNumber();
		lab1:
		system("clear");
		printHeader();
		printScore();
		printMatrix();
		printOptions();
		if(num == 2)
		{
			char option1,option2;
			cout<<"Your numbers: "<<p1<<" "<<p2<<endl;
			if(error)
			{
				cout<<"Invalid Input\n";
				error=false;
			}
			cout<<"Enter Box letter: ";
			if(!flag)
			{
				system("stty raw");
				cin>>option1;
				system("stty cooked");
				cout<<endl;
			}
			if(option1 == '3')
				break;
			else if(option1 == '1')
			{
				lab3:
				system("clear");
				cout<<"ddfghjhaaaaaaaaaaaaaaaaaaaaaaaaaddddddddddddddddddddddaaaaaaaaa"<<endl;
				cout<<"To go back press 'b': ";
				char back;
				system("stty raw");
				cin>>back;
				system("stty cooked");
				if(back=='b')
					goto lab1;
				else
					goto lab3;
			}
			else if(option1 == '2')
			{
				resetMatrix();
				goto lab5;
			}
			if(option1-97>=size*size)
			{
				error=true;
				goto lab1;
			}
			pair<int,int> p = convertIndexes(option1);
			int xc = p.first, yc = p.second, i;
			vector <char> oparr(9); int osize = 0;
			if(flag)
			{
				flag=false;
				cout<<"Invalid input\n";
			}
			cout << "You have the following options: ";
			if(xc - 1 >= 0 && yc - 1 >= 0 && !filled_index[xc - 1][yc - 1])
			{
				oparr[osize++] = convertChar(make_pair(xc - 1, yc - 1));
			}
			if(yc - 1 >= 0 && !filled_index[xc][yc - 1])
			{
				oparr[osize++] = convertChar(make_pair(xc, yc - 1));
			}
			if(xc + 1 < size && yc - 1 >= 0 && !filled_index[xc + 1][yc - 1])
			{
				oparr[osize++] = convertChar(make_pair(xc + 1, yc - 1));
			}
			if(xc + 1 < size && !filled_index[xc + 1][yc])
			{
				oparr[osize++] = convertChar(make_pair(xc + 1, yc));
			}
			if(xc + 1 < size && yc + 1 < size && !filled_index[xc + 1][yc + 1])
			{
				oparr[osize++] = convertChar(make_pair(xc + 1, yc + 1));
			}
			if(yc + 1 < size && !filled_index[xc][yc + 1])
			{
				oparr[osize++] = convertChar(make_pair(xc, yc + 1));
			}
			if(xc - 1 >= 0 && yc + 1 < size && !filled_index[xc - 1][yc + 1])
			{
				oparr[osize++] = convertChar(make_pair(xc - 1, yc + 1));
			}
			if(xc - 1 >= 0 && !filled_index[xc - 1][yc])
			{
				oparr[osize++] = convertChar(make_pair(xc - 1, yc));
			}
			oparr[osize++] = '<';
			for(i = 0; i < osize; i++)
			{
				cout << oparr[i] << " ";
			}
			cout << endl;
			system("stty raw");
			cin>>option2;
			system("stty cooked");
			for(i = 0; i <  osize; i++)
			{
				if(oparr[i] == option2)
				{
					break;
				}
			}
			if(i == osize)
			{
				flag=true;
				goto lab1;
			}
			if(option2 == '<')
			{
				goto lab1;
			}
			int xd = convertIndexes(option2).first,yd = convertIndexes(option2).second, cnt = 0,cnt2 = 0;
			play_matrix[xc][yc] = p1;
			play_matrix[xd][yd] = p2;
			filled_index[xc][yc] = true;
			filled_index[xd][yd] = true;
			fillIndexMatrix();
			while(1)
			{
				int k1 = play_matrix[xc][yc];
				cnt = 0;
				if(k1!=0){
					resetVisited();
					normaliseMatrix(xc, yc, k1, cnt);
					cout<<"haha cnt1 "<<cnt<<endl;
					if(cnt >= 3)
					{
						resetVisited();
						changeMatrix(xc, yc, k1);
						filled_index[xc][yc] = true;
						play_matrix[xc][yc] = k1 + 1;
						fillIndexMatrix();
					}
				}
				cnt2 = 0;
				int k2 = play_matrix[xd][yd];
				if(k2 != 0)
				{
					resetVisited();
					normaliseMatrix(xd, yd, k2, cnt2);
					cout<<"haha cnt2 "<<cnt2<<endl;
					if(cnt2 >= 3)
					{
						resetVisited();
						changeMatrix(xd, yd, k2);
						filled_index[xd][yd] = true;
						play_matrix[xd][yd] = k2 + 1;
						fillIndexMatrix();
					}
				}
				if(cnt < 3 && cnt2 < 3)
				{
					break;
				}
			}
		}
		else
		{
			char option1;
			cout<<"Your number: "<<p1<<endl;
			cout<<"Enter Box letter: ";
			if(error)
			{
				cout<<"Invalid Input\n";
				error=false;
			}
			system("stty raw");
			cin>>option1;
			system("stty cooked");
			cout<<endl;
			if(option1 == '3')
				break;
			else if(option1 == '1')
			{
				lab4:
				system("clear");
				cout<<"ddfghjhaaaaaaaaaaaaaaaaaaaaaaaaaddddddddddddddddddddddaaaaaaaaa"<<endl;
				cout<<"To go back press 'b': ";
				char back;
				system("stty raw");
				cin>>back;
				system("stty cooked");
				if(back=='b')
					goto lab1;
				else
					goto lab4;
			}
			else if(option1 == '2')
			{
				resetMatrix();
				goto lab5;
			}
			if(option1-97>=size*size)
			{
				error=true;
				goto lab1;
			}
			pair<int,int> p = convertIndexes(option1);
			int xc = p.first, yc = p.second,i, cnt = 0;
			play_matrix[xc][yc] = p1;
			filled_index[xc][yc] = true;
			fillIndexMatrix();
			while(1)
			{
				int k = play_matrix[xc][yc];
				resetVisited();
				cnt = 0;
				normaliseMatrix(xc, yc, k, cnt);
				cout<<"haha cnt "<<cnt<<endl;
				if(cnt >= 3)
				{
					resetVisited();
					changeMatrix(xc, yc, k);
					filled_index[xc][yc] = true;
					play_matrix[xc][yc] = k + 1;
					fillIndexMatrix();
				}
				else
				{
					break;
				}
			}
		}
		
	}
}

game::game(int level,int size):matrix(size)
{
	this->level = level;
}

void game::setLevel(int level)
{
	this->level = level;
}

void game::randomNumber()
{
	srand(time(0));
	int temp = rand()%4;
	if(temp == 0)
	{
		num = 2;
		int temp2 = rand()%2;
		if(temp2 == 0)
		{
			p1 = 1;
			p2 = 2;
		}
		else
		{
			p1 = 2;
			p2 = 1;
		}
	}
	else
	{
		num = 1;
		p1 = rand()%2+1;
		p2 = -1;
	}
}

void utility::printHeader()
{
	cout << "::[ MAKE7 GAME]::\t\t\t\t\tSCORE: ";
}

void utility::printOptions()
{
	cout << "1 - help\t" << "2 - restart\t" << "3 - Quit" << endl;
}

matrix::matrix(int x)
{
	size = x;
	char c = 'a';
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			filled_index[i][j] = false;
			index_matrix[i][j] = c;
			play_matrix[i][j] = 0;
			c++;
		}
	}
}

matrix::~matrix()
{
	cout<<"Game Ended"<<endl;
}
	
pair<int,int> matrix::convertIndexes(char c)
{
	pair<int,int> p;
	p.first=(c-97)/size;
	p.second=(c-97)%size;
	return p;
}

char matrix::convertChar(pair<int, int> p)
{
	char c = p.first * size + p.second + 97;
	return c;
}

void matrix::resetMatrix()
{
	char c = 'a';
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			filled_index[i][j] = false;
			index_matrix[i][j] = c;
			play_matrix[i][j] = 0;
			c++;
		}
	}
}

void matrix::fillIndexMatrix()
{
	int i, j;
	char c = 'a';
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(!filled_index[i][j])
			{
				index_matrix[i][j] = c;
			}
			else index_matrix[i][j] = '*';
			c++;
		}
	}
}

void matrix::printMatrix()
{
	cout<<"\t";
	for(int j = 0; j < size; j++){
		cout << " ___";
	}
	cout << "\t\t\t";
	for(int j = 0; j < size; j++)
	{
		cout << " ___";
	}
	cout << endl;
	cout<<"\t";
		for(int j = 0; j < size; j++){
			cout << "|   ";
		}
		cout<<"|";
		cout <<"\t\t\t";
		for(int j = 0; j < size; j++){
			cout << "|   ";
		}
		cout<<"|";
		cout<<endl;
	for(int i = 0; i < size; i++)
	{
		cout << "\t";
		for(int j = 0; j < size; j++)
		{
			if(play_matrix[i][j])
				cout << "| " << play_matrix[i][j] << " ";
			else
				cout << "|   ";
		}
		cout << "|";
		cout << "\t\t\t";
		for(int j = 0; j < size; j++)
		{
			cout << "| " << index_matrix[i][j] << " ";
		}
		cout << "|";
		cout << endl;
		cout<<"\t";
		for(int j = 0; j < size; j++){
			cout << "|___";
		}
		cout << "|\t\t\t";
		for(int j = 0; j < size; j++)
		{
			cout << "|___";
		}
		cout << "|" << endl;
		if(i != size - 1){
			cout<<"\t";
			for(int j = 0; j < size; j++){
				cout << "|   ";
			}
			cout<<"|";
			cout <<"\t\t\t";
			for(int j = 0; j < size; j++){
				cout << "|   ";
			}
			cout<<"|";
		}
		cout<<endl;
	}
}


player::player(string s, int sc)
{
	name = s; score = sc;
}

void player::getName()
{
	cout << "Enter your name: ";
	cin >> name;
}

void player::printScore()
{
	cout << score << endl;
}


int main()
{
	game obj(1,5);
	obj.printWindow();
	return 0;
}
