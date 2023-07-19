#include <fstream>
#include <iostream>

std::pair<int, int> ReadNumber(
    const std::string &text,
    const int startIndex)
{
    int index = startIndex;
    int number = 0;
    while (text.size() > index && text[index] >= '0' && text[index] <= '9')
    {

        number *= 10;
        int currentDigit = text[index] - '0';
        number += currentDigit;
        index += 1;
    }
    return std::make_pair(number, index);
}

int main()
{
    std::ifstream input("../inputs/Day4.txt");
    std::string line;
    int score = 0;
    while (std::getline(input, line))
    {
        auto firstStartInfo = ReadNumber(line, 0);
        auto firstEndInfo = ReadNumber(line, firstStartInfo.second + 1);
        auto secStartInfo = ReadNumber(line, firstEndInfo.second + 1);
        auto secEndInfo = ReadNumber(line, secStartInfo.second + 1);

        int firstStart = firstStartInfo.first;
        int firstEnd = firstEndInfo.first;
        int secStart = secStartInfo.first;
        int secEnd = secEndInfo.first;

        if (firstStart <= secEnd && firstEnd >= secStart)
        {

            score++;
        }

    }
    std::cout << score << std::endl;
}