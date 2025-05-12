#ifndef REVERSEFILTER_H
#define REVERSEFILTER_H

#include "TextFilter.h"
#include <algorithm>

class ReverseFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string reversed = input;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

#endif