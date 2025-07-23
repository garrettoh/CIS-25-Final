#pragma once 
/*
if you're using linux or mac, you can remove the Windows.h include because we're
not using the Windows API in this codebase as its the Proof of concept
In the full version of this program we would use the windows API to Utilise the program
"Syswhispers3" to generate indirect syscalls to the kernel to bypass EDRs and AVs
*/
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// name definitions
using std::vector;
using std::string;
using std::cout;
using byte = unsigned char;
void showMenu();
void encryptXor(vector<byte>& buff, const char key);
bool readFile(string inputFilePath, vector<byte>& buff);
bool writeFile(const string& outputFilePath, const vector<byte>& buff);