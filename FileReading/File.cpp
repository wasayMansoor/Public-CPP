#include <iostream> //library for terminal input/output
#include <string> //library for strings
#include <fstream> //library for file input/output

using namespace std;

int main() {
  string filename;
  

  //FILE Loading
  cout << "Enter output filename: ";
  cin >> filename;
  ofstream myOutput(filename);

  int SIZE; //size of data array
  cout << "How many words would you like to add onto the file: ";
  cin >> SIZE;
  string data[SIZE];

  cout << "-> Enter " << SIZE << " words to store in a file: \n";
  for (int i=0; i < SIZE; i++) {
    cin >> data[i];
  }

  //write to file
  for (int i = SIZE; i >= 0; i--) {
    myOutput << data[SIZE-i] << endl;
  }

  //Always close the file when finished
  myOutput.close();

  //FILE INPUT
  cout << "--- Reading " << filename << ".txt ....." << endl;
  ifstream myInput(filename);
  cout << "File Output: " << endl;

  //Read from the filename
  while(!myInput.eof()) {
    string line;
    myInput >> line;
    cout << line << endl;
  }


  //Close the file
  myInput.close();

  return 0;
}