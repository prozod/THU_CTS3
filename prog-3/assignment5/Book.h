#ifndef BOOK_H
#define BOOK_H
#include "Medium.h"


class Book : public Medium {
private:
    std::string publisher;

public:
    Book(const std::string &abbreviation, const std::string &author, const std::string &title, int year,
         const std::string &publisher);

    [[nodiscard]] std::string getPublisher() const;

    void setPublisher(const std::string &publisher);

    [[nodiscard]] std::string toString() const override;
};

#endif //BOOK_H
