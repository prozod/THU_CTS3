#ifndef STRING_H
#define STRING_H
#include <string>
#include <iostream>

// I made this final so that I ensure no other class will inherit from it (this also helps to prevent eventual memory leaks, since my destructor is not virtual)
// In reality, this limits the ability to extend the String class for custom functionality, but I think in this case
// its a good decision, because we know that no other class will inherit from this.

class String final {
private:
    char *string{};

public:
    explicit String(const char *c_string);

    String(const String &copyCtor);

    void display() const;

    void setString(const char *str);

    String &operator=(const String &other);

    void appendChar(char c, unsigned short pos);

    ~String();
};


#endif //STRING_H
