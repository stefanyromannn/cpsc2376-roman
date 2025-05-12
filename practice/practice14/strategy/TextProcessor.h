#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include "TextFilter.h"
#include <memory>
#include <iostream>
#include <string>

class TextProcessor {
public:
    TextProcessor() : currentFilter(nullptr) {}

    // Set the current text filter strategy
    void setFilter(std::shared_ptr<TextFilter> filter) {
        currentFilter = filter;
    }

    // Apply the current filter strategy
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

#endif // TEXTPROCESSOR_H
