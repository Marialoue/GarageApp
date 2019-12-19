/*  Main.cpp is the executable file for GarageApp program   */

#include <iostream>
#include <string> 
#include <vector>
#include "Functions.h"

using namespace std;

int main(){ 
	Garage* myGarage = new Garage; // pointer (because garage class is abstract) to myGarage

	// creating cars from car class
	car* car1 = new car("ERT 345", "Red", 4);
	car* car2 = new car("SFD 243", "Black", 4);

	// creating motorcycles from motorcycle class
	motorcycle* motorcycle1 = new motorcycle("ERT 345", "Red", 4);
	motorcycle* motorcycle2 = new motorcycle("SFD 243", "Black", 4);

	myGarage->addVehicle(car1);
	myGarage->addVehicle(car2);
	myGarage->addVehicle(motorcycle1);
	myGarage->addVehicle(motorcycle2);
		cout << endl;
	myGarage->vehicleIndex();
		cout << endl;
	myGarage->listOfVehicles(myGarage->GarageVehicles);


	delete car1;
	delete car2;
	delete motorcycle1;
	delete motorcycle2;
}