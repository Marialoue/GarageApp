/*  Functions.h */

#pragma once

struct vehicleProperties{
    int wheels; 
    string color;
    string regNo;
};

//This is a representation of the building "Garage" where we store all vehicles, later on we can add other variables that effect the building, e.g air pollution
class Garage{ 
protected:
public:
    vector<vehicleProperties> Vehicles;
};

//All vehicles will inherit this class
class Vehicle{ 
protected:
public:
    Vehicle(){ //default constructor
    }

    ~Vehicle(){ //destructor to be used when we delete our objects
    }
};

//Function that points to vehicle class that makes a new vehicle
Vehicle* makeNewVehicle(){
    Vehicle *newVehicle = new Vehicle;
    return newVehicle;
    //return (new Vehicle); (same as above, only compressed)
}