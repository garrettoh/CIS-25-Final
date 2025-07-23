# CryptoJockey – Simple XOR File Crypter

**CryptoJockey** is a lightweight C++ tool for XOR-based file encryption and decryption. It uses a single-character key to obfuscate binary data. It's meant for educational use, demonstrating symmetric encryption and basic file I/O.

---
## [Demo **Youtube Video**](https://youtu.be/SFkYGKxSgLM)

## Project Overview

This project consists of:

- `main.cpp` — User interface and application logic
- `crypter.cpp` — Core functions for encryption and file I/O
- `crypter.h` — Header file with declarations and type definitions

---

## Features

- XOR encryption with single-character key
- Works on binary files
- Decryption is just re-running encryption with the same key
- ASCII art
- Signature evasion
- Since this is a PoC the EXE will not be runnable even if you change the extension to EXE (that's because I'm encrypting the entire file, including the PE header)
---

##  How to Use
> Make sure that the key is only one character
```bash
cryptojockey <path/to/file> <key>

```
---

## Test area
The key is "n" if you would like to decrypt the output.enc and see that there is no difference in the x32dbg.exe 
