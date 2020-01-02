/*  Functions.h header file to Main.cpp in GarageApp */

#pragma once // the compiler will include the header file only once when compiling the source code
using namespace std;

// in order to reach these counters in all classes (specially in garage class) I had to make them global
int bikeCounter;
int motorcycleCounter;
int carCounter;
int busCounter;
int truckCounter;
int maxParkingSpaces = 0; // this will be regulated by user
int userInput;            // used for switch cases
string userSearch;        // used to search vehicles

// all vehicles will inherit this class
class Vehicle
{
protected:
    string vehicleType;
    string registrationNo;
    string brand;
    string color;
    int noOfWheels;
    int year;

public:
    Vehicle() {} // default constructor
    Vehicle(string a, string b, string c, int x, int y) : brand(a), registrationNo(b), color(c), year(x), noOfWheels(y)
    {
        cout << "New vehicle made";
    }

    virtual void printVehicleAttribut() = 0; // pure virtual function makes this class abstract, all subclasses will call this function but with different outcome
    string printRegNo() //used in search for reg no
    {
        return registrationNo;
    };

    ~Vehicle() {} // destructor
};

class bike : public Vehicle
{
protected:
    int gears;

public:
    bike(string a, string b, string c, int x, int y, int bikeGears) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a bike" << endl;
        vehicleType = "Bike";
        gears = bikeGears;
        bikeCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand: " << this->brand << "\nColor: " << this->color << "\nGears: " << this->gears << "\nYear: " << this->year << "Wheels:" << this->noOfWheels << endl;
    }

    ~bike()
    {
        cout << "Bike destroyed" << endl;
    }
};

class motorcycle : public Vehicle
{
protected:
    string model;
    string insurranceNo;

public:
    motorcycle(string a, string b, string c, int x, int y, string motobikeInsurranceNo, string motoModel) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a motorcycle" << endl;
        vehicleType = "Motorcycle";
        insurranceNo = motobikeInsurranceNo;
        model = motoModel;
        motorcycleCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand: " << this->brand << "\nColor: " << this->color << "\nInsurrance no: " << this->insurranceNo << "\nModel:" << this->model << "\nYear: " << this->year << "Wheels:" << this->noOfWheels << endl;
    }
    ~motorcycle()
    {
        cout << "Motorcycle destroyd" << endl;
    }
};

class car : public Vehicle
{
protected:
    string model;

public:
    car(string a, string b, string c, int x, int y, string model) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a car" << endl;
        vehicleType = "Car";
        carCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand: " << this->brand << "\nColor: " << this->color << "\nModel: " << this->model << "\nYear: " << this->year << "Wheels:" << this->noOfWheels << endl;
    }
    ~car()
    {
        cout << "Car destroyed" << endl;
    }
};

class bus : public Vehicle
{
protected:
    int seats;
public:
    bus(string a, string b, string c, int x, int y, int busSeats) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a bus" << endl;
        vehicleType = "Bus";
        busSeats = seats;
        busCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand: " << this->brand << "\nColor: " << this->color << "\nSeats: " << this->seats << "\nYear: " << this->year << "Wheels:" << this->noOfWheels << endl;
    }
    ~bus()
    {
        cout << "bus destroyed" << endl;
    }
};

class truck : public Vehicle
{
protected:
    string weight;

public:
    truck(string a, string b, string c, int x, int y, string truckWeight) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a truck" << endl;
        vehicleType = "Truck";
        weight = truckWeight;
        truckCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand: " << this->brand << "\nColor: " << this->color << "\nWeight: " << this->weight << "\nYear: " << this->year << "Wheels:" << this->noOfWheels << endl;
    }
    ~truck()
    {
        cout << "truck destroyed" << endl;
    }
};

// this is the building "Garage" where we store all vehicles, later on we can add other variables that effect the building, e.g air pollution - this will not happen
class Garage
{
protected:
    int counter; // for adding and removing vehicles
public:
    Garage()
    {
        cout << "New garage made" << endl;
    }

    vector<Vehicle *> GarageVehicles; // we will store all vehicles here, there will be a fixed no of spaces available

    void vehicleIndex() // prints how many vehicles there are - works!
    {
        cout << "There are " << this->GarageVehicles.size() << " vehicles in the garage right now." << endl;
    }

    void listOfVehicles()
    {
        cout << "These vehicles are in the garage right now" << endl;
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            cout << GarageVehicles[i]->printVehicleAttribut << endl;
        }
            cout << "Number of bikes: " << bikeCounter << endl;
            cout << "Number of motorcycles: " << motorcycleCounter << endl;
            cout << "Number of cars: " << carCounter << endl;
            cout << "Number of buses: " << busCounter << endl;
            cout << "Number of trucks: " << truckCounter << endl;
    }

    void addVehicle(Vehicle *x) // add vehicle to list of vehicles - works
    {
        if (GarageVehicles.size() < maxParkingSpaces)
        {
            GarageVehicles.push_back(x);
            cout << counter++ << endl;
        }
        else
        {
            cout << "There are no parking spaces left" << endl;
        }
    }

    Vehicle* searchReg(string searchReg)
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            if (GarageVehicles[i]->printRegNo == searchReg)
            {
                cout << "Your vehicle is found." << endl;
                return GarageVehicles[i]->printVehicleAttribut;
            }
            else
            {
                cout << "Your vehicle is not found" << endl;
            }
        }
    }

    Vehicle *removeVehicle(string searchReg) //remove vehicle from list of vehicles
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            if (GarageVehicles[i]->printRegNo() == searchReg)
            {
                cout << GarageVehicles[i] << " will now be deleted." << endl;
                delete GarageVehicles[i];
                GarageVehicles.erase(remove(GarageVehicles.begin(), GarageVehicles.end(), GarageVehicles[i]), GarageVehicles.end());
                cout << counter-- << endl;
                break;
            }
        }
    }

    ~Garage() // destructor
    {
        cout << "Garage destroyed" << endl;
    }
};

void menu()
{
    cout << endl;
    cout << "Welcome to the garage!\nWhat would you like to do?" << endl;
    cout << "______________________"<< endl;
    cout << "See garage\tEnter 1" << endl;    // should call list of vehicles function
    cout << "Add vehicle\tEnter 2" << endl;
    cout << "Remove vehicle\tEnter 3" << endl;
    cout << "Search vehicle\tEnter 4" << endl;
    cout << "Destroy garage\tEnter 5" << endl;
    cout << "______________________"<< endl;
    cout << "Exit?\tEnter 0\n" << endl;
    cout << endl;
}

void addVehicleMenu(){
    cout << endl;
    cout <<"What vehicle would you like to add?"<< endl;
    cout <<"Cool bike\tEnter 1"<< endl;
    cout <<"Even cooler motorcycle\tEnter 2"<< endl;
    cout <<"Fast car\tEnter 3"<< endl;
    cout <<"Mega bus\tEnter 4"<< endl;
    cout <<"Slow truck\tEnter 5"<< endl;
    cout << endl;
}