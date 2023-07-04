#include <fstream>
#include <iostream>
#include <algorithm>

uint32_t getCommonLetterScore(
    const char startLetter,
    const uint32_t scoreOffset,
    const std::string &text
) {
    for (size_t i = 0; i < 26; i++)
    {
        char currLetter = startLetter + i;
        bool existsInFirst = text.substr(0, text.size() / 2).find(currLetter) != std::string::npos;
        bool existsInSecond = text.substr(text.size() / 2, text.size() / 2).find(currLetter) != std::string::npos;

        if (existsInFirst && existsInSecond)
        {
            return i + scoreOffset;
        }
    }

    return 0;
}

int main()
{
    std::ifstream input("../inputs/Day3.txt");
    std::string line;
    uint32_t pointSum = 0;

    while (std::getline(input, line))
    {
        pointSum += getCommonLetterScore('a', 1, line);
        pointSum += getCommonLetterScore('A', 27, line);
    }

    std::cout << pointSum << std::endl;
}