#include <bits/stdc++.h>

using namespace std;

class Vehicle 
{
	protected:
		int id;
		string make;
		double mpg;
	public:
		void set_value(int id, string make, double mpg) 
		{
			this->id = id;
			this->make = make;
			this->mpg = mpg;
		}
		void display() 
		{
			cout<<"Vehicle Description"<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"Make: "<<make<<endl;
			cout<<"Miles Per Gallon: "<<mpg<<endl;
		}
};

class Dwelling 
{
	protected:
		int no_rooms;
		double sq_feet;
	public:
		void set_value(int no_rooms, double sq_feet) 
		{
			this->no_rooms=no_rooms;
			this->sq_feet=sq_feet;
		}
		void display() 
		{
			cout<<"Dwelling Description"<<endl;
			cout<<"Number of Rooms: "<<no_rooms<<endl;
			cout<<"Square Feet: "<<sq_feet<<endl;
		}
};

class RV: public Vehicle, public Dwelling 
{
	public:
		RV(int id, string make, double mpg, int no_rooms, double sq_feet) 
		{
			Vehicle::set_value(id, make, mpg);
			Dwelling::set_value(no_rooms, sq_feet);
		}
		void display() 
		{
			Vehicle::display();
			Dwelling::display();
		}
};

int main() 
{
	RV rv(1, "Mahindra", 13.8, 4, 8000.0);
	rv.Vehicle::display();
	rv.Dwelling::display();
	cout<<endl;
	rv.display();
	return 0;
}
