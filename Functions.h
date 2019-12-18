/*  Functions.h header file to Main.cpp in GarageApp */

#pragma once //the compiler will include the header file only once when compiling the source code
using namespace std;

//This is the building "Garage" where we store all vehicles, later on we can add other variables that effect the building, e.g air pollution
class Garage{
protected:
    int x; //x no of vehicles
    int counter; //for adding and removing vehicles
    int maxParkingSpaces; //setting maximum no of parking spaces
public:
    
    virtual void printProperties() = 0; //function to print properties to be used in all subclasses

    vector<Garage *> GarageVehicles; //we will store all vehicles here, there will be a fixed no of spaces available
    
    void vehicleIndex(){ 
        cout << "There are " << GarageVehicles.size() << " vehicles in the garage." << endl;
    }

    void listOfVehicles(){
        cout << "These are the vehicles in the garage right now:" << endl;
        for (int i = 0; i < GarageVehicles.size(); i++){
            cout << GarageVehicles[i] << endl;
            }
    }

    void addVehicle(Garage* x){  //add vehicle to list of vehicles
        GarageVehicles.push_back(x);
        counter++;
    }

    void removeVehicle(Garage* x){ //remove vehicle from list of vehicles
        
        counter--;
    }

    Garage(){
        cout << "Garage constructor" << endl;
    } //constructor
    
    ~Garage(){
        cout << "Garage destructor" << endl;
    } //destrctor
}; 

//All vehicles will inherit this class
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
    //constructor
    Vehicle(string x, string y, int z) : registrationNo(x), color(y), noOfWheels(z) {
        cout << "Vehicle constructor" << endl;
    } 
    
    //destructor
    ~Vehicle(){
        cout << "Vehicle destructor" << endl;
    } 

    virtual void printProperties(){}   
};

//Function that points to vehicle class that makes a new vehicle
/* Vehicle* makeNewVehicle(){
    Vehicle* newVehicle = new Vehicle;
        return newVehicle;
    //new vehicle with no properties
    //return (new newVehicle); (same as above, only compressed)
}*/
