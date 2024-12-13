#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Stock.h"

std::vector<std::vector<std::string> > parseCSVFile(std::fstream &file) {
    std::vector<std::vector<std::string> > result;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    std::fstream file("../data.csv", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string> > data = parseCSVFile(file);
    auto *warehouse = new Stock;

    for (const auto &row: data) {
        if (row.size() == 7) {
            try {
                int id = std::stoi(row[0]);
                std::string description = row[1];
                int actualStock = std::stoi(row[2]);
                int maxStock = std::stoi(row[3]);
                double price = std::stod(row[4]);
                int cdp = std::stoi(row[5]);
                int order_duration = std::stoi(row[6]);

                auto article = new Article(id, description, actualStock, maxStock, price, cdp, order_duration);

                warehouse->addArticle(*article);
            } catch (const std::exception &e) {
                std::cerr << "error converting data for row: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "row does not have exactly 7 columns. skipping row." << std::endl;
        }
    }

    warehouse->GenerateOrderProposal("../data_new.csv");

    delete warehouse;
    return 0;
}
