/*
C++ I/O manipulation involves using manipulators to control the format and behavior of input and output streams. 

These manipulators are functions or objects that can be inserted into or extracted from streams using the insertion << and extraction >> operators. They provide a way to modify the state of the stream, such as setting the precision of floating-point numbers, adjusting the width of output fields, or changing the base of numerical values. Manipulators can be categorized into those with and without arguments.

Manipulators without arguments
	std::endl: Inserts a new line character and flushes the output stream.
	std::flush: Flushes the output stream.
	std::ws: Consumes leading whitespace from an input stream.
	std::dec, std::hex, std::oct: Sets the base for integer I/O to decimal, hexadecimal, or octal, respectively.
	std::showpos, std::noshowpos: Controls whether to display the plus sign for positive numbers.
	std::left, std::right, std::internal: Adjusts the alignment of output fields.
	std::fixed, std::scientific: Changes the formatting of floating-point I/O.
Manipulators with arguments
	std::setw(int n): Sets the width of the next output field to n characters. Defined in <iomanip>.
	std::setfill(char c): Sets the fill character for padding output fields to c. Defined in <iomanip>.
	std::setprecision(int n): Sets the precision of floating-point numbers to n decimal places. Defined in <iomanip>.
	std::setbase(int base): Sets the base for integer I/O (e.g., 10 for decimal, 16 for hexadecimal). Defined in <iomanip>.
	std::resetiosflags(std::ios_base::fmtflags mask): Clears the specified format flags. Defined in <iomanip>.
	std::setiosflags(std::ios_base::fmtflags mask): Sets the specified format flags. Defined in <iomanip>.
*/

#include <iostream>
#include <iomanip>

int main() {
  int num = 255;
  double pi = 3.14159265359;
  std::string text = "Hello";
  
  // Using manipulators for output formatting
  std::cout << "Decimal: " << num << std::endl;
  std::cout << "Hexadecimal: " << std::hex << num << std::endl;
  std.cout << "Octal: " << std::oct << num << std::endl;
  std::cout << std::dec; // Reset to decimal

  std::cout << "Default precision: " << pi << std::endl;
  std::cout << "Precision 3: " << std::setprecision(3) << pi << std::endl;
  std::cout << "Fixed precision: " << std::fixed << std::setprecision(6) << pi << std::endl;
  std::cout << "Scientific notation: " << std::scientific << pi << std::endl;

  std::cout << std::setw(10) << std::setfill('*') << std::left << text << std::endl;
  std::cout << std::setw(10) << std::right << text << std::endl;

  return 0;
}

