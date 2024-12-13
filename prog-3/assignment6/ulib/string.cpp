#include "./string.h"

namespace ulib {
  string::string() {
    occupied = 0;
    capacity = 1;
    sequence = new char[capacity];
    sequence[0] = '\0';
  }

  string::string(const char str[]) {
    if (str == nullptr) {
      occupied = 0;
      capacity = 1;
      sequence = new char[capacity];
      sequence[0] = '\0';
    } else {
      occupied = strlen(str);
      capacity = occupied + 1;
      sequence = new char[capacity];
      strcpy(sequence, str);
    }
  }

  string::string(const std::string str) {
    occupied = str.size();
    capacity = occupied + 1;
    sequence = new char[capacity];
    strcpy(sequence, str.c_str());
  }

  string::string(const string &src) {
    occupied = src.occupied;
    capacity = src.capacity;
    sequence = new char[capacity];
    strcpy(sequence, src.sequence);
  }

  string::~string() { delete[] sequence; }

  std::ostream &operator<<(std::ostream &out, const string &src) {
    out << src.c_str();
    return out;
  }

  std::istream &operator>>(std::istream &in, string &str) {
    std::string temp;
    in >> temp;
    str = temp;
    return in;
  }

  string &string::operator=(const string &src) {
    if (this == &src) {
      return *this;
    }

    delete[] sequence;

    occupied = src.occupied;
    capacity = src.capacity;
    sequence = new char[capacity];
    strcpy(sequence, src.sequence);

    return *this;
  }

  const char &string::operator[](size_t position) const {
    if (position >= occupied) {
      throw std::out_of_range("index is out of range");
    }
    return sequence[position];
  }

  char &string::operator[](size_t position) {
    if (position >= occupied) {
      throw std::out_of_range("index is out of range");
    }
    return sequence[position];
  }

  string &string::operator+=(const string &addend) {
    if (this == &addend) {
      char *temp = new char[occupied + 1];
      strcpy(temp, sequence);
      delete[] sequence;

      occupied = strlen(temp);
      capacity = occupied + 1;
      sequence = new char[capacity];
      strcpy(sequence, temp);
      strcat(sequence, temp);
      delete[] temp;
    } else {
      size_t newOccupied = occupied + addend.occupied;
      char *newSequence = new char[newOccupied + 1];
      strcpy(newSequence, sequence);
      strcat(newSequence, addend.sequence);

      delete[] sequence;
      sequence = newSequence;
      occupied = newOccupied;
      capacity = occupied + 1;
    }
    return *this;
  }

  string &string::operator+=(const char addend[]) {
    size_t addendLength = strlen(addend);
    size_t newOccupied = occupied + addendLength;

    char *newSequence = new char[newOccupied + 1];
    strcpy(newSequence, sequence);
    strcat(newSequence, addend);

    delete[] sequence;
    sequence = newSequence;

    occupied = newOccupied;
    capacity = newOccupied + 1;

    return *this;
  }

  bool operator==(const string &s1, const string &s2) {
    return (strcmp(s1.sequence, s2.sequence)) == 0;
  }

  bool operator!=(const string &s1, const string &s2) {
    return (strcmp(s1.sequence, s2.sequence)) != 0;
  }

  bool operator<=(const string &s1, const string &s2) {
    return strcmp(s1.sequence, s2.sequence) <= 0;
  }

  bool operator>=(const string &s1, const string &s2) {
    return strcmp(s1.sequence, s2.sequence) >= 0;
  }

  bool operator>(const string &s1, const string &s2) {
    return strcmp(s1.sequence, s2.sequence) > 0;
  }

  bool operator<(const string &s1, const string &s2) {
    return strcmp(s1.sequence, s2.sequence) < 0;
  }
} // end namespace ulib
