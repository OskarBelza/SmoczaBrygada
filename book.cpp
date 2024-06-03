#include "book.h"

Book::Book(const QString &title, const QString &content)
    : title(title), content(content) {}

QString Book::getTitle() const {
    return title;
}

QString Book::getContent() const {
    return content;
}
