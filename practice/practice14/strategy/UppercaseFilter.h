#ifndef UPPERCASEFILTER_H
#define UPPERCASEFILTER_H

#include "TextFilter.h"
#include <cctype>

class UppercaseFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string uppercase = input;
        for (char& c : uppercase) {
            c = std::toupper(c);
        }
        return uppercase;
    }
};

#endif