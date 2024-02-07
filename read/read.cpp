// read.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <filesystem>  // C++17 feature

// Function to generate a random integer (either 0 or 1)
int generateRandomInteger() {
    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());

    // Uniform distribution between 0 and 1
    std::uniform_int_distribution<int> dis(0, 1);

    // Generate and return a random integer (either 0 or 1)
    return dis(gen);
}

int main(int argc, char* argv[])
{
    std::cout << "Read v2.0\n";

    // Generate a random integer (either 0 or 1)
    int randomValue = generateRandomInteger();

    std::filesystem::path executablePath = std::filesystem::canonical(std::filesystem::path(argv[0]));
    std::filesystem::path wordRandomizerPath = executablePath.parent_path() / "WordRandomizer.exe";
    std::filesystem::path htmlMakerPath = executablePath.parent_path() / "HTML_maker.exe";
    // Full paths to the executables

    // Run different executables based on the random value
    if (randomValue == 1) {
        // If randomValue is 1, run WordRandomizer.exe
        std::system(wordRandomizerPath.string().c_str());
    }
    else {
        // If randomValue is 0, run HTML_maker.exe
        std::system(htmlMakerPath.string().c_str());
    }

    return 0;
}