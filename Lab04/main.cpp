/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erick Cabrera
 *
 * Created on February 13, 2017, 4:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */

// assigns score ranges to letter grades
string convert (double score){
    string scoreGrade;
    while(score <= 100 && score >= 90){
        scoreGrade = "Your grade is A.";
        return scoreGrade;
    }
    while(score < 90 && score >= 80){
        scoreGrade = "Your grade is B.";
        return scoreGrade;
    }
    while(score < 80 && score >= 70){
        scoreGrade = "Your grade is C.";
        return scoreGrade;
    }
    while(score < 70 && score >= 60){
        scoreGrade = "Your grade is D.";
        return scoreGrade;
    }
    while(score < 60 && score >= 0){
        scoreGrade = "Your grade is F.";
        return scoreGrade;
    }
}

int main(int argc, char** argv) {
    double score;
    // asks user to input their score
    cout << "Hello, please enter your score:" << endl;
    cin >> score;
    // message telling user score is invalid, try again
    while(score < 0 || score > 100){
        cout << "Please enter valid score between 0-100!" << endl;
        cout << "Hello, please enter your score." << endl;
        cin >> score;
    }
    cout << convert(score) << endl;
    return 0;
}

