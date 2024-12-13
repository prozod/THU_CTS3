#include "Bibliography.h"
#include <sstream>
#include <stdexcept>

Bibliography::Bibliography(int size) : size(size), currentIndex(0) {
    bibliography = new Medium *[size];
    for (int i = 0; i < size; ++i) {
        bibliography[i] = nullptr;
    }
}

Bibliography::~Bibliography() {
    for (int i = 0; i < currentIndex; ++i) {
        delete bibliography[i];
    }
    delete[] bibliography;
}

void Bibliography::insert(Medium *medium) {
    if (currentIndex >= size) {
        throw std::overflow_error("Bibliography is full! Cannot insert more media.");
    }

    for (int i = 0; i < currentIndex; ++i) {
        if (bibliography[i] != nullptr && bibliography[i]->getAbbreviation() == medium->getAbbreviation()) {
            throw std::invalid_argument("Abbreviation already exists in the bibliography.");
        }
    }

    bibliography[currentIndex] = medium;
    ++currentIndex;
}

Medium *Bibliography::operator[](const std::string &abbreviation) const {
    for (int i = 0; i < currentIndex; ++i) {
        if (bibliography[i] != nullptr && bibliography[i]->getAbbreviation() == abbreviation) {
            return bibliography[i];
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const Bibliography &bibliography) {
    for (int i = 0; i < bibliography.currentIndex; ++i) {
        if (bibliography.bibliography[i] != nullptr) {
            os << bibliography.bibliography[i]->toString() << std::endl;
        }
    }
    return os;
}
