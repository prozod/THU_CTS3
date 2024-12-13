#include "Medium.h"
#include <sstream>

Medium::Medium(const std::string &abbreviation, const std::string &author, const std::string &title, int year)
    : abbreviation(abbreviation), author(author), title(title), pub_year(std::to_string(year)) {
}

std::string Medium::getAbbreviation() const { return abbreviation; }
std::string Medium::getAuthor() const { return author; }
std::string Medium::getTitle() const { return title; }
int Medium::getYear() const { return std::stoi(pub_year); }

void Medium::setAbbreviation(const std::string &abbreviation) { this->abbreviation = abbreviation; }
void Medium::setAuthor(const std::string &author) { this->author = author; }
void Medium::setTitle(const std::string &title) { this->title = title; }
void Medium::setYear(int year) { this->pub_year = std::to_string(year); }

std::string Medium::toString() const {
    return "[" + abbreviation + "] " + author + ": " + title;
}

