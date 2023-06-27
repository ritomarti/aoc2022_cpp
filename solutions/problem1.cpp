#include <fstream>
#include <iostream>

int main()
{
    std::ifstream input("../inputs/Day1.txt");
    std::string line;
    int maxCalorie1 = 0;
    int maxCalorie2 = 0;
    int maxCalorie3 = 0;
    int caloriesSum = 0;

    while (std::getline(input, line))
    {
        if (!line.empty())
        {
            int currCalories = std::stoi(line);
            caloriesSum += currCalories;
        }
        else
        {
            if (maxCalorie1 < caloriesSum)
            {
                maxCalorie3 = maxCalorie2;
                maxCalorie2 = maxCalorie1;
                maxCalorie1 = caloriesSum;
            }
            else if (maxCalorie2 < caloriesSum)
            {

                maxCalorie3 = maxCalorie2;
                maxCalorie2 = caloriesSum;
            }
            else if (maxCalorie3 < caloriesSum)
            {
                maxCalorie3 = caloriesSum;
            }

            caloriesSum = 0;
        }
    }
    if (maxCalorie1 < caloriesSum)
    {
        maxCalorie3 = maxCalorie2;
        maxCalorie2 = maxCalorie1;
        maxCalorie1 = caloriesSum;
    }
    else if (maxCalorie2 < caloriesSum)
    {

        maxCalorie3 = maxCalorie2;
        maxCalorie2 = caloriesSum;
    }
    else if (maxCalorie3 < caloriesSum)
    {
        maxCalorie3 = caloriesSum;
    }

    std::cout << maxCalorie1+maxCalorie2+maxCalorie3 << std::endl;
}
