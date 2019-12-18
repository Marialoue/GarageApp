/*  Main.cpp is the executable file for GarageApp program   */

#include <iostream>
#include <string> 
#include <vector>
#include "Functions.h"

using namespace std;

int main(){ 
	Garage* myGarage; //pointer (because garage class is abstract) to myGarage
	//creating cars with function makeNewVehicle
	//Vehicle* car = makeNewVehicle("4", "GFD543", "Blue"); //makes new object called "car" of Vehicle class
	// Vehicle* car2 = makeNewVehicle();
	
	//creating car3 locally
	Vehicle* car2 = new Vehicle("ERT 345", "Red", 4);
	Vehicle* car3 = new Vehicle("SFD 243", "Black", 4);
	// Vehicle* car4 = makeNewVehicle();


	delete car2;
	delete car3;
	// vector<Garage *> localVehicle; //vector with type Garage (class) and name localVehicle
	// localVehicle.push_back(car2);//adding object car2 in vector localVehicle
	// cout << localVehicle.size() << endl;
	// cout << localVehicle[0] << endl;

	//cout << localVehicle[0]->printProperties() << endl;
}