#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QObject>
#include <vector>
#include "book.h"

class Archive : public QObject {
    Q_OBJECT
public:
    explicit Archive(QObject *parent = nullptr);

    void addBook(const Book &book);
    std::vector<Book> getBooks() const;

signals:
    void bookAdded(const Book &book);

private:
    std::vector<Book> books;
};

#endif // ARCHIVE_H
