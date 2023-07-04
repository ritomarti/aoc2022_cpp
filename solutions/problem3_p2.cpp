#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input("../inputs/Day3.txt");
    std::string line;
    std::string bufferLine1;
    std::string bufferLine2;
    std::string bufferLine3;
    int pointSum = 0;
    while (std::getline(input, line))
    {
        bufferLine3 = bufferLine2;
        bufferLine2 = bufferLine1;
        bufferLine1 = line;

        if (bufferLine3.empty())
        {
            continue;
        }

        for (size_t i = 0; i < 26; i++)
        {
            bool isContainedInFirst = false;
            bool isContainedInSec = false;
            bool isContainedInThird = false;
            char currentLetter = i + 'a';
            for (size_t j = 0; j < bufferLine1.size(); j++)
            {
                if (currentLetter == bufferLine1[j])
                {
                    isContainedInFirst = true;
                }
            }

            for (size_t j = 0; j < bufferLine2.size(); j++)
            {

                if (currentLetter == bufferLine2[j])
                {
                    isContainedInSec = true;
                }
            }
            for (size_t j = 0; j < bufferLine3.size(); j++)
            {

                if (currentLetter == bufferLine3[j])
                {
                    isContainedInThird = true;
                }
            }
            if (isContainedInFirst && isContainedInSec && isContainedInThird)
            {
                pointSum += i + 1;
            }
        }
        for (size_t i = 0; i < 26; i++)
        {
            bool isContainedInFirst = false;
            bool isContainedInSec = false;
            bool isContainedInThird = false;
            char currentLetter = i + 'A';
            for (size_t j = 0; j < bufferLine1.size(); j++)
            {
                if (currentLetter == bufferLine1[j])
                {
                    isContainedInFirst = true;
                }
            }

            for (size_t j = 0; j < bufferLine2.size(); j++)
            {

                if (currentLetter == bufferLine2[j])
                {
                    isContainedInSec = true;
                }
            }
            for (size_t j = 0; j < bufferLine3.size(); j++)
            {

                if (currentLetter == bufferLine3[j])
                {
                    isContainedInThird = true;
                }
            }
            if (isContainedInFirst && isContainedInSec && isContainedInThird)
            {
                pointSum += i + 27;
            }
        }
        bufferLine1.clear();
        bufferLine2.clear();
        bufferLine3.clear();
    }
    std::cout << pointSum << std::endl;
}