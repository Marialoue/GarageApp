/*  Garage applikation   */

#include <iostream>
#include <string> 
#include <vector>
#include "Functions.h"

using namespace std;

int main(){
	makeNewVehicle(); //makes new objet of Vehicle class
	Garage* garage = new Garage;
    cout << garage->output("Black") << endl;
}