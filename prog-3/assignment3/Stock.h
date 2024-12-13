#ifndef STOCK_H
#define STOCK_H
#include <vector>
#include <fstream>
#include "Article.h"


class Stock {
private:
 std::vector<Article> articles;

public:
 Stock() = default;

 [[nodiscard]] double CalculateStockValue() const;

 void addArticle(const Article &article);

 void displayArticles() const {
  for (auto &article: articles) {
   std::cout << article.getPrice();
  }
 }

 void GenerateOrderProposal(const std::string &outputFile) const;
};

#endif //STOCK_H
