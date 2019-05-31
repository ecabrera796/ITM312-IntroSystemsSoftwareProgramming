/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erick Cabrera
 *
 * Created on January 23, 2017, 3:54 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double price = 100;
    double tax = 100 * .10;
    double tip = 100 * .15;
    double total = price + tax + tip;
    
        
    cout << "Meal: " << price << "\n";
    cout << "Tax (10%): " << tax << "\n";
    cout << "Tip (15%): " << tip << "\n";
    cout << "Total: " << total;
    return 0;
}