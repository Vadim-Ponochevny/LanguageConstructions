/**********************************
* Author: Vadim Ponochevny        *
* Topic: Processing arrays        *
* Name: variant 3                 *
**********************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0, count = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += matrix[i][j];
            count++;
        }
    }

    cout << "Sum of elements below the main diagonal: " << sum << endl;
    cout << "count of elements below the main diagonal: " << count << endl;

    return 0;
}