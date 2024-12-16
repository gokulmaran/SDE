#include <iostream>
#include <fstream> // For file handling
#include <string>

int main() {
    // Writing to a file
    std::ofstream outFile("example.txt"); // Open file for writing (output)
    if (!outFile) {  // Check if the file opened successfully
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    outFile << "Hello, this is a sample text in the file!" << std::endl;
    outFile << "C++ file handling is easy to learn." << std::endl;
    outFile.close(); // Close the file after writing

    // Reading from the file
    std::ifstream inFile("example.txt"); // Open file for reading (input)
    if (!inFile) {  // Check if the file opened successfully
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Reading from file:\n";
    while (std::getline(inFile, line)) {  // Read the file line by line
        std::cout << line << std::endl;
    }
    inFile.close(); // Close the file after reading

    return 0;
}
