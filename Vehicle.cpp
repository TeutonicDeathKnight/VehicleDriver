#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

void Vehicle::setManufactureName(string input) { manufactureName = input; }

string Vehicle::getManufactureName() const { return manufactureName; }

void Vehicle::setModelName(string input) { modelName = input; }

string Vehicle::getModelName() const { return modelName; }

void Vehicle::setVehicleColor(string input) { vehicleColor = input; }

string Vehicle::getVehicleColor() const { return vehicleColor; }

void Vehicle::setNumberTailLights(int num) { numberTailLights = num; }

int Vehicle::getNumberTailLights() const { return numberTailLights; }

Vehicle::Vehicle()
{
	cout << "Creating new Vehicle.\n\n";

	//set each member variable to empty string or 0
	manufactureName = "";
	modelName = "";
	vehicleColor = "";
	numberTailLights = 0;
}

Vehicle::~Vehicle()
{
	cout << "In Vehicle destructor.\n";

	//set each member variable to empty string or null values
	manufactureName = "";
	modelName = "";
	vehicleColor = "";
	numberTailLights = NULL;
}