#include <iostream>
#include <cmath>

using namespace std;
const int nOfFactories = 3;

//nOfFactories is Number Of Factories 
//arrayOfUnits contains number of units for each factroy
//arrayOfThousands contains number of units for each factory but in thousands
//counter are just being used for loops


void inputUnits(int arrayOfUnits[], int counter);
void thousands(int arrayOfUnits[], int counter2);
void outputLoop(const int arrayOfThousands[], int counter);
void totalUnits(int& sum);
int doublesCalculator(double number);
void graph(int n);

//main code which states what the program does and calls the functions
int main( )
{
    int production[nOfFactories];
    cout << "This program displays graph showing\n" << "production for each factory in the company.\n";
    inputUnits(production, nOfFactories);
    thousands(production, nOfFactories);
    outputLoop(production, nOfFactories);
    return 0;
}

//This function loops over n amount of times, n being number of factories
void inputUnits(int arrayOfUnits[], int counter)
{
    for (int factoryN = 1;factoryN <= counter; factoryN++)
    {
		//will call the totalUnits(gets number of units produced) function n number of times
        cout << endl << "--Enter production data for plant number " << factoryN << endl;
        totalUnits(arrayOfUnits[factoryN - 1]);
	}
}


//Inputs number of units produced by each department, then adds them up to calculate the total number of units produced by a factory
void totalUnits(int& sum)
{
    cout << "Enter number of units produced by each department, to end list enter a negative number.\n";
    sum = 0; 
	int units;
    cin >> units;
	// loops over and adds up the input, to get the total number of units produced by a factory. Loops stops when a negative number is inputted
    while (units >= 0) {
		sum = sum + units;
		cin >> units;
    } 
	//prints out total number of units produced by a factory
	cout << "Total = " << sum << endl;
}

//this function calculates number of units produced in thousands
void thousands(int arrayOfUnits[], int counter2)
{
for (int index = 0; index < counter2; index++){
	//calls doublesCalculator to change the current variable into a double then divides it by 1000 to get how many thousands of units have been produced
    arrayOfUnits[index] = doublesCalculator(arrayOfUnits[index]/1000.0);
	}
}

//this function changes variables to doubles and rounds the value
int doublesCalculator(double number) 
{
	return static_cast<int>(floor(number + 0.5));
}

//loops over for all the factories and calls the graph function for each one of them
void outputLoop(const int arrayOfThousands[], int counter)
{
    cout << "\nUnits produced in thousands of units:\n";
	//loop over n number of times, n being number of factories
    for (int factoryN = 1; factoryN <= counter; factoryN++)
    {
		//prints out current factory number
        cout << "Factory #" << factoryN << " ";
		//calls graph function for current factory
        graph(arrayOfThousands[factoryN - 1]);
        cout << endl;
    }
}

//prints a * for each thousands of units produced
void graph(int n) {
    for (int count = 1; count <= n; count++){
		cout << "*";
	}
}