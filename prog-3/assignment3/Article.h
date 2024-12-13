#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <utility>
#include <string>

class Article {
private:
    int id{};
    std::string description;
    int actualStock{};
    int maxStock{};
    double price{};
    int cpd{}; // consumption per day
    int order_duration{};

public:
    [[nodiscard]] int getId() const {
        return id;
    }

    [[nodiscard]] std::string getDescription() const {
        return description;
    }

    [[nodiscard]] int getMaxStock() const {
        return maxStock;
    }

    [[nodiscard]] int getOrderDuration() const {
        return order_duration;
    }

    [[nodiscard]] int getActualStock() const {
        return actualStock;
    }

    [[nodiscard]] double getPrice() const {
        return price;
    }

    [[nodiscard]] int getCpd() const {
        return cpd;
    }

    [[nodiscard]] int calculateReorderPoint() const {
        return (cpd * order_duration) + 2;
    }

    [[nodiscard]] int calculateOrderProposal() const {
        int reorderPoint = calculateReorderPoint();
        return (actualStock <= reorderPoint) ? (reorderPoint - actualStock) : 0;
    }

    Article() = default;

    Article(int id, std::string description, int actualStock, int maxStock, double price, int cdp,
            int order_duration);

    virtual ~Article();
};

#endif // ARTICLE_H
