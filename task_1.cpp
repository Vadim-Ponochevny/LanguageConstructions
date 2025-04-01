#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double g = 9.81;
const double PI = 3.141592653589793;

int main() {

    double v0, alpha;
    cout << "Enter initial velocity (m/s): ";
    cin >> v0;
    cout << "Enter angle (degrees): ";
    cin >> alpha;

    double alpha_rad = alpha * PI / 180.0;

    double flightTime = (2.0 * v0 * sin(alpha_rad)) / g;
    double H = (v0 * v0 * sin(alpha_rad) * sin(alpha_rad)) / (2.0 * g);
    double L = (v0 * v0 * sin(2.0 * alpha_rad)) / g;
    double R1 = (v0 * v0) / (g * cos(alpha_rad));
    double R2 = (v0 * v0 * cos(alpha_rad) * cos(alpha_rad)) / g;

    cout << fixed << setprecision(6);
    cout << "Flight time: " << flightTime << " sec" << endl;
    cout << "Maximum height: " << H << " m" << endl;
    cout << "Maximum range: " << L << " m" << endl;
    cout << "Radius of curvature at the start of the trajectory: " << R1 << " m" << endl;
    cout << "Radius of curvature at the peak of the trajectory: " << R2 << " m" << endl;

    return 0;
}