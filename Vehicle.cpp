#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

void Vehicle::setManufactureName(string input)
{

}

string Vehicle::getManufactureName() const { return manufactureName; }

void Vehicle::setModelName(string input)
{

}

string Vehicle::getModelName() const { return modelName; }

void Vehicle::setVehicleColor(string input)
{

}

string Vehicle::getVehicleColor() const { return vehicleColor; }

void Vehicle::setNumberTailLights(int num)
{

}

int Vehicle::getNumberTailLights() const { return numberTailLights; }

Vehicle::Vehicle()
{
	manufactureName = "";
	modelName = "";
	vehicleColor = "";
	numberTailLights = 0;
	
	cout << "Creating new Vehicle.\n\n";
}

Vehicle::~Vehicle() { cout << "In Vehicle destructor.\n"; }