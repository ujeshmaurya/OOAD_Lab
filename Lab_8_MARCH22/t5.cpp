#include <bits/stdc++.h>

using namespace std;

class RestaurantMeal 
{
	protected:
		string name;
		double price;
	public:
		RestaurantMeal(string name, double price) 
		{
			this->name=name;
			this->price=price;
		}
		void display() 
		{
			cout<<"Restaurant Meal"<<endl;
			cout<<"Meal Name: "<<name<<endl;
			cout<<"Price: "<<price<<endl<<endl;
		}
};

class HotelService 
{
	protected:
		string service_name;
		double service_fee;
		int room_no;
	public:
		HotelService(string service_name, double service_fee, int room_no) 
		{
			this->service_name=service_name;
			this->service_fee=service_fee;
			this->room_no=room_no;
		}
		void display() 
		{
			cout<<"Hotel Service"<<endl;
			cout<<"Name of Service: "<<service_name<<endl;
			cout<<"Service Fee: "<<service_fee<<endl;
			cout<<"Room Number: "<<room_no<<endl<<endl;
		}
};

class RoomServiceMeal: public RestaurantMeal, public HotelService 
{
	public:
		RoomServiceMeal(string name,double price,int room_no,string service_name="Room Service",double service_fee=4.00):HotelService(service_name, service_fee,room_no),RestaurantMeal(name,price) 
		{
			cout<<endl<<"Restaurant Service Meal Constructor"<<endl<<endl;
		}
		void display() 
		{
			RestaurantMeal::display();
			HotelService::display();
			cout<<"Sum of Meal and Service Fees: $ "<<(price+service_fee)<<endl<<endl;
		}
};

int main() 
{
	RoomServiceMeal obj("Steak Dinner", 20.00, 1202);
	obj.display();
	return 0;
}
