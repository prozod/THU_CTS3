#include "Book.h"
#include <sstream>

Book::Book(const std::string &abbreviation, const std::string &author, const std::string &title, int year,
           const std::string &publisher)
    : Medium(abbreviation, author, title, year), publisher(publisher) {
}

std::string Book::getPublisher() const { return publisher; }
void Book::setPublisher(const std::string &publisher) { this->publisher = publisher; }

std::string Book::toString() const {
    std::ostringstream oss;
    oss << "[" << abbreviation << "] " << author << ": " << title << ". " << publisher << ", " << pub_year << ".";
    return oss.str();
}

