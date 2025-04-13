#include <iostream>
#include <cmath>
#include <numeric> // For std::gcd

/*
GCD Function:
The gcd(a, b) function calculates the greatest common divisor of two integers using the Euclidean algorithm.
- The algorithm finds the GCD of two numbers, 'a' and 'b', by repeatedly dividing the larger number by the smaller number and taking the remainder until the remainder is zero. 
1. Divide: Divide the larger number (a) by the smaller number (b) and find the remainder (r). 
2. Replace: Replace the larger number (a) with the smaller number (b), and the smaller number (b) with the remainder (r). 
3. Repeat: Repeat steps 1 and 2 until the remainder is zero. 
4. Result: The last non-zero divisor is the GCD of the original numbers. 

LCM Function:
The lcm(a, b) function calculates the least common multiple using the formula: LCM(a, b) = (a * b) / GCD(a, b).
*/

using namespace std;

/*print factors of given number*/
class Solution {
public:

// Function to calculate the GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the LCM (Least Common Multiple)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

//factors 
	void printFactors(int n) {
		cout << "Factors of " << n << " are: ";
		for (int i = 1; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				if (n / i == i)
					cout << i << " ";
				else
				   cout << i << " " << n / i << " ";
			}
		}
		cout << endl;
	}
};

int main() {
	Solution sol;
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    sol.printFactors(num);
	
	int num1, num2;

    // Get input from the user
    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    // Calculate and display the LCM
    int result = sol.lcm(num1, num2);
    std::cout << "The LCM of " << num1 << " and " << num2 << " is: " << result << std::endl;
	
	
    return 0;
}