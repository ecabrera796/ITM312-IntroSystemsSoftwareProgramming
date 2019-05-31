/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ecabr
 *
 * Created on February 24, 2017, 10:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
double getScore(){
    double score;
    cout << "Please enter your test scores: " << endl;
    cin >> score;
    if(score < 0){
        cout << "Please enter a valid test score: " << endl;
        cin >> score;
    } else if(score > 100){
        cout << "Please enter a valid test score: " << endl;
        cin >> score;
    }
    return score;
}

int main(int argc, char** argv) {
    double score1 = getScore();
    return 0;
}

