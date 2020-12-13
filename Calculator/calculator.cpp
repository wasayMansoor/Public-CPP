# include <iostream>
using namespace std;

int main()
{
    int choice;
    int invalid;
    int quit = 0;
    float num1, num2;
    float output;
    string op;

    while(quit != 1){
        invalid = 0;
        cout << "What Would You Like To Do \n0)Quit \n1)Add \n2)Subtract \n3)Multiply \n4)Divide \n>";
        cin >> choice;

        if(choice == 0){
            quit = 1;
            break;
        }

        cout << "\nEnter two digits: " << endl;

        cout << ">";
        cin >> num1;
        cout << ">";
        cin >> num2;

        if(choice == 1){
            op = "+";
            output = num1 + num2;
        }
        else if(choice == 2){
            op = "-";
            output = num1 - num2;
        } 
        else if(choice == 3){
            op = "x";
            output = num1 * num2;
        } 
        else if(choice == 4){
            op = "/";
            output = num1 / num2;
        }
        else{
            cout << "Invalid Choice" << endl;
            invalid = 1;
        }

        if (invalid == 0){
            cout << num1 << op << num2 << "=" << output << endl;
        }
        cout << endl;
    }    
    return 0;
}