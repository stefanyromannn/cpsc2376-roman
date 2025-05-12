#ifndef TEXTFILTER_H
#define TEXTFILTER_H

#include <string>

// Interface for text filter strategies
class TextFilter {
public:
    virtual ~TextFilter() = default;
    virtual std::string apply(const std::string& input) = 0;
};

#endif