#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

using namespace std;

// Used to create a file for testing purposes
void createFile(string fn);

int main() {
    // Let's create a file for test purposes
    // createFile("myfile.txt");

    // (i) Open for read
    string fn = "myfile.txt";
    ifstream inputStream;
    inputStream.open(fn);
    if (!inputStream.is_open()) {
        cerr << "Cannot open file " << fn << endl;
        return -1;
    }

    // (ii) Read line-by-line (separated by newline)
    string nextLine;
    string allLines;

    // Use a loop to read all lines
    while (getline(inputStream, nextLine) && !inputStream.eof()) {
        // Display the line that was just read
        cout << "Read in the line: " << nextLine << endl;

        // Append the line to allLines string
        allLines += nextLine + "\n";
    }

    // Check if the last read found an EOF marker
    if (inputStream.eof()) {
        cout << "The last read found an EOF marker" << endl;
    }
    else if (inputStream.fail()) {
        cout << "Failed to read a line." << endl;
    }

    // End of solution
    cout << endl
        << "Complete String: " << endl
        << allLines << endl;

    // (iii) Close the file
    inputStream.close();

    return 0;
}

void createFile(string fn) {
    // (i) Open for write
    ofstream outputStream;
    outputStream.open(fn);
    if (!outputStream.is_open()) {
        cerr << "Cannot create file" << endl;
        throw std::runtime_error("Cannot create " + fn);
    }

    // (ii) Stream characters
    outputStream << "Hello COMP1000" << endl
        << "--------------" << endl;
    outputStream << "Subject Area: " << "COMP" << endl;
    outputStream << "Module ID: " << 1000 << endl;

    // (iii) Close
    outputStream.close();
}