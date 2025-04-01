#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

const double g = 9.81;
const double PI = 3.141592653589793; 

int main() {
    setlocale(LC_ALL, "RU");

    double v0, alpha;
    cout << "Введите начальную скорость (м/с): ";
    cin >> v0;
    cout << "Введите угол (в градусах): ";
    cin >> alpha;

    double alpha_rad = alpha * PI / 180.0; 

    double flightTime = (2.0 * v0 * sin(alpha_rad)) / g;
    double H = (v0 * v0 * sin(alpha_rad) * sin(alpha_rad)) / (2.0 * g);
    double L = (v0 * v0 * sin(2.0 * alpha_rad)) / g;
    double R1 = (v0 * v0) / (g * cos(alpha_rad));
    double R2 = (v0 * v0 * cos(alpha_rad) * cos(alpha_rad)) / g;


    cout << fixed << setprecision(6);
    cout << "Время полета: " << flightTime << " сек" << endl;
    cout << "Максимальная высота: " << H << " м" << endl;
    cout << "Максимальная дальность: " << L << " м" << endl;
    cout << "Радиус кривизны начала траектории: " << R1 << " м" << endl;
    cout << "Радиус кривизны вершины траектории: " << R2 << " м" << endl;

    return 0;
}