# The program

This project is a C++ program that processes text files to identify and list URLs and words along with the line numbers on which they appear.
The results are outputted to a file named `rezultatai.txt`.

## Features
- Lists all `.txt` files in the current directory for the user to choose from.
- Reads the chosen file and all existing extracts URLs.
- Identifies and normalizes words, ignoring numbers and special characters (Uses `regex`).
- Outputs the results to a file, displaying each word, its frequency, and the lines on which it appears and all the URL's ang the total count.

## File Structure
```
.
├── Makefile
├── main.cpp
├── funkcijos.cpp
├── funkcijos.h
└── mylib.h
```


## Dependencies
- C++17
- Standard C++ Libraries

## Compilation

To compile the project, use the provided `Makefile`. In your terminal, navigate to the project directory and run:
```
make
```
This will produce an executable named `my_program`.

## Running the Program
After compiling, you can run the program using:
```
./my_program
```
The program will prompt you to select a .txt file from the current directory to process.

## Cleaning Up
To remove the compiled files and clean the directory, use:
```
make clean
```

## Code Overview
### main.cpp
The `main.cpp` file contains the main function that initializes the program, handles user input, and calls functions to process the file.

### funkcijos.cpp
Contains the implementations of the following functions:

- getFileChoice(): Lists available .txt files and gets the user's choice.
- canOpen(const string& fileChoice): Checks if a file can be opened successfully.
- isURL(const string& zodis): Checks if a string is a valid URL.
- fixWords(const string& zodis): Normalizes a word by removing non-alphanumeric characters and converting to lowercase.
- addToTheList(const string& zodis, map<string, vector<int>>& sarasas, int eilutesNumeris): Adds a word to the list along with its line number.
- readFile(const string& fileChoice, map<string, vector<int>>& sarasas, vector<string>& urls): Reads the file and populates the word list and URL list.
- output(map<string, vector<int>>& sarasas, vector<string> urls): Outputs the results to rezultatai.txt.

### funkcijos.h
Header file for `funkcijos.cpp`. Declares all the functions defined in funkcijos.cpp.

### mylib.h
Includes necessary libraries and sets up common namespaces. Used by both `main.cpp` and `funkcijos.cpp`.

## Example Usage
1. Run the program:
```
./my_program
```

2. Select a .txt file from the list.

Wait for the program to process the file.

Check the rezultatai.txt file for the output.
