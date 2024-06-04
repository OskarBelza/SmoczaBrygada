#include "archive.h"

Archive::Archive(QObject *parent) : QObject(parent) {
    books.push_back(Book("informacje o smokach", "Smoki to mistyczne stworzenia..."));
    books.push_back(Book("informacje o smokach", "Smoki to mistyczne stworzenia..."));
    books.push_back(Book("informacje o smokach", "Smoki to mistyczne stworzenia..."));
}

void Archive::addBook(const Book &book) {
    books.push_back(book);
    emit bookAdded(book);
}

std::vector<Book> Archive::getBooks() const {
    return books;
}
