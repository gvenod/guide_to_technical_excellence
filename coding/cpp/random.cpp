
/*
The srand() function changes the “seed” or the starting point of the algorithm.
seed: Integer used to initialize the random number generator.
*/

#include <iostream>
#include <cstdlib> //rand
#include <limits> //numeric_limits
#include <cmath> //infinity macro

using namespace std;

int main() {

    // Use current time as seed for random generator
    srand(time(0));

    // rand() -> It will generate random numbers in the range [0, RAND_MAX) where RAND_MAX is a constant whose default value may vary but is granted to be at least 32767. 
    for (int i = 0; i < 3; i++)
        cout << rand() << " ";
	
	double positive_infinity = std::numeric_limits<double>::infinity();
	float negative_infinity = -std::numeric_limits<float>::infinity();
	
	double pos_infinity = INFINITY;
	double neg_infinity = -INFINITY;
	
	/*adding 1 to max_int will result in integer overflow, wrapping around to the minimum value.*/
	int max_int = std::numeric_limits<int>::max();
	int min_int = std::numeric_limits<int>::min();

	cout << "Positive infinity: " << positive_infinity << " : " << pos_infinity << " : " << max_int << endl;
	cout << "Negative infinity: " << negative_infinity << " : " << neg_infinity << " : " << min_int <<endl;

    return 0;
}

