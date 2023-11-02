#include <iostream>
#include <fstream>
#include <vector>
#include <map>
int main()
{
    std::ifstream input("../inputs/Day6.txt");
    std::string line;

    if (!std::getline(input, line) || line.empty())
    {
        std::cout << "Error reading file." << std::endl;
        return 0;
    }

    for (size_t i = 13; i < line.size(); i++)
    {
        std::map<char,bool>seen;
        bool isSolution=true;
        for (size_t j = 0; j < 14; j++)
        {
            if(seen.count(line[i-j])==1)
            {
                isSolution=false;
                break;
            }
            else
            {
                seen[line[i-j]]=true;
            }

        }
        if(!isSolution){
            continue;
        }
        
        std::cout<<i+1<<std::endl;
        break;
    }
    return 0;
}