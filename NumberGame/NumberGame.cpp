#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "----------------------------------" << endl;
	cout << " Welcome To Guess That Number!" << endl;
	cout << "----------------------------------" << endl;
	int max = 5;
	int level = 1;
	
	while (true)
	{
		int number = rand() % max; 
		int round = 0;
		int guess = 0;
		int correct = 0;
		//cout << number << endl;
		
		cout << "Level: " << level << endl << endl;
		
		while (round < 5 && correct == 0)
		{
			cout << "Round: " << round+1 << endl;
			cout << "Guess A Number Less Than " << max <<":";
			cin >> guess;
		
			if (guess == number)
			{
				correct = 1;
			}
		
			else
			{
				cout << "Incorrect Guess" << endl << endl;
			}
		
			round = round + 1;
		}
	
		if (correct == 1)
		{
			max = max * 2;
			cout << "Moving To Next Level" << endl;
			level = level + 1;
		}
	
		else
		{
			cout << "You Have Lost The Game" << endl;
			break;
		}
		
		cout << endl << endl;
	}
}