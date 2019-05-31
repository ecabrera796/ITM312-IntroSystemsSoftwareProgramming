/*
 * File:   main.cpp
* Author: Erick Cabrera
*
* Created on February 6, 2017, 12:08 PM
*/
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
 
using namespace std;
 
/*
*
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    cout << "Please follow the steps to successfully troubleshoot your engine." << endl;
    int statusLight;
    int meter;
    int pressure;
    int flow;
    cout << "What color is the status light? (1 for Green, 2 for Red, 3 for Amber)" << endl;
    statusLight = rand() % 3 + 1;
    if (statusLight == 1){
        cout << "restart the engine";
        return 0;
    } else if(statusLight == 2){
        cout << "Shut off input lines" << endl;
    } else if(statusLight == 3){
        cout << "Check fuel service routine" << endl;
        return 0;
    }
    cout << "What does meter #3 read?" << endl;
    meter = rand() % 50 + 1;
    if(meter < 50){
        cout << "Check main line for test pressure. What does it read? (1 for Normal, 2 for High, 3 for Low)" << endl;
        pressure = rand() % 3 + 1;
        if(pressure == 1){
            cout << "Refer to motor service manual" << endl;
            return 0;
        } else if(pressure == 2 || pressure == 3){
            cout << "Check main line service manual" << endl;
            return 0;
        }
    }else if(meter >= 50){
        cout << "Measure flow velocity at inlet 2-B. \nWhat does it read? (1 for Normal, 2 for High, 3 for Low)" << endl;
        flow = rand() % 3 + 1;
        if(flow = 1){
            cout << "Refer to inlet service manual" << endl;
            return 0;
        } else if(flow == 2 || flow == 3){
            cout << "Refer unit for factory service" << endl;
            return 0;
        }
    }
    return 0;
}