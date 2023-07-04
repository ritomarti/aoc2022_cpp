#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input("../inputs/Day3.txt");
    std::string line;
    int pointSum = 0;
    while (std::getline(input, line))
    {
        for (size_t i = 0; i < 26; i++)
        {
            bool isContainedInFirst = false;
            bool isContainedInSec = false;
            char currentLetter = i + 'a';
            for (size_t j = 0; j < line.size() / 2; j++)
            {
                if (currentLetter == line[j])
                {
                    isContainedInFirst = true;
                }
            }

            for (size_t j = line.size() / 2; j < line.size(); j++)
            {

                if (currentLetter == line[j])
                {
                    isContainedInSec = true;
                }
            }
            if (isContainedInFirst && isContainedInSec)
            {
                pointSum += i + 1;
            }
        }
        for (size_t i = 0; i < 26; i++)
        {
            bool isContainedInFirst = false;
            bool isContainedInSec = false;
            char currentLetter = i + 'A';
            for (size_t j = 0; j < line.size() / 2; j++)
            {
                if (currentLetter == line[j])
                {
                    isContainedInFirst = true;
                }
            }

            for (size_t j = line.size() / 2; j < line.size(); j++)
            {

                if (currentLetter == line[j])
                {
                    isContainedInSec = true;
                }
            }
            if (isContainedInFirst && isContainedInSec)
            {
                pointSum += i + 27;
            }
        }
    }
    std::cout << pointSum << std::endl;
}