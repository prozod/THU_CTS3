#include "Stock.h"

double Stock::CalculateStockValue() const {
    double totalValue = 0.0;
    for (const auto &article: articles) {
        totalValue += article.getPrice() * article.getActualStock();
    }
    return totalValue;
}


void Stock::addArticle(const Article &article) {
    articles.push_back(article);
}

void Stock::GenerateOrderProposal(const std::string &newDataFile) const {
    std::ofstream newFile(newDataFile);

    newFile << "id,description,actualStock,maxStock,price,cdp,order_duration,reorder_point,order_proposal\n";

    for (const auto &article: articles) {
        int reorderPoint = article.calculateReorderPoint();
        int orderProposal = article.calculateOrderProposal();

        newFile << article.getId() << ","
                << article.getDescription() << ","
                << article.getActualStock() << ","
                << article.getMaxStock() << ","
                << article.getPrice() << ","
                << article.getCpd() << ","
                << article.getOrderDuration() << ","
                << reorderPoint << ","
                << orderProposal << "\n";
    }
    newFile.close();
}

