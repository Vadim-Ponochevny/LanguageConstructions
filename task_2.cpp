#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    const double E = 115.0;
    const double r = 29.7;

    cout << fixed << setprecision(2); 
    cout << "R (Ohm)\tP (Watt)" << endl;
    cout << "----------------" << endl;

    double R = 10; 

    
    while (R < 50) {
        double P = R * pow(E / (R + r), 2); 
        cout << R << "\t" << P << endl;
        R += 10; 
    }

    
    do {
        double P = R * pow(E / (R + r), 2); 
        cout << R << "\t" << P << endl;
        R += 50; 
    } while (R <= 300);

    return 0;
}