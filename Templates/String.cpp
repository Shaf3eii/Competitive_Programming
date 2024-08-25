#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// 1. Creation and initialization
void stringInitialization()
{
    string str1 = "Hello"; // Way 1
    string str2("World");  // Way 2

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
}

// 2. Length-related functions
void lengthRelatedFunctions() {
    cout << "\n2. Length-related functions:\n";
    string str = "Hello";

    cout << "Length of string: " << str.length() << endl;
    cout << "Length of string using size(): " << str.size() << endl;
    cout << "Is string empty? " << (str.empty() ? "Yes" : "No") << endl;
}

// 3. Element access functions
void elementAccessFunctions() {
    cout << "\n3. Element access functions:\n";
    string str = "Hello";
    // operator[]
    cout << "Character at index 1: " << str[1] << endl;
    // at()
    cout << "Character at index 3 using at(): " << str.at(3) << endl;
}

// 4. Capacity functions
void capacityFunctions() {
    cout << "\n4. Capacity functions:\n";
    string str = "Hello";
    // capacity()
    cout << "Capacity of string: " << str.capacity() << endl;
    // reserve()
    str.reserve(20);
    cout << "Capacity after reserve(20): " << str.capacity() << endl;
}

// 5. Modifying functions
void modifyingFunctions() {
    cout << "\n5. Modifying functions:\n";
    string str = "Hello";

    // Clear the string
    str.clear();
    cout << "String after clear(): " << str << endl;

    // Append 'H' and 'I' to the string
    str.push_back('H');
    str.push_back('I');
    cout << "String after push_back('H'): " << str << endl;

    // Remove the last character from the string
    str.pop_back();
    cout << "String after pop_back(): " << str << endl;

    // Insert 'i' at index 1 in the string
    str.insert(1, "i");
    cout << "String after insert(1, 'i'): " << str << endl;

    // Erase one character at index 1 from the string
    str.erase(1, 1);
    cout << "String after erase(1, 1): " << str << endl;

    // Replace one character at index 1 with 'e' in the string
    str.replace(1, 1, "e");
    cout << "String after replace(1, 1, 'e'): " << str << endl;

    // Append " World" to the string
    str.append(" World");
    cout << "String after append(' World'): " << str << endl;

    // Extract a substring starting from index 6 with length 5 from the string
    string substring = str.substr(6, 5);
    cout << "Substring from index 6 with length 5: " << substring << endl;

    // Resize the string to length 5
    str.resize(5);
    cout << "String after resize(5): " << str << endl;
}

// 6. String operations
void stringOperations() {
    cout << "\n6. String operations:\n";
    string str = "Hello";

    // Get a pointer to a constant character array representing the string
    const char* cstr = str.c_str();
    cout << "c_str(): " << cstr << endl;

    // Find the index of the first occurrence of "el" in the string
    int found = str.find("el");
    cout << "Index of 'el': " << found << endl;

    // Find the index of the last occurrence of 'l' in the string
    int rfound = str.rfind("l");
    cout << "Index of last 'l': " << rfound << endl;

    // Find the index of the first occurrence of 'a' or 'e' or 'i' or 'e' or 'u' in the string
    int found_first_of = str.find_first_of("aeiou");
    cout << "Index of first occurrence of vowel character: " << found_first_of << endl;

    // Find the index of the last occurrence of ....
    int found_last_of = str.find_last_of("aeiou");
    cout << "Index of last occurrence of vowel character: " << found_last_of << endl;

    // Find the index of the first character not 'H' or 'e' in the string
    int found_first_not_of = str.find_first_not_of("He");
    cout << "Index of first character not 'H' or 'e': " << found_first_not_of << endl;

    // Find the index of the last character not 'l' or 'o' in the string
    int found_last_not_of = str.find_last_not_of("lo");
    cout << "Index of last character not 'l' or 'o': " << found_last_not_of << endl;

    // Compare the string with another string ("Hello")
    string str2 = "Hello";
    int comp = str.compare(str2);
    cout << "Comparison result with 'Hello': " << comp << endl;
}

// 7. String comparison functions
void stringComparisonFunctions() {
    cout << "\n7. String comparison functions:\n";
    string str1 = "Hello";
    string str2 = "World";

    // Check if strings are equal or not
    cout << "Are strings equal? " << (str1 == str2 ? "Yes" : "No") << endl;
    cout << "Are strings not equal? " << (str1 != str2 ? "Yes" : "No") << endl;

    // Compare strings lexicographically
    cout << "Is str1 less than str2? " << (str1 < str2 ? "Yes" : "No") << endl;
    cout << "Is str1 less than or equal to str2? " << (str1 <= str2 ? "Yes" : "No") << endl;
    cout << "Is str1 greater than str2? " << (str1 > str2 ? "Yes" : "No") << endl;
    cout << "Is str1 greater than or equal to str2? " << (str1 >= str2 ? "Yes" : "No") << endl;
}

// 8. String transformation functions
void stringTransformationFunctions() {
    cout << "\n8. String transformation functions:\n";
    string str = "hello";

    // Convert string to uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase string: " << str << endl;

    // Convert string to lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lowercase string: " << str << endl;
}

// 9. String formatting functions
void stringFormattingFunctions() {
    cout << "\n9. String formatting functions:\n";
    // Convert numerical values to strings
    int num = 123;
    string str = to_string(num);
    cout << "String representation of " << num << ": " << str << endl;

    // Convert strings to integers
    string str_num = "456";
    int parsed_int = stoi(str_num);
    cout << "Parsed integer from string: " << parsed_int << endl;
}

// 10. String manipulation functions
void stringManipulationFunctions() {
    cout << "\n10. String manipulation functions:\n";
    string str;

    // Read a line of text from input stream into a string
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "You entered: " << str << endl;
}

// 11. String copying functions
void stringCopyingFunctions() {
    cout << "\n11. String copying functions:\n";
    string str1 = "Hello, ";
    string str2 = "World!";

    // Copy part of one string to another string
    char buffer[20];
    copy(str1.begin(), str1.end(), buffer);
    copy(str2.begin(), str2.end(), buffer + str1.size());
    buffer[str1.size() + str2.size()] = '\0';
    cout << "Copied string: " << buffer << endl;
}

// 12. string streaming
int count_how_many_words() {
    // Breaking input into word
    // using string stream
    string str = "String streaming to count how many words.";
    // Used for breaking words
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

int main() {
    stringInitialization();
    lengthRelatedFunctions();
    elementAccessFunctions();
    capacityFunctions();
    modifyingFunctions();
    stringOperations();
    stringComparisonFunctions();
    stringTransformationFunctions();
    stringFormattingFunctions();
    stringManipulationFunctions();
    stringCopyingFunctions();
    count_how_many_words();
    return 0;
}
