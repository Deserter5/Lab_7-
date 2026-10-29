#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

std::string changeExtension(const std::string& filename, const std::string& newExt);
bool generateRandomFile(const std::string& filename, int count, int minVal, int maxVal);
bool readArrayFromFile(const std::string& filename, std::vector<int>& arr);
bool writeArrayToFile(const std::string& filename, const std::vector<int>& arr);

#endif