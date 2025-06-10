#include "FileHandler.h"

bool FileHandler::saveToFile(const std::string& filename, const std::vector<int>& numbers) {
    std::ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        return false;
    }
    
    for (const auto& number : numbers) {
        outFile << number << std::endl;
    }
    
    outFile.close();
    return true;
}