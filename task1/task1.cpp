#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Firm {
    string name;
    int quantity;
    double sales;
    double market_share;
};

void sort_by_quantity(Firm* firms, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (firms[i].quantity < firms[j].quantity) {
                Firm temp = firms[i];
                firms[i] = firms[j];
                firms[j] = temp;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість рядків таблиці: ";
    cin >> n;

    Firm* firms = new Firm[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть дані для рядка №" << i + 1 << ":" << endl;
        cout << "Назва фірми: ";
        cin >> firms[i].name;
        cout << "Кількість: ";
        cin >> firms[i].quantity;
        cout << "Річний обсяг продажу ($): ";
        cin >> firms[i].sales;
        cout << "Частина ринку (%): ";
        cin >> firms[i].market_share;
    }

    sort_by_quantity(firms, n);

    cout << endl << "Таблиця з відсортованими даними по кількості:" << endl;
    cout << left << setw(15) << "Назва фірми" << setw(10) << "Кількість" << setw(20) << "Річний обсяг продажу ($)" << setw(20) << "Частина ринку (%)" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << firms[i].name << setw(10) << firms[i].quantity << setw(20) << firms[i].sales << setw(20) << firms[i].market_share << endl;
    }

    delete[] firms;

    return 0;
}
