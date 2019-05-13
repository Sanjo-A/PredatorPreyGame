/******************************************************************************
 * Program Name: Group Project
 * Author: Sanjo Abraham
 * Date: 5/12/2019
 * Description:
 * This is the implement file for the input validation 
 *****************************************************************************/
#include "inputValidation.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int InputValidation::intValidation(int min, int max){
    string strInput;
    int intInput;
    cout << ">>";
    getline(cin, strInput);
    bool inputCheck = false;
    while (inputCheck == false){
        if(InputValidation::isInteger(strInput) == true ){
            intInput = stoi(strInput);
            inputCheck = true;
            if(intInput < min || intInput > max){
                cout << "Please enter a number between [" << min << ", " << max << "]" << endl;
                inputCheck = false;
                cin.clear();
                cout << ">>";
                getline(cin, strInput);
                
            }
        }
        else if (InputValidation::isInteger(strInput) == false){
            inputCheck = false;
            cout << "That was an invalid input. Please enter an integer." << endl;
            cin.clear();
            cout << ">>";
            getline(cin, strInput);
        
                
        }
    }
    return intInput;
}


bool InputValidation::isInteger(string str){
    bool integerCheck = true;
    for (int i = 0; i <str.length(); i++){
        if (isdigit(str[i]) ==false){
            integerCheck = false;
            if (str[0] =='\n'){
                integerCheck = false;
                
            }
        }
    }
    if (str == "") integerCheck = false;
    return integerCheck;
}
