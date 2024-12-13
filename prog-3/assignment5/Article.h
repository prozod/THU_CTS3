#ifndef ARTICLE_H
#define ARTICLE_H
#include "Medium.h"


class Article : public Medium {
private:
    std::string articleDescription;
    int articleNumber;
    int articlePageCount;

public:
    Article(const std::string &abbreviation, const std::string &author, const std::string &title, int year, std::string
            articleDescription, int articleNumber, int articlePageCount);

    [[nodiscard]] std::string getArticleDescription() const;

    [[nodiscard]] int getArticleNumber() const;

    [[nodiscard]] int getArticlePageCount() const;

    void setArticleDescription(const std::string &articleDesc);

    void setArticleNumber(int articleNumber);

    void setArticlePageCount(int pageCount);

    [[nodiscard]] std::string toString() const override;
};


#endif //ARTICLE_H
