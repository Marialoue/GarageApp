/*  Main.cpp is the executable file for GarageApp program   */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Functions.h"

using namespace std;

int main()
{								   // default garage
	Garage *myGarage = new Garage; // pointer (because garage class is abstract) to myGarage
	
	do
	{
		cout << "Before we start, how many parking spaces would you like to have in your garage?" << endl;
		cin >> maxParkingSpaces;
		menu();
		cin >> userInput;

		// general variables for all vehicles
		string inBrand;
		string regNo;
		string inColor;
		int inYear;
		int inWheels;
		// specific variables for different vehicles
		int inGears;
		string inInsurrance;
		string inModel;
		int inSeats;
		string inWeight;

		switch (userInput)
		{
		case 1: // see garage
			myGarage->listOfVehicles();
			break;

		case 2: // add vehicle
			addVehicleMenu();
			cin >> userInput;
			
			if (userInput == 1) // adding a bike
			{
				cout << "Enter brand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What color is it?" << endl;
				cin >> inColor;
				cout << "From what year?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> inWheels;
				cout << "How many gears?" << endl;
				cin >> inGears;

				bike *bike = new bike(inBrand, regNo, inColor, inYear, inWheels, inGears);
				myGarage->addVehicle(bike);
			}

			if (userInput == 2) // adding a motorcycle
			{
				cout << "Enter brand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What color is it?" << endl;
				cin >> inColor;
				cout << "From what year?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> inWheels;
				cout << "Do you have an insurrance no?" << endl;
				cin >> inInsurrance;
				cout << "Which model is it?" << endl;
				cin >> inModel;
				motorcycle *motorcycle = new motorcycle(inBrand, regNo, inColor, inYear, inWheels, inInsurrance, inModel);
				myGarage->addVehicle(motorcycle);
			}

			if (userInput == 3) // add car
			{
				cout << "Enter brand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What color is it?" << endl;
				cin >> inColor;
				cout << "From what year?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> inWheels;
				cout << "What model?" << endl;
				cin >> inModel;
				car *car = new car(inBrand, regNo, inColor, inYear, inWheels, inModel);
				myGarage->addVehicle(car); 
			}

			if (userInput == 4) // add bus
			{
				cout << "Enter brand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What color is it?" << endl;
				cin >> inColor;
				cout << "From what year?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> inWheels;
				cout << "How mega is your bus (in seats)?" << endl;
				cin >> inSeats;
				bus *bus = new bus(inBrand, regNo, inColor, inYear, inWheels, inSeats);
				myGarage->addVehicle(bus);
			}
			if (userInput == 5) // add truck
			{
				cout << "Enter brand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What color is it?" << endl;
				cin >> inColor;
				cout << "From what year?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> inWheels;
				cout << "How mega is your truck [light/heavy]" << endl;
				cin >> inWeight;

				truck *truck = new truck(inBrand, regNo, inColor, inYear, inWheels, inWeight);
				myGarage->addVehicle(truck);
			}
			break;

		case 4: // remove vehicle - done without testing
			cout << "You need registration number to remove vehicle, enter now:" << endl;
			cin >> userSearch;
			myGarage->removeVehicle(userSearch);
			break;

		case 5: // search vehicle - done without testing
			cout << "Enter registration number to search:" << endl;
			cin >> userSearch;
			myGarage->searchReg(userSearch);
			break;

		case 6: // destroy garage
		// myGarage->garageVehicles.clear();
		// delete myGarage;

		default:
			break;
		}
	} while (userInput != 0);
	cout << "Until next time" << endl;
}