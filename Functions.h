/*  Functions.h header file to Main.cpp in GarageApp */

#pragma once // the compiler will include the header file only once when compiling the source code
using namespace std;

// all vehicles will inherit this class
class Vehicle : public Garage{ 
protected:
    int noOfWheels;
    int year;
    string color;
    string registrationNo;
    string brand;
    string model;
    string insurranceNo; 

public:
    Vehicle(){} // default constructor
    
    Vehicle(string x, string y, int z) : registrationNo(x), color(y), noOfWheels(z) { // constructor
        cout << "Vehicle constructor" << endl;
    } 
    
    virtual void printProperties() = 0;

    ~Vehicle(){ // destructor
        cout << "Vehicle destructor" << endl;
    }  
};

class car : public Vehicle{
    protected:
    public:

    car(string x, string y, int z) : Vehicle(x, y, z) {
        cout << "Car constructor" << endl;
        cout << "new car made" << endl;
    }

    void printProperties(){
        cout << "Registration number:" << this->registrationNo << " Color: " << this->color << " Number of wheels:" << this->noOfWheels << endl;
    }
    
    ~car(){
        cout << "Car destructor" << endl;
    }
};

class motorcycle : public Vehicle{
    protected:
    public:
    motorcycle(string x, string y, int z) : Vehicle(x,y,z) {
    cout << "Motorcycle constructor" << endl;
    }

    void printProperties(){
        cout << "Registration number:" << this->registrationNo << " Color: " << this->color << " Number of wheels:" << this->noOfWheels << endl;
    }

    ~motorcycle(){
    cout << "Motorcycle destructor" << endl;
    }
};

// this is the building "Garage" where we store all vehicles, later on we can add other variables that effect the building, e.g air pollution
class Garage{
protected:
    int x; // x no of vehicles
    int counter; // for adding and removing vehicles
    int maxParkingSpaces; // setting maximum no of parking spaces
public:
        Garage(){ // constructor
        cout << "Garage constructor" << endl;
    }

    vector<Vehicle *> GarageVehicles; // we will store all vehicles here, there will be a fixed no of spaces available
    
    void vehicleIndex(){ 
        cout << "There are " << GarageVehicles.size() << " vehicles in the garage." << endl;
    }

    void listOfVehicles( vector<Vehicle*> GarageVehicles ){
        cout << "These are the vehicles in the garage right now:" << endl;
        for (int i = 0; i < GarageVehicles.size(); i++){
            cout << GarageVehicles[i] << endl;
            }
    }

    void addVehicle( Vehicle* x ){  //add vehicle to list of vehicles
        GarageVehicles.push_back(x);
        cout << counter++ << endl;
    }

    void removeVehicle( Vehicle* x ){ //remove vehicle from list of vehicles
        for(vector<Vehicle* > ::iterator it = GarageVehicles.begin(); it != GarageVehicles.end(); it++)
            // cout << * it << endl // loops through and prints all indexes in the vector
            GarageVehicles.erase(it); //deletes the last index in vector ?
        cout << counter-- << endl;
    }

    ~Garage(){ // destructor
        cout << "Garage destructor" << endl;
    } 
}; 