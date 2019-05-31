/* 
 * File:   main.cpp
 * Author: Erick Cabrera
 *
 * Created on March 20, 2017, 4:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

    void swap(int *x, int *y){
         int ref;
         ref = *x;
        *x = *y;
        *y = ref;
    }
    
    void swap(double &a, double &b){
        double point;
        point = a;
        a = b;
        b = point;
    }
    
    void swap(char *i, char *j){
         char any;
         any = *i;
        *i = *j;
        *j = any;
    }
    
int main(int argc, char** argv) {
    int num1 = 5, num2 = 33;
    swap(&num1, &num2);
    cout << "The value of x -> " << num1 << endl;
    cout << "The value of y -> " << num2 << endl;    
    
    double dub1 = 1.5, dub2 = 3.5;
    swap(dub1, dub2);
    cout << "The value of a -> " << dub1 << endl;
    cout << "The value of b -> " << dub2 << endl;
    
    char letter1 = 'k', letter2 = 'e';
    swap(&letter1, &letter2);
    cout << "The value of i -> " << letter1 << endl;
    cout << "The value of j-> " << letter2 << endl;
}
