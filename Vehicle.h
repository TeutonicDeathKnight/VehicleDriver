#pragma once

//Vehicle class -- Accept and store information about a specific vehicle
class Vehicle
{
public:
	void setManufactureName(std::string input);
	//sets the value of the private member string variable
	//	manufactureName based on input string

	std::string getManufactureName() const;
	//returns the value of the private member string variable manufactureName

	void setModelName(std::string input);
	//sets the value of the private member string variable
	//	modelName based on input string

	std::string getModelName() const;
	//returns the value of the private member string variable modelName

	void setVehicleColor(std::string input);
	//sets the value of the private member string variable
	//	vehicleColor based on input string

	std::string getVehicleColor() const;
	//returns the value of the private member string variable vehicleColor

	void setNumberTailLights(int num);
	//sets the value of the private member int variable
	//	numberTailLights based on randomly generated int input

	int getNumberTailLights() const;
	//returns the value of the private member int variable numberTailLights

	Vehicle();
	//default / zero argument constructor

	~Vehicle();
	//default destructor

private:
	std::string manufactureName;
	//stores the name of the vehicle manufacturer
	//	cannot be blank

	std::string modelName;
	//stores the name of the vehicle model
	//	cannot be blank

	std::string vehicleColor;
	//stores the color of the vehicle
	//	cannot be blank

	int numberTailLights;
	//stores the number of tail lights for the vehicle
	//  random number between 1 and 5 inclusive
};