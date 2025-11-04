#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool isDigitsOnly(const std::string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::vector<std::string> words;
    std::string word;

    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] != ' ') {
            word += line[i];
        }
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    std::vector<int> digitIndices;

    for (int i = 0; i < (int)words.size(); i++) {
        if (isDigitsOnly(words[i])) {
            digitIndices.push_back(i);
        }
    }

    if (digitIndices.empty()) {
        std::cout << line;
        return 0;
    }

    long long maxVal = -1;
    std::vector<int> maxima;
    for (int idx : digitIndices) {
        long long val = stoll(words[idx]);
        if (val > maxVal) {
            maxVal = val;
            maxima.clear();
            maxima.push_back(idx);
        }
        else if (val == maxVal) {
            maxima.push_back(idx);
        }
    }

    int chosenIndex;
    if (maxima.size() == 1) {
        chosenIndex = maxima[0];
    }
    else {
        chosenIndex = maxima[maxima.size() - 2];
    }

    std::string chosenWord = words[chosenIndex];
    words.erase(words.begin() + chosenIndex);
    words.insert(words.begin(), chosenWord);

    for (size_t i = 0; i < words.size(); i++) {
        std::cout << words[i];
        if (i + 1 < words.size())std::cout << " ";
    }

    return 0;
}
