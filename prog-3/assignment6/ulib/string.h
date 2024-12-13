/*
 * String.h
 * Basic reimplementation of String data type
 * @ULib(short for User Defined Library)
 */

#ifndef STRING_H
#define STRING_H
#include <cstdlib> // to have size_t
#include <iostream>

namespace ulib {
    class string {
    public:
        // constructors
        string();

        explicit string(const char str[]);

        string(const std::string str);

        string(const string &source);

        virtual ~string();

        // modifying member functions
        string &operator+=(const string &addend);

        string &operator+=(const char addend[]);

        string &operator+=(const char addend);

        string &operator=(const string &source);

        const char &operator[](size_t position) const; // char at a distinct position
        char &operator[](size_t position); // char at a distinct position

        // constant member functions which do not change the state of the object
        std::size_t length() const { return occupied; } // return number of characters
        const char *c_str() const { return sequence; } // return text as a C-string
        void swap(string &); // exchange of two strings
        bool is_empty() { return (occupied == 0); } // check if empty

        // friends
        friend std::ostream &operator<<(std::ostream &outs, const string &source);

        friend std::istream &operator>>(std::istream &ins, const string &source);

        friend bool operator==(const string &s1, const string &s2);

        friend bool operator!=(const string &s1, const string &s2);

        friend bool operator>=(const string &s1, const string &s2);

        friend bool operator<=(const string &s1, const string &s2);

        friend bool operator>(const string &s1, const string &s2);

        friend bool operator<(const string &s1, const string &s2);

    private:
        size_t occupied{}; // current number of characters
        size_t capacity{}; //	maximum number of characters
        char *sequence{}; // pointer to the beginning of the string array
    };

    // Prototype declarations of NON-MEMBER functions
    // to be used in context with class String
    string operator+(const string &s1, const string &s2);

    string operator+(const string &s1, const char *s2);

    string operator+(const char *s1, const string &s2);

    bool operator==(const string &s1, const string &s2);

    bool operator!=(const string &s1, const string &s2);

    bool operator>=(const string &s1, const string &s2);

    bool operator<=(const string &s1, const string &s2);

    bool operator>(const string &s1, const string &s2);

    bool operator<(const string &s1, const string &s2);

    std::ostream &operator<<(std::ostream &outs, const string &source);

    std::istream &operator>>(std::istream &ins, string &target);
} /* end namespace ulib */

#endif
