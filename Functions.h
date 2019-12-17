/*  Functions.h */

#pragma once

//This is a representation of the building "Garage" where we store all vehicles, later on we can add other variables that effect the building, e.g air pollution
class Garage{ 
protected:
    int wheels; 
    int year;
    std::string color;
    std::string registrationNo; //not needed for bicycles
    std::string brand;
    std::string model; 

public:
    std::vector<Garage> Vehicles; //vector with type garage class and name Vehicle
    virtual std::string output(std::string color){
        return color;
    }
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