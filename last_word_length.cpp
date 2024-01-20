//Given a string s consisting of words and spaces, return the length of the last word in the string.

#include <iostream>
#include <string>

int lengthOfLastWord(const std::string& s) {
    int length = 0;
    bool foundWord = false;

    // Iterate through the string from right to left
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            // Increment the length for each character in the last word
            ++length;
            foundWord = true;
        } else if (foundWord) {
            // Break when a space is encountered after the last word
            break;
        }
    }

    return length;
}

int main() {
    std::string input;

    // Get user input using getline to handle spaces
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Calculate and display the length of the last word
    int result = lengthOfLastWord(input);
    std::cout << "Length of the last word: " << result << std::endl;

    return 0;
}
