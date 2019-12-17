/*  Functions.h */

#pragma once
#include <vector>
#include <string>

struct vehicleProperties{
    int wheels;
    string color;
    string regNo;
}

//This is a representation of the building "Garage" where we store all vehicles, later on maybe we can add air pollution or other variables concerning the building
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

//array Vehicle class garage

//Function that points to vehicle class that makes a new car
Vehicle* makeNewVehicle(){
    Vehicle *newCar = new Vehicle;
    return newCar;
    //return (new Vehicle);
}