#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

void stripWhitespaceFromString(std::string &text) {
  text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());
}

std::string toLower(std::string s) {
  std::transform(s.cbegin(), s.cend(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

std::string toUpper(std::string s) {
  std::transform(s.cbegin(), s.cend(), s.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return s;
}

std::vector<int> whiteSpacePositions(std::string text) {
  std::vector<int> wsPositions;
  int idx = 0;
  (void)std::count_if(text.begin(), text.end(),
                      [&wsPositions, &idx](unsigned char c) {
                        if (std::isspace(c)) {
                          wsPositions.push_back(idx);
                        }
                        idx++;
                        return std::isspace(c);
                      });

  return wsPositions;
}

void assureEqualLengthOfStrings(std::string &plaintext,
                                std::string &encryption_key) {
  for (int i = 0; i < plaintext.length(); ++i) {
    if (encryption_key.length() < plaintext.length()) {
      encryption_key += encryption_key[i % plaintext.length()];
    }
  }
}

std::string text, enc_key;

void vigenere_encrypt() {
  std::cout << "Enter the text that you want to be encrypted: ";
  std::getline(std::cin, text);
  std::cout << "Enter encryption keyword: ";
  std::getline(std::cin, enc_key);

  std::vector<int> wsPositions = whiteSpacePositions(text);

  stripWhitespaceFromString(text);
  stripWhitespaceFromString(enc_key);

  assureEqualLengthOfStrings(text, enc_key);

  std::string encrypted_text;
  for (int i = 0; i < text.length(); i++) {
    char x = ((toLower(text)[i] - 'a') + (toUpper(enc_key)[i] - 'A')) % 26;
    x += 'A';
    encrypted_text.push_back(x);
  }

  for (int pos : wsPositions) {
    encrypted_text.insert(pos, " ");
  }

  std::cout << "Encrypted Text: " << encrypted_text << std::endl;
}

void vigenere_decrypt() {
  std::cout << "Enter the text that you want to be decrypted: ";
  std::getline(std::cin, text);
  std::cout << "Enter encryption keyword: ";
  std::getline(std::cin, enc_key);

  std::vector<int> wsPositions = whiteSpacePositions(text);

  stripWhitespaceFromString(text);
  stripWhitespaceFromString(enc_key);

  assureEqualLengthOfStrings(text, enc_key);

  std::string decrypted_text;
  for (int i = 0; i < text.length(); i++) {
    char x = ((toLower(text)[i] - 'a') - (toUpper(enc_key)[i] - 'A') + 26) % 26;
    x += 'a';
    decrypted_text.push_back(x);
  }

  for (int pos : wsPositions) {
    decrypted_text.insert(pos, " ");
  }

  std::cout << "Decrypted Text: " << decrypted_text << std::endl;
}

void vigenere_cypher(int process) {
  switch (process) {
  case 1:
    vigenere_encrypt();
    break;

  case 2:
    vigenere_decrypt();
    break;

  default:
    std::cout << "--> Invalid argument value. The Vigenere Cypher requires an "
                 "argument (1 for encryption, 2 for decryption)."
              << std::endl;
    break;
  }
}
