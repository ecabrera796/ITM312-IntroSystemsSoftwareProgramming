/* 
 * File:   main.cpp
 * Author: Erick Cabrera
 *
 * Created on March 27, 2017, 4:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//int maxDirectory = 0;

struct Directory{
    Directory  * ptr;
    int studentID;          // student ID number
    string firstName;     // student first name
    string lastName;     // student last name
    string bday;            // student date of birth
    string email;           // student email
};
    
Directory * first;
Directory * last;

void addStudent(){
    Directory * current;
    current = new Directory;
    //current -> studentID = maxDirectory;
    
    cout << "Enter student's ID number: ";
    cin >> current -> studentID;
    cout << endl;
    
    cout << "Enter student's first name: ";
    cin >> current -> firstName;
    cout << endl;
    
    cout << "Enter student's last name: ";
    cin >> current -> lastName;
    cout << endl;
    
    cout << "Enter student's date of birth: ";
    cin >> current -> bday;
    cout << endl;
    
    cout << "Enter student's email: ";
    cin >> current -> email;
    cout << endl;
    
    if(first == NULL){
        first = current;
    }
    else if(last != NULL){
        last -> ptr = current;
    }
    
    last = current;
    //maxDirectory++;
}

void showData(){
    Directory * current;
    current = first;
    
    bool complete = false;
    do{
        cout << "Student ID: " << current -> studentID << endl;
        cout << "First name: " << current -> firstName << endl;
        cout << "Last name: " << current -> lastName << endl;
        cout << "Date of Birth: " << current -> bday << endl;
        cout << "Email: " << current -> email << endl;
        
        if(&current == &last){
            complete = true;
        }else{
            current = current -> ptr;
        }
    }while(complete == false);
}

int main(int argc, char** argv) {
    addStudent();
    showData();
    
    return 0;
}

