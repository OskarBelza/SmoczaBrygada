#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
public:
    Book(const QString &title, const QString &content);

    QString getTitle() const;
    QString getContent() const;

private:
    QString title;
    QString content;
};

#endif // BOOK_H
