#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    const double electromotiveForce = 115.0;
    const double internalResistance = 29.7;
    double resistance = 10;
    double currentPower;
    int marginSize = 2;

    cout << fixed << setprecision(marginSize)
         << "R (Ohm)\tP (Watt)\n"
         << "----------------\n";
    
    while (resistance < 50) {
        currentPower = resistance * pow(electromotiveForce / (resistance + internalResistance), 2);
        cout << resistance << "\t" << currentPower << endl;
        resistance += 10; 
    }
    
    do {
        currentPower = resistance * pow(electromotiveForce / (resistance + internalResistance), 2);
        cout << resistance << "\t" << currentPower << endl;
        resistance += 50; 
    } while (resistance <= 300);

    return 0;
}