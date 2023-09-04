#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

std::vector<std::stack<char>> processCrateLines(std::vector<std::string>& cLines)
{
    int colNum = cLines.back().size() / 4 + 1;
    std::vector<std::stack<char>> result(colNum);

    for (int i = cLines.size() - 1; i >= 0; i--) {
        for (size_t j = 0; j < colNum; j++) {
            size_t lineIndex = 1 + j * 4;
            if (cLines[i][lineIndex] != ' ')
                result[j].push(cLines[i][lineIndex]);
        }
    }

    return result;
}

std::vector<std::string> splitString(const std::string& input) {
    std::istringstream iss(input);
    std::string curr;
    std::vector<std::string> result;

    while (std::getline(iss, curr, ' ')) {
        result.push_back(curr);
    }
    return result;
}

int main()
{
    std::ifstream input("../inputs/Day5.txt");
    std::vector<std::string> crateLines;
    std::string line;

    while (std::getline(input, line) && !line.empty())
        crateLines.push_back(line);
    
    crateLines.pop_back();

    auto crateState = processCrateLines(crateLines);

    while (std::getline(input, line)) {
        auto words = splitString(line);
        int numMoves = std::atoi(words[1].c_str());
        int from = std::atoi(words[3].c_str()) - 1;
        int to = std::atoi(words[5].c_str()) - 1;
        std::stack<char> tempStack;

        for (int i = 0; i < numMoves; i++) {
            char prevTop = crateState[from].top();
            crateState[from].pop();
            tempStack.push(prevTop);
        }

        for (int i = 0; i < numMoves; i++) {
            char prevTop = tempStack.top();
            tempStack.pop();
            crateState[to].push(prevTop);
        }
    }

    for (auto& column : crateState)
        std::cout << column.top();
    
    std::cout << std::endl;
}