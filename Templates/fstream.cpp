#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void openAndCloseFiles();
void readFromFiles();
void writeToFiles();
void filePositioning();
void fileOperations();
void advancedTopics();

int main() {
    openAndCloseFiles();
    readFromFiles();
    writeToFiles();
    filePositioning();
    fileOperations();
    advancedTopics();

    cout << "All demonstrations complete." << endl;
    return 0;
}


void openAndCloseFiles() {
    cout << "Opening and closing files demonstration:" << endl;

    // Open a file for writing
    ofstream outFile("Output.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    // Write to the file
    outFile << "Hello, world!" << endl;
    // Close the file
    outFile.close();

    // Open a file for reading
    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string s;
    int a;

    inFile >> s >> a;
    cout << s << " " << a << '\n';
    getline(inFile, s);
    cout << s << '\n';
    // Close the file
    inFile.close();

    cout << "File opened and closed successfully." << endl << endl;
}


void readFromFiles() {
    cout << "Reading from files demonstration:" << endl;

    // Open the file for reading
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the file
    inFile.close();

    cout << "File read successfully." << endl << endl;
}


void writeToFiles() {
    cout << "Writing to files demonstration:" << endl;

    // Open the file for writing
    ofstream outFile("Output.txt", ios::app); // Append mode
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    // Write to the file
    outFile << "Adding another line." << endl;

    // Close the file
    outFile.close();

    cout << "Data written to file successfully." << endl << endl;
}


void filePositioning() {
    cout << "File positioning demonstration:" << endl;

    fstream file("Output.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Move to the beginning of the file
    file.seekg(0, ios::beg); // get
    string line;
    getline(file, line);
    cout << "First line: " << line << endl;

    // Move to the end of the file
    file.seekp(0, ios::end); // put
    file << "End of file line." << endl;

    // Get the current position in the file
    streampos position = file.tellg(); // streampos --> Class , position --> Object from that class
    cout << "Current position for reading: " << position << endl;

    // Close the file
    file.close();

    cout << "File positioning performed successfully." << endl << endl;
}


void fileOperations() {
    cout << "File operations demonstration:" << endl;

    fstream file("Output.txt", ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    // Read a single character from the file
    char ch;
    file.get(ch);
    cout << "First character read: " << ch << endl;

    // Write a single character to the file
    file.put('X'); // === file << 'X';

    // Close the file
    file.close();

    cout << "File operations performed successfully." << endl << endl;
}


void advancedTopics() {
    cout << "Advanced topics demonstration:" << endl;

    // Exception handling with file streams
    fstream file;
    file.exceptions(fstream::failbit | fstream::badbit);

    try {
        file.open("Output.txt", ios::in);
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } catch (fstream::failure& e) {
        cerr << "Exception opening/reading/closing file: " << e.what() << endl;
    }

    cout << "Advanced topics covered successfully." << endl;
}

