#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;
    double price;
    int borrowCount;

public:
    Book(string t, string a, int y, double p)
        : title(t), author(a), year(y), price(p), borrowCount(0) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    int getBorrowCount() const { return borrowCount; }

    void setTitle(const string &t) { title = t; }
    void setAuthor(const string &a) { author = a; }
    void setYear(int y) { year = y; }
    void setPrice(double p) { price = p; }

    void borrowBook()
    {
        ++borrowCount;
    }

    void increasePrice(double percent)
    {
        price += price * (percent / 100.0);
    }

    string getBookInfo() const
    {
        string info = "Title: " + title + ", Author: " + author + ", Year: " +
                      to_string(year) +
                      ", Price: " + to_string(price) + "$" +
                      ", Borrowed: " + to_string(borrowCount) + " times";
        return info;
    }
};

class Library
{
private:
    string libraryName;
    vector<Book> books;

public:
    Library(string name) : libraryName(name) {}

    void addBook(const Book &b)
    {
        books.push_back(b);
    }

    void getLibraryInfo() const
    {
        cout << "Library: " << libraryName << endl;
        cout << "******************************" << endl;

        if (books.empty())
        {
            cout << "No books in the library." << endl;
            return;
        }

        for (size_t i = 0; i < books.size(); ++i)
            cout << books[i].getBookInfo() << endl;
    }

    void borrowBookByTitle(const string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title)
            {
                book.borrowBook();
                return;
            }
        }
        cout << "Book titled (" << title << ") not found in the library." << endl;
    }

    void getMostBorrowedBook() const
    {
        if (books.empty())
        {
            cout << "No books available" << endl;
            return;
        }

        const Book *topBook = &books[0];

        for (const auto &book : books)
        {
            if (book.getBorrowCount() > topBook->getBorrowCount())
            {
                topBook = &book;
            }
        }

        cout << "Most borrowed book: " << topBook->getTitle()
             << " {" << topBook->getBorrowCount() << " times}" << endl;
    }

    double getAveragePrice() const
    {
        if (books.empty())
            return 0.0;

        double total = 0;
        for (const auto &book : books)
        {
            total += book.getPrice();
        }
        return total / books.size();
    }

    void findBookByTitle(const string &title) const
    {
        for (const auto &book : books)
        {
            if (book.getTitle() == title)
            {
                cout << "Book found: " << book.getBookInfo() << endl;
                return;
            }
        }
        cout << "Book titled (" << title << ") not found." << endl;
    }
};

int main()
{
    Library lib("Central Library");

    Book b1("C++ Coding", "John Doe", 2013, 45.5);
    Book b2("Python Course", "Jane Doe", 2020, 50.0);
    Book b3("Ui/Ux Design", "Mark Dan", 1990, 75.0);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    for (int i = 0; i < 3; ++i)
        lib.borrowBookByTitle("C++ Coding");
    for (int i = 0; i < 8; ++i)
        lib.borrowBookByTitle("Python Course");

    lib.getLibraryInfo();

    cout << "******************************" << endl;

    lib.getMostBorrowedBook();

    cout << "Average price of books: " << lib.getAveragePrice() << "$" << endl;

    cout << "******************************" << endl;

    lib.findBookByTitle("C++ Coding");
    lib.findBookByTitle("Clean Code");

    return 0;
}
