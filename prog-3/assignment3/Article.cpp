#include "Article.h"

Article::Article(int id, std::string description, int actualStock, int maxStock, double price, int cpd,
                 int order_duration) : id(id), description(std::move(description)), actualStock(actualStock),
                                       maxStock(maxStock)
                                       , price(price), cpd(cpd), order_duration(order_duration) {
};


Article::~Article() {
}

