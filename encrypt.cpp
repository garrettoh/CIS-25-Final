#include "crypter.h"

// this function takes in a vector of bytes and a key, and encrypts the bytes using XOR operation
// the key is a single character, which is used to XOR each byte in the vector
void encryptXor(vector<byte>& buff, char key){
    for (auto& byte : buff){
        byte ^= key;
    }
}

// this function reads a file into a vector of bytes
// it takes the file path as input and fills the vector with the file's contents
bool readFile(string inputFilePath, vector<byte>& buff){
    std::ifstream input(inputFilePath, std::ios::binary);
    if (!input) {
        std::cerr << "Failed to open file: " << inputFilePath << "\n";
        return false;
    }

    input.seekg(0, std::ios::end);
    std::streamsize size = input.tellg();
    if (size <= 0) {
        std::cerr << "File is empty or tellg failed.\n";
        return false;
    }
    input.seekg(0, std::ios::beg);

    // this resizes the vector to the size of the file
    // and reserves enough space to hold the file's contents
    buff.resize(static_cast<size_t>(size));
    if (!input.read(reinterpret_cast<char*>(buff.data()), size)) {
        std::cerr << "Failed to read file contents.\n";
        return false;
    }

    return true;
}

// this function writes the contents of a vector of bytes to a file
// it takes the output file path and the vector as input
bool writeFile(const std::string& outputFilePath, const std::vector<byte>& buff) {
    std::ofstream output(outputFilePath, std::ios::binary);
    if (!output) {
        std::cerr << "Failed to open file for writing: " << outputFilePath << "\n";
        return false;
    }
// write the contents of the vector to the file
    output.write(reinterpret_cast<const char*>(buff.data()), buff.size());
    if (!output) {
        std::cerr << "Failed to write all data to file.\n";
        return false;
    }

    return true;
}