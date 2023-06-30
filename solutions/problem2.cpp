#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input("../inputs/Day2.txt");
    std::string line;
    int pointSum = 0;
    while (std::getline(input, line))
    {

        if (line[0] == 'A')
        {
            if (line[2] == 'X')
            {
                pointSum += 0 + 3;
            }
            else if (line[2] == 'Y')
            {
                pointSum += 1 + 3;
            }
            else
            {
                pointSum += 2 + 6;
            }
        }
        if (line[0] == 'B')
        {
            if (line[2] == 'X')
            {
                pointSum += 0+1;
            }
            else if (line[2] == 'Y')
            {
                pointSum += 2+3;
            }
            else
            {
                pointSum += 6+3;
            }
        }
        if (line[0] == 'C')
        {
            if (line[2] == 'X')
            {
                pointSum += 2 + 0;
            }
            else if (line[2] == 'Y')
            {
                pointSum += 3 + 3;
            }
            else
            {
                pointSum += 1 + 6;
            }
        }

        
    }
    std::cout << pointSum << std::endl;
}