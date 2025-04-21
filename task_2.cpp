/***********************************************
* Author: Ponochevny Vadim                     *
* Program: Cycles with pre- and postcondition  *
* Variant: 3                                   *
***********************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double powerCalculation(double resistance, double electromotiveForce, double internalResistance) {
    if (resistance + internalResistance == 0.0) {
        return 0.0;
    }
    else
        return resistance * (electromotiveForce / (resistance + internalResistance)) * (electromotiveForce / (resistance + internalResistance));
}

int main() {
    double electromotiveForce;
    double internalResistance;
    double resistance;
    double currentPower;
    double firstResistanceLimit = 50.0;
    double finalResistanceLimit = 300.0;
    double resistanceStep = 10;
    int decimalPlaces = 2;

    cout << "Load power calculation\n";
    cout << "----------------------\n";

    cout << "Enter EMF (V): ";
    cin >> electromotiveForce;

    cout << "Enter internal resistance (Ohm): ";
    cin >> internalResistance;

    cout << "Enter initial load resistance (Ohm): ";
    cin >> resistance;

    cout << fixed << setprecision(decimalPlaces)
        << "R (Ohm)\tP (Watt)\n"
        << "----------------\n";

    while (resistance < firstResistanceLimit) {
        currentPower = powerCalculation(resistance, electromotiveForce, internalResistance);
        cout << resistance << "\t" << currentPower << endl;
        resistance += resistanceStep;
    }

    resistanceStep = 50;
    do {
        currentPower = powerCalculation(resistance, electromotiveForce, internalResistance);
        cout << resistance << "\t" << currentPower << endl;
        resistance += resistanceStep;
    } while (resistance <= finalResistanceLimit);

    return 0;
}