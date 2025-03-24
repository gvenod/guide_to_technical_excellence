#include <iostream>
#include <string>
#include <cctype> //isdigit
#include <cstdlib> //itoa

//operator overloading, copy constructor, inheritance, templates...


using namespace std;

class Solution {
	int privateVar;
protected:
	int protectedVar;
public:
	int publicVar;
	
	Solution() {//default constructor
		privateVar = 1;
	}
	
	/*Solution(Solution *p) {//copy constructer
		privateVar = p->privateVar;
	}*/
	
	// Copy constructor
	//An initialization list in C++ provides a way to initialize class members directly in the constructor definition, before the constructor body executes. 
    Solution(const Solution& other) : privateVar(other.privateVar) {
        std::cout << "Copy constructor called for " << privateVar << std::endl;
    }

	/*operator overloading*/	
	string operator+ (int c) {
		return "hello " + to_string(c);
	}
	
	void playWithClasses() {
	}
};

/*inheritance*/
class miniSolution : public Solution {
	public:
	string operator- (int c) {
		return "goodbye " + to_string(c);
	}
	
};

int main() {
	Solution sol;
	cout << sol + 5 << endl;
	
	miniSolution mSol;
	cout << mSol - 5 << endl;
	cout << mSol + 5 << endl;
	
    return 0;
}