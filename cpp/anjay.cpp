/*
Punya Pibe Ecksdee
*/

#include <iostream>
#include <cmath>
#include <cstdbool>

using namespace std;

int main() {
    string name;
    int height;

    getline(cin, name);
    cout << "Welcome " << name << endl;
    cout << "Enter your height : ";
    cin >> height;

    cout << "your height is " << height << " cm";
} 