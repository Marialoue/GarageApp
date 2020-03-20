/*  Main.cpp is the executable file for GarageApp program   */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Functions.h"

using namespace std;

int main()
{
	cout << "\nWelcome to the garage!\n"
		 << endl;
	Garage *myGarage = new Garage; // pointer to new object myGarage (because garage class is abstract), which will be the default garage

	cout << "How many parking spaces would you like to have?" << endl;
	cin >> maxParkingSpaces;

	do
	{
		mainMenu();
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
			myGarage->vehicleIndex();
			myGarage->listOfVehicles();
			break;

		case 2:														// add vehicle
			if (myGarage->GarageVehicles.size() < maxParkingSpaces) // this function could be moved to Functions.h header, with the below if statements
			{
				addVehicleMenu();
				cin >> userInput;

				if (userInput == 1) // add bike
				{
					cout << "Enter brand: ";
					cin >> inBrand;
					cout << "what is your registrations nr? ";
					cin >> regNo;
					cout << "What color is it? ";
					cin >> inColor;
					cout << "From what year? ";
					cin >> inYear;
					cout << "How many wheels are there? ";
					cin >> inWheels;
					cout << "How many gears? ";
					cin >> inGears;

					bike *bike1 = new bike(inBrand, regNo, inColor, inYear, inWheels, inGears);
					myGarage->addVehicle(bike1);
				}

				if (userInput == 2) // add motorcycle
				{
					cout << "Enter brand: ";
					cin >> inBrand;
					cout << "what is your registrations nr? ";
					cin >> regNo;
					cout << "What color is it? ";
					cin >> inColor;
					cout << "From what year? ";
					cin >> inYear;
					cout << "How many wheels are there? ";
					cin >> inWheels;
					cout << "Enter insurrance no: ";
					cin >> inInsurrance;
					cout << "Which model is it? ";
					cin >> inModel;
					motorcycle *motorcycle1 = new motorcycle(inBrand, regNo, inColor, inYear, inWheels, inInsurrance, inModel);
					myGarage->addVehicle(motorcycle1);
				}

				if (userInput == 3) // add car
				{
					cout << "Enter brand: ";
					cin >> inBrand;
					cout << "what is your registrations nr? ";
					cin >> regNo;
					cout << "What color is it? ";
					cin >> inColor;
					cout << "From what year? ";
					cin >> inYear;
					cout << "How many wheels are there? ";
					cin >> inWheels;
					cout << "What model? ";
					cin >> inModel;
					car *car1 = new car(inBrand, regNo, inColor, inYear, inWheels, inModel);
					myGarage->addVehicle(car1);
				}

				if (userInput == 4) // add bus
				{
					cout << "Enter brand: ";
					cin >> inBrand;
					cout << "what is your registrations nr? ";
					cin >> regNo;
					cout << "What color is it? ";
					cin >> inColor;
					cout << "From what year? ";
					cin >> inYear;
					cout << "How many wheels are there? ";
					cin >> inWheels;
					cout << "How mega is your bus (in seats)? ";
					cin >> inSeats;
					bus *bus1 = new bus(inBrand, regNo, inColor, inYear, inWheels, inSeats);
					myGarage->addVehicle(bus1);
				}

				if (userInput == 5) // add truck
				{
					cout << "Enter brand: ";
					cin >> inBrand;
					cout << "what is your registrations nr? ";
					cin >> regNo;
					cout << "What color is it? ";
					cin >> inColor;
					cout << "From what year? ";
					cin >> inYear;
					cout << "How many wheels are there? ";
					cin >> inWheels;
					cout << "What it the weight of your truck [light/heavy]? ";
					cin >> inWeight;
					truck *truck1 = new truck(inBrand, regNo, inColor, inYear, inWheels, inWeight);
					myGarage->addVehicle(truck1);
				}
			}
			else
			{
				cout << "There are no parking spaces left." << endl;
			}

			break;

		case 3: // remove vehicle
			cout << "You need registration number to remove vehicle, enter now:" << endl;
			cin >> userSearch;
			myGarage->removeVehicle(userSearch);
			break;

		case 4: // search vehicle by regNo or color
			searchFunctionMenu();
			cin >> userInput;
			if (userInput == 1)
			{
				cout << "Enter your registration number:" << endl;
				cin >> userSearch;
				myGarage->searchReg(userSearch);
				break;
			}
			if (userInput == 2)
			{
				cout << "Enter your color:" << endl;
				cin >> userSearch;
				myGarage->searchColor(userSearch);
				break;
			}
			else
			{
				cout << "Invalid input" << endl;
			}
			break;

		case 5: // destroy garage
			myGarage->destroyVehicles();
			delete myGarage;

		default:
			break;
		}
	} while (userInput != 0);
	cout << "Until next time" << endl;
}