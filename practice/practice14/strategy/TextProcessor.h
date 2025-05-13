#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include "TextFilter.h"
#include <memory>
#include <iostream>
#include <string>

class TextProcessor {
public:
    TextProcessor() : currentFilter(nullptr) {}

    void setFilter(std::shared_ptr<TextFilter> filter) {
        currentFilter = filter;
    }
    void applyFilter(const std::string& input) {
        if (currentFilter) {
            std::string result = currentFilter->apply(input);
            std::cout << "Filtered text: " << result << std::endl;
        } else {
            std::cout << "No filter set!" << std::endl;
        }
    }

private:
    std::shared_ptr<TextFilter> currentFilter;
};

#endif
