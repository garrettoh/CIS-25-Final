#include "crypter.h"

/*
I heard that using namespace std is bad practice, so I will not use besides using std::cout

super hacker menu display function

took me a while to figure out that 
*/
void showMenu() {
    cout << "                            _ ____ ____  _   \n";
    cout << "                           | |___ \\___ \\| |  \n";
    cout << "  ___ _   _ _ __   ___ _ __| | __) |__) | |_ \n";
    cout << " / __| | | | '_ \\ / _ \\ '__| ||__ <|__ <| __|\n";
    cout << " \\__ \\ |_| | |_) |  __/ |  | |___) |__) | |_ \n";
    cout << " |___/\\__,_| .__/ \\___|_|  |_|____/____/ \\__|\n";
    cout << "           | |                               \n";
    cout << "           |_|                               \n";
    cout << "\n\nUsage cryptojockey path/to/file/to/encrypt , key";
}

int main(int argc, char* argv[]) {
    showMenu();
    // if there are not exactly 3 arguments, exit
    if (argc != 3) {
        cout << "Usage: cryptojockey <path/to/file> <key>\n";
        return 1;
    }

    string filePath = argv[1];
    char key = argv[2][0]; 
    vector<byte> buff;
    // check if the file exists and can be read
    if (!readFile(filePath, buff)) {
        std::cerr << " Could not read file.\n";
        return 1;
    }
    else {
        cout << " File was read successfully.\n";
    }
    // displays output to user.  
    cout << " Buffer size: " << buff.size() << " bytes\n";
    cout << " Encrypting file: " << filePath << " with key '" << key << "'\n";

    encryptXor(buff, key);


    // check for file IO errors
    // writes the encrypted buff to the new file output.enc
    if (!writeFile("output.enc", buff)) {
        std::cerr << " Could not write output file.\n";
        return 1;
    }
    else {
        cout << " Encrypted file written as: output.enc\n";
    }

    return 0;
}
