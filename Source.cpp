/******************************************
* Author: Vadim Ponochevny                *
* Topic: Using procedures and functions   *
* Name: variant 3                         *
******************************************/
#include <iostream>
#include <vector>

using namespace std;

int sumLessThanB(vector<int> arr, int b) {
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < b) {
            sum += arr[i];
        }
    }
    return sum;
}

vector<int> inputArray(int size, char name) {
    vector<int> arr(size);

    cout << "Enter " << size << " elements of array " << name << ": " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

int main() {
    int n, m, b;

    cout << "Enter the size of array G: ";
    cin >> n;
    cout << "Enter the size of array V: ";
    cin >> m;
    cout << "Enter the value of b: ";
    cin >> b;

    vector<int> G = inputArray(n, 'G');
    vector<int> V = inputArray(m, 'V');

    int sumG = sumLessThanB(G, b);
    int sumV = sumLessThanB(V, b);

    cout << "Sum of elements in array G less than " << b << ": " << sumG << endl;
    cout << "Sum of elements in array V less than " << b << ": " << sumV << endl;

    return 0;
}