#include<bits/stdc++.h>
using namespace std;
class InsurancePolicy
{
	private:
		int policyNumber;
		
	protected:
		string policyHolder;
		
	public:
		float rate;
		void setPolicy(int policyNumber,string policyHolder,float rate)
		{
			this->policyNumber=policyNumber;
			this->policyHolder=policyHolder;
			this->rate=rate;
		}
		void showPolicy()
		{
			cout<<"Policy number : "<<policyNumber<<"\nPolicy Holder : "<<policyHolder<<"\nAnnual Rate : "<<rate<<"\n";
		}
};
class AutomobileInsurancePolicy : protected InsurancePolicy
{
	private:
		string date;
	public:
		using InsurancePolicy::setPolicy;
		using InsurancePolicy::showPolicy;
		void setDate(string date)
		{
			this->date=date;
		}
		void showDate()
		{
			cout<<"Date : "<<date<<"\n";
		}
};

int main()
{
	AutomobileInsurancePolicy p1;
	p1.setPolicy(1,"Ujesh",4.5);
	p1.setDate("15/03/2018");
	p1.showPolicy();
	p1.showDate();
}
