#include <iostream>
#include <fstream>
int main()
{
    std::ifstream input("../inputs/Day6.txt");
    std::string line;

    if (!std::getline(input, line) || line.empty())
    {
        std::cout << "Error reading file." << std::endl;
        return 0;
    }

    for (size_t i = 3; i < line.size(); i++)
    {
        char current = line[i];
        char prev1 = line[i - 1];
        char prev2 = line[i - 2];
        char prev3 = line[i - 3];

        if (current == prev1 || prev1 == prev2 || prev2 == prev3 ||
         prev3 == current || current == prev2 || prev1 == prev3)
        {
            continue;
        }

        std::cout<<i+1<<std::endl;
        break;
    }
    return 0;
}