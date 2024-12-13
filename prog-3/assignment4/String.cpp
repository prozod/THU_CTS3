#include "String.h"

// 2. Implement a constructor that takes a C-string as an argument and dynamically allocates memory for it.
String::String(const char *c_string) : string(nullptr) {
    if (c_string) {
        string = new char[strlen(c_string) + 1];
        strcpy(string, c_string);
    }
}

// 3. Implement a copy constructor that creates a deep copy of a String object. Ensure that changes to one object do not affect the other.
String::String(const String &copyCtor) : string(nullptr) {
    if (copyCtor.string) {
        string = new char[strlen(copyCtor.string) + 1];
        strcpy(string, copyCtor.string);
    }
}


void String::display() const {
    if (string) {
        std::cout << string;
    } else {
        std::cout << "(null)";
    }
}

void String::setString(const char *str) {
    if (str) {
        delete[] string;
        string = new char[strlen(str) + 1];
        strcpy(string, str);
    }
}

// 4.Implement a method that allows setting a character at a specific index within the String.
void String::appendChar(const char c, unsigned short pos) {
    if (!string) {
        string = new char[2];
        string[0] = c;
        string[1] = '\n';
        return;
    }

    size_t og_length = strlen(string);

    if (pos > og_length) {
        pos = og_length;
    }

    char *new_string = new char[og_length + 2];

    for (size_t i = 0; i < pos; ++i) {
        new_string[i] = string[i];
    }

    new_string[pos] = c;

    for (size_t i = pos; i < og_length; ++i) {
        new_string[i + 1] = string[i];
    }

    new_string[og_length + 1] = '\0';


    delete[] string;
    string = new_string;
}


String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }

    delete []string;

    if (other.string) {
        string = new char[strlen(other.string) + 1];
        strcpy(string, other.string);
    } else {
        string = nullptr;
    }

    return *this;
}

// 5. Implement a destructor to release the dynamically allocated memory.
String::~String() {
    delete[] string;
}
