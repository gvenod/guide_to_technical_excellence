#include <iostream>
#include <string>
#include <algorithm>

int text_manipulation() {
    // Concatenation
    std::string str1 = "Hello";
    std::string str2 = " World";
    std::string result = str1 + str2;
    std::cout << "Concatenation: " << result << std::endl; // Output: Hello World

    // Substring
    std::string longString = "This is a longer string";
    std::string sub = longString.substr(0, 4); // Extract "This"
    std::cout << "Substring: " << sub << std::endl; // Output: This

    // Find
    size_t found = longString.find("longer");
    if (found != std::string::npos) {
        std::cout << "Found 'longer' at: " << found << std::endl; // Output: Found 'longer' at: 10
    }

   // Replace
    std::string replaceString = "Replace example";
    replaceString.replace(0, 7, "New"); // Replace "Replace" with "New"
    std::cout << "Replace: " << replaceString << std::endl; // Output: New example

    // Erase
    std::string eraseString = "Erase example";
    eraseString.erase(6, 7); // Erase "example"
    std.cout << "Erase: " << eraseString << std::endl; // Output: Erase 

    // Length
    std::cout << "Length of '" << result << "': " << result.length() << std::endl; // Output: Length of 'Hello World': 11

    // Iterating
    std::string iterateString = "Iterate";
    std::cout << "Iterating: ";
    for (char c : iterateString) {
        std::cout << c << " "; // Output: I t e r a t e
    }
    std::cout << std::endl;

    //Transform
    std::string transformString = "Transform";
    std::transform(transformString.begin(), transformString.end(), transformString.begin(), ::tolower);
    std::cout << "Transform to lower case: " << transformString << std::endl; // Output: transform

    return 0;
}

int part2() {
    std::string str = "This is a test string";

    // 1. Find and replace
    std::string find_str = "test";
    std::string replace_str = "sample";
    size_t pos = str.find(find_str);
    if (pos != std::string::npos) {
        str.replace(pos, find_str.length(), replace_str);
    }
    std::cout << "After replace: " << str << std::endl;

    // 2. Substring extraction with error handling
    size_t start_pos = 5;
    size_t length = 20;
    if (start_pos + length <= str.length()) {
         std::string sub_str = str.substr(start_pos, length);
         std::cout << "Substring: " << sub_str << std::endl;
    } else {
        std::cout << "Invalid substring range" << std::endl;
    }

    // 3. String concatenation with different data types
    std::string str1 = "The number is ";
    int num = 42;
    std::string str2 = str1 + std::to_string(num);
    std::cout << "Concatenated string: " << str2 << std::endl;

    // 4. Removing characters from a string
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::cout << "String after removing spaces: " << str << std::endl;

    // 5. Case-insensitive string comparison
    std::string str3 = "Hello";
    std::string str4 = "hello";
    if (std::equal(str3.begin(), str3.end(), str4.begin(),
                   [](char a, char b){
                       return std::tolower(a) == std::tolower(b);
                   })) {
        std::cout << "Strings are equal (case-insensitive)" << std::endl;
    } else {
        std::cout << "Strings are not equal (case-insensitive)" << std::endl;
    }

    return 0;
}

int main() {
    std::string str = "Hello";
	
	//index based loop
    for (size_t i = 0; i < str.length(); ++i) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
	
	//range based loop
	for (char c : str) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
	
	//iterator based
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;	
	
	//while loop
	size_t index = 0;
    while (index < str.length()) {
        std::cout << str[index] << " ";
        index++;
    }
    std::cout << std::endl;
    return 0;
}

