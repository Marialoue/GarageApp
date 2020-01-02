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
		cout << endl;
		menu();
		cin >> userInput;
		cout << endl;

			string inBrand;
			string regNo;
			string inColor;
			int inYear;
			int wheels;
			int gears;
			string electric;
			string insurrance;
			string model;
			string cabriolet;
			int seats;
			string weight;
		switch (userInput)
		{
		case 1: // create garage - this must be done before everything else
			break;

		case 2: // see garage
			myGarage->listOfVehicles();
			break;

		case 3: // add vehicle
			addVehicleMenu();
			cin >> userInput;
			
			if (userInput == 1) // adding a bike
			{


				cout << "Enter inBrand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What inColor is it?" << endl;
				cin >> inColor;
				cout << "From what inYear?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> wheels;
				cout << "How many gears?" << endl;
				cin >> gears;
				cout << "Is it electric? [yes/no]" << endl;
				cin >> electric;

				bike *bike = new bike(inBrand, regNo, inColor, inYear, wheels, gears, electric);
				myGarage->addVehicle(bike);
			}

			if (userInput == 2) // adding a motorcycle
			{
				cout << "Enter inBrand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What inColor is it?" << endl;
				cin >> inColor;
				cout << "From what inYear?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> wheels;
				cout << "Do you have an insurrance no?" << endl;
				cin >> insurrance;
				cout << "Which model is it?" << endl;
				cin >> model;
				motorcycle *motorcycle = new motorcycle(inBrand, regNo, inColor, inYear, wheels, insurrance, model);
				myGarage->addVehicle(motorcycle);
			}

			if (userInput == 3) // add car
			{
				cout << "Enter inBrand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What inColor is it?" << endl;
				cin >> inColor;
				cout << "From what inYear?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> wheels;
				cout << "Is it an cabriolet? [yes/no]" << endl;
				cin >> cabriolet;
				Vehicle *car = new car(inBrand, regNo, inColor, inYear, wheels, cabriolet);
				myGarage->addVehicle(car); 
			}
			
			if (userInput == 4) // add bus
			{
				cout << "Enter inBrand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What inColor is it?" << endl;
				cin >> inColor;
				cout << "From what inYear?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> wheels;
				cout << "How mega is your bus (in seats)?" << endl;
				cin >> seats;

				bus *bus = new bus(inBrand, regNo, inColor, inYear, wheels, seats);
				myGarage->addVehicle(bus);
			}
			if (userInput == 5) // add truck
			{
				cout << "Enter inBrand: " << endl;
				cin >> inBrand;
				cout << "what is your registrations nr?" << endl;
				cin >> regNo;
				cout << "What inColor is it?" << endl;
				cin >> inColor;
				cout << "From what inYear?" << endl;
				cin >> inYear;
				cout << "How many wheels are there?" << endl;
				cin >> wheels;
				cout << "How mega is your truck [light/heavy]" << endl;
				cin >> weight;

				truck *truck = new truck(inBrand, regNo, inColor, inYear, wheels, weight);
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
			delete myGarage;
		default:
			break;
		}
	} while (userInput != 0);
}