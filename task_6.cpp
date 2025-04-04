/*********************************************************************
* Author: Ваше имя                                                  *
* Name: Работа с файлами (Книги)                                    *
* Description: Файл содержит сведения о книгах:                     *
*              - фамилия автора,                                    *
*              - название,                                          *
*              - год издания,                                       *
*              - количество,                                        *
*              - цена.                                              *
*              Выведите список книг заданного автора                *
*              и определите их общую стоимость.                     *
*              Найдите среди всех книг самую старую.                *
* URL: https://onlinegdb.com/                                        *
*********************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Book {
    string author;
    string title;
    int year;
    int quantity;
    float price;
};

int main() {
    string fileName, targetAuthor = "";
    int bookCount, authorChoice, oldestBookIndex = 0;
    float totalCost = 0;

    cout << "Enter filename (20 characters max): ";
    cin >> fileName;

    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "File not found. Please restart the program." << endl;
        return 1;
    }

    cout << "Enter number of books in file (10 max): ";
    cin >> bookCount;
    vector<Book> library(bookCount);

    cout << "Select author to search:\n1. Tolstoy\n2. Dostoevsky\n3. Pushkin\n4. Gogol\n";
    while (targetAuthor.empty()) {
        cin >> authorChoice;
        switch (authorChoice) {
        case 1: targetAuthor = "Tolstoy"; break;
        case 2: targetAuthor = "Dostoevsky"; break;
        case 3: targetAuthor = "Pushkin"; break;
        case 4: targetAuthor = "Gogol"; break;
        default: cout << "No such author. Try again: ";
        }
    }

    cout << "\nBooks by " << targetAuthor << ":\n";
    cout << left << setw(25) << "TITLE" << " | "
        << setw(6) << "YEAR" << " | "
        << setw(6) << "COUNT" << " | "
        << "PRICE" << endl;
    cout << string(60, '-') << endl; // Разделительная линия

    for (int i = 0; i < bookCount; ++i) {
        fin >> library[i].author
            >> library[i].title
            >> library[i].year
            >> library[i].quantity
            >> library[i].price;

        // Find oldest book
        if (library[i].year < library[oldestBookIndex].year) {
            oldestBookIndex = i;
        }

        // Process books by selected author
        if (library[i].author == targetAuthor) {
            cout << left << setw(25) << library[i].title << " | "
                << right << setw(6) << library[i].year << " | "
                << setw(6) << library[i].quantity << " | "
                << setw(5) << library[i].price << "$" << endl;
            totalCost += library[i].quantity * library[i].price;
        }
    }

    cout << "\nTotal book value: " << totalCost << "$" << endl;
    cout << "The oldest book in library: \""
        << library[oldestBookIndex].title << "\" ("
        << library[oldestBookIndex].author << ", "
        << library[oldestBookIndex].year << ")\n";

    return 0;
}