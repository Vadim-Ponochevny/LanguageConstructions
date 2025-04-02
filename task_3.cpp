#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    const double n = 0.009;          // Kinematic viscosity (cm²/s)
    const double d = 1.91;           // Pipe diameter (cm)

    double speeds[] = { 1, 2, 5, 10, 20, 50, 100 }; // Flow speeds (m/s)

    cout << "Speed (m/s)   | Reynolds Number | Resistance Coefficient\n";

    for (double J : speeds) {
        double J_cm_s = J * 100;  // Convert speed to cm/s
        double R = (J_cm_s * d) / n;  // Calculate Reynolds number

        double lambda;
        if (R > 920000) {
            lambda = 0.021 / pow(d, 0.3);  // Formula for turbulent flow
        }
        else {
            lambda = pow((1.5 * pow(10, -6) / d) + (1.0 / R), 0.3); // Formula for laminar flow
        }

        cout << fixed << setw(13) << setprecision(0) << J << " | "  
            << setw(15) << setprecision(4) << R << " | "  
            << setw(21) << lambda << endl;
    }

    return 0;
}