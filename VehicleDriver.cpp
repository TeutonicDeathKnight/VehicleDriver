//VehicleDriver.cpp -- Store and display owned vehicle information
//CSIS 212-<D02_202440>

//Sources
//validateNotEmptyString() and clearInputStream() copied from my lab 5 submission
//destroyVehicles() logic derived from lab instructions

//include and using statements
#include <iostream>
#include <iomanip>
#include <string>
#include "Vehicle.h"

using namespace std;

//function prototypes
int collectVehicleNumberInput();
void createVehicles(const int& numVehicles, Vehicle** vehicles);
void displayVehicles(const int& numVehicles, Vehicle** vehicles);
void destroyVehicles(const int& numVehicles, Vehicle** vehicles);
void collectVehicleInfo(string& man, string& mod, string& col, int position);
string collectStringInput(string prompt, string errMessage);
bool validateNotEmptyString(string strToTest);
void clearInputStream();

//main()
int main()
{
	cout << "Zachary Seeley -- Lab 6 - Dynamic Memory Assignment" << endl << endl;

	const int numVehicles = collectVehicleNumberInput();

	Vehicle** vehicles = new Vehicle*[numVehicles];

	createVehicles(numVehicles, vehicles);

	displayVehicles(numVehicles, vehicles);

	destroyVehicles(numVehicles, vehicles);

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//collectVehicleNumberInput()
int collectVehicleNumberInput()
{
	bool validInput = false;
	int input;

	//prompt and reprompt user until valid input is given
	do
	{
		//prompt user for the number of owned vehicles
		cout << "Number of vehicles you have owned (2-10): ";

		//collect input from user
		cin >> input;

		//if input was non numeric or out of range
		//	output error message
		//else
		//	set validInput flag to true
		if (cin.fail() || !(input >= 2 && input <= 10))
		{
			cout << "\n\nYour input was not a numeric input, less than 2, or greater than 10."
				<< "\nInput must be a single numeric value between 2 and 10 inclusive.\n\n";
		}
		else
		{
			cout << endl;
			validInput = true;
		}

		clearInputStream();

	} while (validInput == false);

	return input;
}

void createVehicles(const int& numVehicles, Vehicle** vehicles)
{
	//set rand() seed to 100 per lab instructions
	srand(100);

	for (int i = 0; i < numVehicles; i++)
	{
		string man, mod, col;
		int lights;

		//add extra line between vehicle inputs to match output example in lab instructions
		if (i > 0)
			cout << endl;

		//collect user input for manufacture, model, color
		//  assign values to related variables
		collectVehicleInfo(man, mod, col, i + 1);

		//create lights for vehicle using rand()
		//	use the remainder of rand() divided by 6 to get a value between 0 and 5
		//	repeat until lights value is between 1 and 5 inclusive
		do
			lights = rand() % 6;
		while (!(lights >= 1 && lights <= 5));

		//create new reference to vehicle object
		//	then set object values using class setters, user inputs, and randomly generated number
		vehicles[i] = new Vehicle;
		vehicles[i]->setManufactureName(man);
		vehicles[i]->setModelName(mod);
		vehicles[i]->setVehicleColor(col);
		vehicles[i]->setNumberTailLights(lights);
	}
}

void displayVehicles(const int& numVehicles, Vehicle** vehicles)
{
	//output display output header
	cout << right << setw(39) << "These are the vehicles you have owned:" << '\n';

	//output each line item for each vehicle
	for (int i = 0; i < numVehicles; i++)
		cout << setw(40) << "Vehicle Manufacture: " << vehicles[i]->getManufactureName() << '\n'
			<< setw(40) << "Vehicle Model: " << vehicles[i]->getModelName() << '\n'
			<< setw(40) << "Vehicle Color: " << vehicles[i]->getVehicleColor() << '\n'
			<< setw(40) << "Number of Tail Lights per side (1-5): "
			<< vehicles[i]->getNumberTailLights() << "\n\n";
}

void destroyVehicles(const int& numVehicles, Vehicle** vehicles)
{
	//loop through the vehicles array
	//	delete each vehicle object and set each pointer to null
	for (int i = 0; i < numVehicles; i++)
	{
		delete vehicles[i];
		vehicles[i] = NULL;
	}

	//delete vehicles array and set pointer to vehicles array to null
	delete vehicles;
	vehicles = NULL;

	cout << endl;
}

void collectVehicleInfo(string& man, string& mod, string& col, int position)
{
	cout << "Vehicle #" << position << "\n\n";

	string prompt = "Vehicle Manufacture: ";

	string errMessageBase = "\n\nInput is blank and cannot be blank.\n";
	string errMessage =
		errMessageBase + "You must input the name of a vehicle manufacturer.\n\n";

	man = collectStringInput(prompt, errMessage);

	prompt = "Model of " + man + " vehicle (Escape, F-150, etc.): ";

	errMessage =
		errMessageBase + "You must input the name of a vehicle model.\n\n";

	mod = collectStringInput(prompt, errMessage);

	prompt = "Color of the " + mod + " (White, Blue, etc.): ";

	errMessage =
		errMessageBase + "You must input the name of a vehicle color.\n\n";

	col = collectStringInput(prompt, errMessage);
}

string collectStringInput(string prompt, string errMessage)
{
	bool inputFlag = false;
	string input;

	//while input is not valid,
	//	prompt and reprompt user for valid text input
	do
	{
		cout << prompt;

		getline(cin, input);

		if (validateNotEmptyString(input) == false)
			cout << errMessage;
		else
			inputFlag = true;

	} while (inputFlag == false);

	return input;
}

//validateNotEmptyString()
bool validateNotEmptyString(string strToTest)
{
	bool containsNonWhitespaceChars = false;
	string str = strToTest;

	//loop through strToTest
	for (int position = 0; position < str.length(); position++)
	{
		char evalChar = str[position];

		//if current character is one of the 6 whitespace characters
		// replace with the null character
		if (evalChar == 9
			|| evalChar == 10
			|| evalChar == 11
			|| evalChar == 12
			|| evalChar == 13
			|| evalChar == 32)
		{
			str[position] = '\0';
		}
	}

	//loop through string and if a non whitespace character is found
	// set containsNonWhitespaceChars to true and break out of loop
	for (int position = 0; position < str.length(); position++)
		if (str[position] != '\0')
		{
			containsNonWhitespaceChars = true;
			break;
		}

	//if input is only whitespace characters, output error message
	if (containsNonWhitespaceChars == false)
	{
		cout << endl << "Input cannot be blank or only whitespace characters." << endl
			<< "Press enter to continue." << endl;
	}

	return containsNonWhitespaceChars;
}

//clearInputStream()
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line
	//	until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}