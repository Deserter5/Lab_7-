#include <iostream>
#include <vector>
#include <chrono>
#include "sorting.h"
#include "file_utils.h"

int main() {
    int n;
    std::string inputFilename;

    std::cout << "Enter sequence size: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid sequence size." << std::endl;
        return 1;
    }

    std::cout << "Enter input filename: ";
    std::cin >> inputFilename;

    if (!generateRandomFile(inputFilename, n, -100000, 100000)) {
        std::cerr << "Failed to generate input file." << std::endl;
        return 1;
    }
    std::cout << "Random sequence written to: " << inputFilename << std::endl;

    std::vector<int> originalData;
    if (!readArrayFromFile(inputFilename, originalData)) {
        std::cerr << "Failed to read input file." << std::endl;
        return 1;
    }

    std::vector<int> dataForInsertion = originalData;
    std::vector<int> dataForMerge = originalData;

    auto startInsert = std::chrono::high_resolution_clock::now();
    insertionSort(dataForInsertion);
    auto endInsert = std::chrono::high_resolution_clock::now();
    auto durationInsert = std::chrono::duration_cast<std::chrono::microseconds>(endInsert - startInsert).count();

    std::string outputFilename = changeExtension(inputFilename, "sorted");
    if (!writeArrayToFile(outputFilename, dataForInsertion)) {
        std::cerr << "Failed to write sorted file." << std::endl;
        return 1;
    }
    std::cout << "Sorted sequence written to: " << outputFilename << std::endl;

    auto startMerge = std::chrono::high_resolution_clock::now();
    mergeSort(dataForMerge, 0, static_cast<int>(dataForMerge.size()) - 1);
    auto endMerge = std::chrono::high_resolution_clock::now();
    auto durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(endMerge - startMerge).count();

    std::cout << "\nComparison Results:" << std::endl;
    std::cout << "Array size:     " << n << std::endl;
    std::cout << "Insertion Sort: " << durationInsert / 1000.0 << " ms (" << durationInsert << " us)" << std::endl;
    std::cout << "Merge Sort:     " << durationMerge / 1000.0 << " ms (" << durationMerge << " us)" << std::endl;

    return 0;
}