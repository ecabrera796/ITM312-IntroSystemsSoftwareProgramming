/* 
 * File:   main.cpp
 * Author: Erick Cabrera
 * Created on March 6, 2017, 3:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
    // random generator for number between 50 and 1
    int number = rand() % 50 + 1;
    cout << number << endl;
    
    //ask user for their guess
    int guess;
    cout << "Please enter an integer between 1 and 50" << endl;
    cin >> guess;
    
    // user inputs valid number
    while(guess >= 1 && guess <= 50){
        
        // number is lower than 1
        if (guess < number){
            cout << "You guessed too low! Please try again!" << endl;
            cout << "Please enter an integer between 1 and 50" << endl;
            cin >> guess;
            
         // number is higher than 1   
         } else if (guess > number){
             cout << "You guessed too high! Please try again!" << endl;
             cout << "Please enter an integer between 1 and 50" << endl;
             cin >> guess;
             
         // number is correct    
         } else if (guess = number){
             cout << "You guessed right" << endl;
             return 0;
         }
    }
    
    // user inputs invalid number
    while (guess < 1 || guess > 50){
    cout << "You entered an invalid number that is outside of the range! Please try again!" << endl;
    cout << "Please enter an integer between 1 and 50" << endl;
    cin >> guess;
    }
    return 0;
}

