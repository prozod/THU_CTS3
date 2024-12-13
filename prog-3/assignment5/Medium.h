#ifndef MEDIUM_H
#define MEDIUM_H
#include <string>

class Medium {
protected:
    std::string abbreviation;
    std::string author;
    std::string title;
    std::string pub_year;

public:
    Medium(const std::string &abbreviation, const std::string &author, const std::string &title, int year);

    [[nodiscard]] std::string getAbbreviation() const;

    [[nodiscard]] std::string getAuthor() const;

    [[nodiscard]] std::string getTitle() const;

    [[nodiscard]] int getYear() const;

    void setAbbreviation(const std::string &abbreviation);

    void setAuthor(const std::string &author);

    void setTitle(const std::string &title);

    void setYear(int year);

    [[nodiscard]] virtual std::string toString() const;

    virtual ~Medium() = default;
};

#endif //MEDIUM_H
