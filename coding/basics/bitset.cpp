#include <iostream>
#include <bitset>
#include <string>

using namespace std;
#define mask(x) (1<<x)

class Solution {
	public:
		void helloworld() {
			cout << "hello world" << endl;
		}
		
		void printBinary(int val) {
			bitset<8> n = val;
			cout << n.to_string() << endl;
			return;
		}
		
		void setBit(int val, int pos) {
			cout << "setBit"  << endl;
			printBinary(val);
			int res = val | mask(pos);
			printBinary(res);
			return;
		}
		
		void clearBit(int val, int pos) {
			cout << "clearBit"  << endl;
			printBinary(val);
			int res = val & ~mask(pos);
			printBinary(res);
			return;
		}

		void readBit(int val, int pos) {
			cout << "readBit"  << endl;
			printBinary(val);
			int res = val & mask(pos);
			printBinary(res);
			return;
		}		
		
		void invertBit(int val, int pos) {
			cout << "invertBit" << endl;
			printBinary(val);
			int res = val ^ mask(pos);
			printBinary(res);
			return;
		}

		void moveBits(int val, int pos, bool toRight) {
			cout << "moveBits" << endl;
			printBinary(val);
			int res = 0;
			if(toRight) {
				res = val >> pos;
			} else {
				res = val << pos;
			}
			printBinary(res);
			return;
		}
};

int main() {
	Solution sol;
	sol.helloworld();
	
	int inVal = 0xFF, pos = 4;
	sol.printBinary(inVal);
	sol.setBit(inVal, pos);
	sol.clearBit(inVal, pos);
	sol.readBit(inVal, pos);
	sol.invertBit(inVal, pos);
	
	sol.moveBits (inVal, pos, true);
	sol.moveBits (inVal, pos, false);
	
	return 0;
}