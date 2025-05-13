#ifndef TEXTFILTER_H
#define TEXTFILTER_H

#include <string>

class TextFilter {
public:
    virtual ~TextFilter() = default;
    virtual std::string apply(const std::string& input) = 0;
};

#endif