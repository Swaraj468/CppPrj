#include<iostream>
#include<vector>
#include<algorithm>	
#include "Header.h"
#include <memory>

class Vehicle
{
public:
	Vehicle(const std::string& vehicleName, const int vehicleCapacity)
		: _name{vehicleName}, _capacity{vehicleCapacity}
	{

	}
	 virtual void Run() const //virtual means the child can override it
	{
		std::cout << _name << " with " << _capacity << " people running" << std::endl;
	} 

	 int GetCapacity() const { return _capacity; }
	 void SetCapacity(int newCapacity) {
		 if (newCapacity < 0) {
			 return;
		 }
		 _capacity = newCapacity;
	 }
protected: // weak protection, the child class can access it, still not available out side of the family, use with caution.
	const std::string _name; //and _ infromnt of a member indicates private. in python _ is the way to tell a member is private.

private:
	
	 int _capacity;

};

class Car : public Vehicle //car is inheriting from vehicle
{
public:
	Car(const std::string& carName, const int carCapacity, float carMileage)
		: Vehicle{ carName, carCapacity }, _mileage{ carMileage }
	{

	}
	virtual void Run() const override //override means we are not creating a new function. we are redefining the vehicle part of the run for the car
	{
		std::cout << _name << " with " << _mileage << " mileage " << GetCapacity() << " people running" << std::endl;
	}
	 float GetMileage() const { //accesser.
		return _mileage;
	}
private:
	float _mileage;
};

int main() {
	Vehicle vehicle{ "LightYear2000", 1000 };
	//vehicle.Run();

	Car car{ "Toyota Rv4", 5 , 20.5};
	Vehicle& carAsVehicle = car;


	car.Run();
	carAsVehicle.Run();
	//std::cout << car.GetMileage() << std::endl;
}

