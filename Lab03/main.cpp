/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab03.cpp
 * Author: Erick Cabrera
 *
 * Created on February 6, 2017, 12:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
int i;
       for( i = 0; i < 10; i++){
         for(int j = 10; j > i; j--)
            cout << " ";
            for(int k = 0; k < i; k++)
                cout << " *";
                cout << endl;
        }
       for(i = 10; i > 0; i--){
        for(int j = 10; j > i; j--)
            cout << " ";
            for(int k = 0; k < i; k++)
                cout << " *";
                cout << endl;
         }
        return 0;
}