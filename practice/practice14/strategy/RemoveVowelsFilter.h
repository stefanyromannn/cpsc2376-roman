#ifndef REMOVEVOWELS_H
#define REMOVEVOWELS_H

#include "TextFilter.h"
#include <string>
#include <algorithm>

class RemoveVowelsFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string result;
        for (char c : input) {
            if (!isVowel(c)) {
                result += c;
            }
        }
        return result;
    }

private:
    bool isVowel(char c) {
        c = std::tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};

#endif 
