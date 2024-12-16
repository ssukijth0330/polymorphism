// Discount price for Membership of two difference levels 
// Premium level: discount price is -10%
//   Basic level: discount price is -5%
//  
// Normal price for non membership
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
protected:
	string id;
	string name;
	
public: 
	Customer (string in_name, string in_id) : name(in_name), id(in_id) {}
	virtual void displayInfo() = 0;
	virtual double calculateDiscount(double amount) = 0;
};

class PremiumCustomer : public Customer {
private:
	int membershipYears;
	const float discount = 0.90;

public:
	PremiumCustomer(string in_name, string in_id, int in_year) : Customer(in_name, in_id), membershipYears(in_year) {}
	void displayInfo() override {
		cout << "Premium Customer: " << name << " ( ID: " << id << ", Membership year: " << membershipYears << " )" << endl;
	}
	double calculateDiscount(double in_amount) override {
		return in_amount * discount;
	}
};

class BasicCustomer : public Customer {
private:
	int membershipYears;
	const float discount = 0.95;
public:
	BasicCustomer(string in_name, string in_id, int in_year) : Customer(in_name, in_id), membershipYears(in_year) {}
	void displayInfo() override {
			cout << "Basic Customer: " << name << "( ID: " << id << ", Membership year: " << membershipYears << " ) " << endl;
	}
	double calculateDiscount(double in_amount) override {
		return in_amount * discount;
	}
};	

int main () {
	//Create vector to save customers information
	//and point customers to that vector
	vector<Customer*> customers;
	customers.push_back(new PremiumCustomer("Alex Norman", "p00001", 2001));
	customers.push_back(new BasicCustomer("John Adam", "b00001", 2005));
	customers.push_back(new PremiumCustomer("Peter Lake", "p00002", 2000));
	customers.push_back(new BasicCustomer("Lisa Matin", "b00002", 2010));

	double baseAmount = 180.65;

	for (const auto& customer : customers) {
		customer->displayInfo();
		cout << "The Bill amount : " << baseAmount << ", Cutomer paid: ";
		printf("%.2f\n", customer->calculateDiscount(baseAmount));
		cout << endl;
	}
	return 0;
}

