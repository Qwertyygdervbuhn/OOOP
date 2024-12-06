#include <iostream>
using namespace std;

class Book {
    char* Author;
    char* Text;
    int pages;
    int year;

public:
    Book() : Author(nullptr), Text(nullptr), pages(0), year(0) {}

    Book(const Book&) = delete;
    Book& operator=(const Book&) = delete;

    Book(Book&& obj) noexcept
        : Author(obj.Author), Text(obj.Text), pages(obj.pages), year(obj.year) {
        obj.Author = nullptr;
        obj.Text = nullptr;
    }

    Book& operator=(Book&& obj) noexcept {
        if (this != &obj) {
            delete[] Author;
            delete[] Text;

            Author = obj.Author;
            Text = obj.Text;
            pages = obj.pages;
            year = obj.year;

            obj.Author = nullptr;
            obj.Text = nullptr;
        }
        return *this;
    }

    ~Book() {
        delete[] Author;
        delete[] Text;
    }

    void setAuthor(const char* author) {
        delete[] Author;
        Author = new char[strlen(author) + 1];
    }

    void setText(const char* text) {
        delete[] Text;
        Text = new char[strlen(text) + 1];
    }

    void setPages(int p) {
        pages = p;
    }

    void setYear(int y) {
        year = y;
    }

    void displayInfo() const {
        cout << "Author: " << (Author ? Author : "Unknown") << endl;
        cout << "Text: " << (Text ? Text : "No text provided") << endl;
        cout << "Pages: " << pages << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Book book;

    cout << "Enter author name: ";
    char author[100];
    cin.getline(author, 100);
    book.setAuthor(author);

    cout << "Enter book text (summary or description): ";
    char text[500];
    cin.getline(text, 500);
    book.setText(text);

    cout << "Enter number of pages: ";
    int pages;
    cin >> pages;
    book.setPages(pages);

    cout << "Enter year of publication: ";
    int year;
    cin >> year;
    book.setYear(year);

    cout << "\nBook information:\n";
    book.displayInfo();
}
