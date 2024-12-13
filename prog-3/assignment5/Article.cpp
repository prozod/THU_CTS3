#include "Article.h"
#include <sstream>


Article::Article(const std::string &abbreviation, const std::string &author, const std::string &title, int year,
                 std::string articleDescription, int articleNumber, int articlePageCount)
    : Medium(abbreviation, author, title, year), articleNumber(articleNumber), articleDescription(articleDescription)
      , articlePageCount(articlePageCount) {
}

[[nodiscard]] std::string Article::getArticleDescription() const {
    return articleDescription;
}

[[nodiscard]] int Article::getArticleNumber() const {
    return articleNumber;
}

[[nodiscard]] int Article::getArticlePageCount() const {
    return articlePageCount;
}

void Article::setArticleDescription(const std::string &articleDesc) {
    articleDescription = articleDesc;
}

void Article::setArticleNumber(int articleNumber) {
    this->articleNumber = articleNumber;
}

void Article::setArticlePageCount(int pageCount) {
    articlePageCount = pageCount;
}

std::string Article::toString() const {
    std::ostringstream oss;
    oss << "[" << abbreviation << "] " << author << ": " << title << ". " << articleDescription << ", "
            << articleNumber << ", " << pub_year << ".";
    return oss.str();
}
