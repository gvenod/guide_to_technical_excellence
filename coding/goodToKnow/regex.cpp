/*
basic regex operations 
	searching, 
	matching multiple occurrences, 
	using character classes and capture groups, and 
	replacing text.
	
	special chars: .[{()\^$|?*+  use escape character to use it literally. \.

	^ Matches the start of the string, 	$ Matches the end of the string, \d matches whole number or digit (0–9); \w alpha-numeric character. \W - non alpha numeric character, \s - white space/tab \S - non white space *, + and { } are called repeaters [ * - 0 or more times; ? - 0 or 1 time, + - atleast 1 or more, dot is a wildcard, | - OR alternation]
		^\d{3} or ^\d\d\d will match like :453" and \d{3}$  will match with patterns like "113" in "453-113". 
		{n,m}: Matches when the preceding character, or character group, occurs at least n times, and at most m times.
		\D Reverse of \d. Matches anything except digits. \D\D = AB
	[] is used to indicate a set/range of characters
		[A-Z] will match any uppercase ASCII letter; [0–9] will match any digit from 0 to 9; [0-3][0-3] will match all the two-digits numbers from 00 to 33; [0-9A-Fa-f] will match any hexadecimal digit.		
	A character group is indicated by () matches the characters in exact order.
		[(+*)] will match any of the literal characters '(', '+', '*', or ')' because they lose their special meaning inside sets.
	
	Email : ^([a-zA-Z0–9_\-\.]+)@([a-zA-Z0–9_\-\.]+)\.([a-zA-Z]{2,5})$
	URL: https?://(www\.)?(\w+)(\.\w+)
	
*/

#include <iostream>
#include <string>
#include <regex>

int main() {
    // Example 1: Matching a simple pattern
    std::string text1 = "The quick brown fox jumps over the lazy dog.";
    std::regex pattern1("fox");
    std::smatch match1;

    if (std::regex_search(text1, match1, pattern1)) {
        std::cout << "Match found: " << match1.str() << std::endl; // Output: Match found: fox
    } else {
        std::cout << "Match not found." << std::endl;
    }

    // Example 2: Matching multiple occurrences
    std::string text2 = "apple banana apple orange apple";
    std::regex pattern2("apple");
    std::smatch match2;
    std::string::const_iterator searchStart(text2.cbegin());

    while (std::regex_search(searchStart, text2.cend(), match2, pattern2)) {
        std::cout << "Match found: " << match2.str() << " at position " << match2.position() << std::endl;
        searchStart = match2.suffix().first;
    }
    // Output:
    // Match found: apple at position 0
    // Match found: apple at position 13
    // Match found: apple at position 27

    // Example 3: Using character classes
    std::string text3 = "Date: 2025-03-22";
    std::regex pattern3("\\d{4}-\\d{2}-	\\d{2}"); // Matches date in YYYY-MM-DD format
    std::smatch match3;

    if (std::regex_search(text3, match3, pattern3)) {
        std::cout << "Date found: " << match3.str() << std::endl; // Output: Date found: 2025-03-22
    } else {
        std::cout << "Date not found." << std::endl;
    }

    // Example 4: Using capture groups
    std::string text4 = "Name: John, Age: 30";
    std::regex pattern4("Name: (\\w+), Age: (\\d+)");
    std::smatch match4;

    if (std::regex_search(text4, match4, pattern4)) {
        std::cout << "Name: " << match4[1].str() << ", Age: " << match4[2].str() << std::endl;
        // Output: Name: John, Age: 30
    } else {
        std::cout << "Information not found." << std::endl;
    }

     // Example 5: Replacing text using regex
    std::string text5 = "The cat sat on the mat.";
    std::regex pattern5("cat");
    std::string replacement = "dog";
    std::string new_text = std::regex_replace(text5, pattern5, replacement);
    std::cout << new_text << std::endl; // Output: The dog sat on the mat.

    return 0;
}