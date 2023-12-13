#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

bool search_by_title(Book* books, int n, string title) {
    for (int i = 0; i < n; i++) {
        if (books[i].title == title) {
            return true;
        }
    }
    return false;
}

bool search_by_author(Book* books, int n, string author) {
    for (int i = 0; i < n; i++) {
        if (books[i].author == author) {
            return true;
        }
    }
    return false;
}

bool search_by_year(Book* books, int n, int year) {
    for (int i = 0; i < n; i++) {
        if (books[i].year == year) {
            return true;
        }
    }
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість книг: ";
    cin >> n;

    Book* books = new Book[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть дані для книги №" << i + 1 << ":" << endl;
        cout << "Назва: ";
        cin >> books[i].title;
        cout << "Автор: ";
        cin >> books[i].author;
        cout << "Рік видання: ";
        cin >> books[i].year;
    }

    cout << endl << "Введіть критерій пошуку:" << endl;
    cout << "1. За назвою" << endl;
    cout << "2. За автором" << endl;
    cout << "3. За роком видання" << endl;

    int choice;
    cin >> choice;

    int i;  // Визначення індексу перед switch

    switch (choice) {
    case 1: {
        string title;
        cout << "Введіть назву книги: ";
        cin >> title;

        if (search_by_title(books, n, title)) {
            cout << "Книга знайдена:" << endl;
            i = 0;
            while (books[i].title != title) {
                i++;
            }
            cout << "Назва: " << books[i].title << endl;
            cout << "Автор: " << books[i].author << endl;
            cout << "Рік видання: " << books[i].year << endl;
        }
        else {
            cout << "Книга не знайдена." << endl;
        }
        break;
    }
    case 2: {
        string author;
        cout << "Введіть автора книги: ";
        cin >> author;

        if (search_by_author(books, n, author)) {
            cout << "Книга знайдена:" << endl;
            i = 0;
            while (books[i].author != author) {
                i++;
            }
            cout << "Назва: " << books[i].title << endl;
            cout << "Автор: " << books[i].author << endl;
            cout << "Рік видання: " << books[i].year << endl;
        }
        else {
            cout << "Книга не знайдена." << endl;
        }
        break;
    }
    case 3: {
        int year;
        cout << "Введіть рік видання книги: ";
        cin >> year;

        if (search_by_year(books, n, year)) {
            cout << "Книга знайдена:" << endl;
            i = 0;
            while (books[i].year != year) {
                i++;
            }
            cout << "Назва: " << books[i].title << endl;
            cout << "Автор: " << books[i].author << endl;
            cout << "Рік видання: " << books[i].year << endl;
        }
        else {
            cout << "Книга не знайдена." << endl;
        }
        break;
    }
    default: {
        cout << "Неправильний вибір." << endl;
        break;
    }
    }

    delete[] books;  // Звільнення пам'яті

    return 0;
}
