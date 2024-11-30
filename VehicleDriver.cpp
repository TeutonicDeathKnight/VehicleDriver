//VehicleDriver.cpp -- Store and display owned vehicle information
//CSIS 212-<D02_202440>

//Sources
//validateNotEmptyString() and clearInputStream() copied from my lab 5 submission

//include and using statements
#include <iostream>
#include <iomanip>
#include <string>
#include "Vehicle.h"

using namespace std;

//function prototypes
int collectVehicleNumberInput();
void collectVehicleInfo(string& man, string& mod, string& col, int& lights, int position);
string collectStringInput(string prompt, string errMessage);
bool validateNotEmptyString(string strToTest);
void clearInputStream();

//main()
int main()
{
	cout << "Zachary Seeley -- Lab 6 - Dynamic Memory Assignment" << endl << endl;

	int numVehicles = collectVehicleNumberInput();

	Vehicle** vehicles = new Vehicle*[numVehicles];

	for (int i = 0; i < numVehicles; i++)
	{
		string man, mod, col;
		int lights;

		collectVehicleInfo(man, mod, col, lights, i + 1);


	}

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
			cout << "\n\nYour input was not a numeric input, less than 2, or greater than 10."
				<< "\nInput must be a single numeric value between 2 and 10 inclusive.\n\n";
		else
		{
			cout << endl;
			validInput = true;
		}

	} while (validInput == false);

	clearInputStream();

	return input;
}

void collectVehicleInfo(string& man, string& mod, string& col, int& lights, int position)
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



	prompt = "Color of the " + mod + " (White, Blue, etc.): "

}

string collectStringInput(string prompt, string errMessage)
{
	bool inputFlag = false;
	string input;

	do
	{
		cout << prompt;

		getline(cin, input);

		if (validateNotEmptyString(input) == false)
			cout << errMessage;
		else
		{
			cout << endl;
			inputFlag = true;
		}

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