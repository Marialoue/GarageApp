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
        cout << "\nNew vehicle made";
    }

    virtual void printVehicleAttribut() = 0; // pure virtual function makes this class abstract, all subclasses will call this function but with different outcome
    string getRegNo() //used in search for reg no
    {
        return registrationNo;
    };
    string getColor()
    {
        return color;
    };

    virtual ~Vehicle() {} // destructor
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
        cout << "... " << this->vehicleType << " ...\nBrand:\t" << this->brand << "\nReg no:\t" << this->registrationNo << "\nColor:\t" << this->color << "\nYear:\t" << this->year << "\nWheels:\t" << this->noOfWheels << "\nGears:\t" << this->gears << "\n" << endl;
    }

    ~bike()
    {
        cout << "Bike destroyed" << endl;
        bikeCounter--;
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
        cout << "... " << this->vehicleType << " ...\nBrand:\t" << this->brand << "\nReg no:\t" << this->registrationNo << "\nColor:\t" << this->color << "\nYear: " << this->year << "\nWheels:\t" << this->noOfWheels << "\nInsurrance no:\t" << this->insurranceNo << "\nModel:\t" << this->model << "\n" << endl;
    }
    ~motorcycle()
    {
        cout << "Motorcycle destroyd" << endl;
        motorcycleCounter--;
    }
};

class car : public Vehicle
{
protected:
    string model;

public:
    car(string a, string b, string c, int x, int y, string carModel) : Vehicle(a, b, c, x, y)
    {
        cout << " and it's a car" << endl;
        vehicleType = "Car";
        model = carModel;
        carCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand:\t" << this->brand << "\nReg no:\t" << this->registrationNo << "\nColor:\t" << this->color << "\nYear:\t" << this->year << "\nWheels:\t" << this->noOfWheels << "\nModel:\t" << this->model << "\n" << endl;
    }
    ~car()
    {
        cout << "Car destroyed" << endl;
        carCounter--;
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
        seats = busSeats;
        busCounter++;
    }
    void printVehicleAttribut()
    {
        cout << "... " << this->vehicleType << " ...\nBrand:\t" << this->brand << "\nReg no:\t" << this->registrationNo << "\nColor:\t" << this->color << "\nYear:\t" << this->year << "\nWheels:\t" << this->noOfWheels << "\nSeats:\t" << this->seats << "\n" << endl;
    }
    ~bus()
    {
        cout << "Bus destroyed" << endl;
        busCounter--;
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
        cout << "... " << this->vehicleType << " ...\nBrand:\t" << this->brand << "\nReg no:\t" << this->registrationNo << "\nColor:\t" << this->color << "\nYear:\t" << this->year << "\nWheels:\t" << this->noOfWheels << "\nWeight:\t" << this->weight << "\n" << endl;
    }
    ~truck()
    {
        cout << "Truck destroyed" << endl;
        truckCounter--;
    }
};

// "blueprint" for the building Garage where we store all vehicles - here one could add other variables related to the building e.g air pollution. 
class Garage
{
protected:
    int counter; // for adding and removing vehicles
public:
    Garage()
    {
        cout << "Your new garage is created." << endl;
    }

    vector<Vehicle *> GarageVehicles; // we will store all vehicles here, there will be a fixed number of spaces available

    void vehicleIndex() // prints how many vehicles there are and max capacity for garage
    {
        cout << "There are " << this->GarageVehicles.size() << " vehicles in the garage, capacity is " << maxParkingSpaces << " parking spaces\n" << endl;
    }

    void listOfVehicles() 
    {
        cout << "These vehicles are in the garage right now:" << endl;
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            GarageVehicles[i]->printVehicleAttribut();
        }
            cout << "Number of bikes:\t" << bikeCounter << endl;
            cout << "Number of motorcycles:\t" << motorcycleCounter << endl;
            cout << "Number of cars:\t\t" << carCounter << endl;
            cout << "Number of buses:\t" << busCounter << endl;
            cout << "Number of trucks:\t" << truckCounter << endl;
    }

    void addVehicle(Vehicle *x) // add vehicle to list of vehicles
    {
        GarageVehicles.push_back(x);
        counter++;
    }

    Vehicle* searchReg(string searchReg)
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            if (GarageVehicles[i]->getRegNo() == searchReg)
            {
                cout << "Your vehicle is found: " << endl;
                GarageVehicles[i]->printVehicleAttribut();
                break;
            }
            else
            {
                cout << "Your vehicle is not found." << endl;
            }
        }
        return 0;
    }

    Vehicle* searchColor(string searchColor)
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            if (GarageVehicles[i]->getColor() == searchColor)
            {
                cout << "Your vehicle is found: " << endl;
                GarageVehicles[i]->printVehicleAttribut();
                break;
            }
            else
            {
                cout << "Your vehicle is not found." << endl;
            }
        }
        return 0;
    }

    Vehicle *removeVehicle(string searchReg) // remove specific vehicle from list of vehicles
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            if (GarageVehicles[i]->getRegNo() == searchReg)
            {
                GarageVehicles[i]->printVehicleAttribut();
                cout << "It will now be deleted." << endl;
                delete GarageVehicles[i];
                GarageVehicles.erase(remove(GarageVehicles.begin(), GarageVehicles.end(), GarageVehicles[i]), GarageVehicles.end());
                counter--; // decreasing vehicles in counter
                break;
            }
        }
        return 0;
    }

    Vehicle *destroyVehicles() // using for loop to delete all elements in list of vehicles and setting counters to 0
    {
        for (int i = 0; i < GarageVehicles.size(); i++)
        {
            delete GarageVehicles[i];
        }

        bikeCounter = 0;
		motorcycleCounter = 0;
		carCounter = 0;
		busCounter = 0;
		truckCounter = 0;
        return 0;
    }

    ~Garage() // destructor
    {
        cout << "Point of no return - Garage is destroyed" << endl;
    }
};

void mainMenu()
{
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "__________________________"<< endl;
    cout << "See garage \t Enter 1" << endl;
    cout << "Add vehicle \t Enter 2" << endl;
    cout << "Remove vehicle \t Enter 3" << endl;
    cout << "Find vehicle \t Enter 4" << endl;
    cout << "Destroy garage \t Enter 5" << endl;
    cout << "__________________________"<< endl;
    cout << "Exit? \t\t Enter 0\n" << endl;
    cout << endl;
}

void addVehicleMenu()
{
    cout << endl;
    cout << "What vehicle would you like to add?" << endl;
    cout << "Cool bike\tEnter 1" << endl;
    cout << "New motorcycle\tEnter 2" << endl;
    cout << "Fast car\tEnter 3" << endl;
    cout << "Mega bus\tEnter 4" << endl;
    cout << "Regular truck\tEnter 5" << endl;
    cout << endl;
}

void searchFunctionMenu()
{
    cout << endl;
    cout << "How would you like to search?" << endl;
    cout << "By registration number\tEnter 1" << endl;
    cout << "By color\t\tEnter 2" << endl;
    cout << endl;
}