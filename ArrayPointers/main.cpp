#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
    

int main(int argc, char** argv) {
    int num1 = 2, num2 = -3;
    swap(&num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
    
}

