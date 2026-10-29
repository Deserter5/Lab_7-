#include "file_utils.h"
#include <fstream>
#include <random>

std::string changeExtension(const std::string& filename, const std::string& newExt) {
    size_t lastDot = filename.find_last_of(".");
    if (lastDot == std::string::npos) {
        return filename + "." + newExt;
    }
    return filename.substr(0, lastDot) + "." + newExt;
}

bool generateRandomFile(const std::string& filename, int count, int minVal, int maxVal) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    for (int i = 0; i < count; ++i) {
        outFile << dist(gen) << (i == count - 1 ? "" : " ");
    }
    return true;
}

bool readArrayFromFile(const std::string& filename, std::vector<int>& arr) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }

    int value;
    arr.clear();
    while (inFile >> value) {
        arr.push_back(value);
    }
    return true;
}

bool writeArrayToFile(const std::string& filename, const std::vector<int>& arr) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        outFile << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    return true;
}