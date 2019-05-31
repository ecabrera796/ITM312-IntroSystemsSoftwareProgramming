/* 
 * File:   main.cpp
 * Author: ecabr
 *
 * Created on February 8, 2017, 10:23 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {  
    int x = 100;
    int * intptr;
    
    intptr = &x;
    cout << "value of x -> " << x << endl;
    cout << "address of x -> " << &x << endl;
    cout << "value of intptr -> " << intptr << endl;
    cout << "value of *intptr -> " << *intptr << endl;
    *intptr = 200;
    cout << "new value of *intptr -> " << *intptr << endl;
    cout << "value of x -> " << x << endl;

    return 0;
}