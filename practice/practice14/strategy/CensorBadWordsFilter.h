#ifndef CENSORBADWORDS_H
#define CENSORBADWORDS_H

#include "TextFilter.h"
#include <string>
#include <vector>
#include <algorithm>

class CensorBadWordsFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string result = input;
        for (const auto& badWord : badWords) {
            size_t pos = 0;
            while ((pos = result.find(badWord, pos)) != std::string::npos) {
                result.replace(pos, badWord.length(), "****");
                pos += 4; 
            }
        }
        return result;
    }

private:
    const std::vector<std::string> badWords = {"badword1", "badword2", "badword3"}; 
};

#endif 
