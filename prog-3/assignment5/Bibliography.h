#ifndef BIBLIOGRAPHY_H
#define BIBLIOGRAPHY_H

#include "Medium.h"
#include <iostream>

class Bibliography {
private:
    Medium **bibliography;
    int size;
    int currentIndex;

public:
    explicit Bibliography(int size);

    ~Bibliography();

    void insert(Medium *medium);

    Medium *operator[](const std::string &abbreviation) const;

    friend std::ostream &operator<<(std::ostream &os, const Bibliography &bibliography);
};

#endif // BIBLIOGRAPHY_H
