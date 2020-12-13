#include <iostream>
#include <string>
#include <fstream>

/// ARGUMENTS WHEN RUNNING PROGRAM
// (1): -e OR -d	FOR ENCRYPTION OR DECRYPTION
// (2): any integer	FOR KEY
// (3): INPUT FILE NAME
// (4): OUTPUT FILE NAME

using namespace std;


int decryption(ifstream &infile, ofstream &outfile, int shift)
{
	string line;
	while ( getline (infile,line) )
	{
		//initializing encrypted message
		string ciphertext;
		//for loop until end of message
		for (int i=0;i<line.length();i++) 
		{
			//initalizing variable used to encrypt each chr in the message
			char encryptedChr;
			//encrypting each chr
			encryptedChr = line[i];
			if (encryptedChr >= 'A' && encryptedChr <= 'Z')
			{
				encryptedChr = line[i] - shift;
				//if value of chr goes above value of Z then program puts the value back to value of A and continues from there
				if (encryptedChr > 'Z')
				{
					encryptedChr = encryptedChr - 'Z' + 'A' - 1;
				}
				//if value of chr goes below value of A then program puts the value back to value of Z and continues from there
				else if (encryptedChr < 'A')
				{
					encryptedChr = encryptedChr - 'A' + 'Z' + 1;
				}
			}
			//adds up all the encrypted chr and produces an output
			ciphertext = ciphertext + encryptedChr;		
		}
		outfile << ciphertext << "\n";
	}
	outfile.close();
	infile.close();
	
	return 0;
}

int encryption(ifstream &infile, ofstream &outfile, int shift)
{
	string line;
	while ( getline (infile,line) )
	{
		//initializing encrypted message
		string ciphertext;	
		//for loop until end of message
		
		for (int i=0;i<line.length();i++) 
		{
			//initalizing variable used to encrypt each chr in the message
			char encryptedChr;
			//encrypting each chr
			encryptedChr = line[i];
			if (encryptedChr >= 'A' && encryptedChr <= 'Z')
			{
				encryptedChr = line[i]+ shift;
				//if value of chr goes above value of Z then program puts the value back to value of A and continues from there
				if (encryptedChr > 'Z'){
				encryptedChr = encryptedChr - 'Z' + 'A' - 1;
				}
					//if value of chr goes below value of A then program puts the value back to value of Z and continues from there
				else if (encryptedChr < 'A'){
					encryptedChr = encryptedChr - 'A' + 'Z' + 1;
				}
			}
			//adds up all the encrypted chr and produces an output
			ciphertext = ciphertext + encryptedChr;				
		}
		
		outfile << ciphertext << "\n";
		
	}
	outfile.close();
	infile.close();
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc < 5){
		cout << "Missing Arguments" << endl;
		return 0;
	}
	//input shift value
	int shift = atoi(argv[2]);
	
	//Files
	string line;
	ifstream infile(argv[3]);
	
	if (infile.is_open() && infile.good())
	{
		if (string(argv[1]) == "-e")
		{
			ofstream outfile(argv[4]);
			encryption(infile, outfile, shift);
		}
		
		else if (string(argv[1]) == "-d")
		{
			ofstream outfile(argv[4]);
			decryption(infile, outfile, shift);
		}
		
		else
		{
			cout << "Invalid Arguments" << endl;
		}
	}
	
	return 0;
}