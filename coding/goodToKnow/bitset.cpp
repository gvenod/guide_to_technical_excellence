#include <iostream>
#include <bitset> // a = "1011", set(1), clear(3), reset, flag
#include <string>

/* 	
	& 	-Bitwise AND
	| 	-Bitwise OR
	^ 	-Bitwise XOR
	>>= -Binary Right shift and assign
	<<= -Binary Left shift and assign
	&= 	-Assign the value of bitwise AND to the first bitset.
	|= 	-Assign the value of bitwise OR to the first bitset.
	^= 	-Assign the value of bitwise XOR to the first bitset.
	~ 	-Bitwise NOT
*/

//given value and position
// 1. set a bit - create a mask. do OR. 1 OR 0 -> 1
// 2. clear a bit  - create a mask. do bitwise not. do AND. ~1 = 0 AND 0 -> 0.
// 3. read a bit - create a mask. do AND. 1 AND 0 -> 1.



using namespace std;
#define mask(x) (1<<x)

class Solution {
	public:

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
		
		std::string hexToBinary(const std::string& hexString) {
			std::string binaryString = "";
			for (char hexChar : hexString) {
				int decimalValue;
				if (hexChar >= '0' && hexChar <= '9') {
					decimalValue = hexChar - '0';
				} else if (hexChar >= 'A' && hexChar <= 'F') {
					decimalValue = hexChar - 'A' + 10;
				} else if (hexChar >= 'a' && hexChar <= 'f') {
					 decimalValue = hexChar - 'a' + 10;
				} else {
					return "";
				}
				
				std::string binaryFragment = "";
				for (int i = 3; i >= 0; --i) {
					binaryFragment += ((decimalValue >> i) & 1) ? '1' : '0';
				}
				binaryString += binaryFragment;
			}
			return binaryString;
		}
		
		void hexToBinary(string hexArray) {
			map<char, string> hexlookup = {{'0', "0000"}, {'A', "1011"}, {'F', "1111"}};
			hexArray.toupper();
			
			string saBinary;
			for (int i =0; i < hexArray.length(); i++) {
				if((hexArray[i] >= '0' && hexArray[i] <= '9') || ( hexArray[i] >= 'A' && hexArray[i] <= 'F')) {
					saBinary += hexlookup[hexArray[i]];
				}
			}
			
			cout << "hex = " << hexArray << " binary = "<< saBinary << endl;	
		}
		
		int hexToDecimal(string hexArray) {
			long long decimalVal= 0;
			for (int i =0; i < len(hexArray); i++) {
				decimal += (hexArray[i] - 'A' + 10)
			}
			return 0;
		}
		
		int decimalToOctal(int dVal) {
			int oVal, pos = 1;
			while (dVal != 0) {
				oVal = (dVal % 8) * pos; 
				dVal = dVal/8;
				pos *= 10;//move pos
			}
			return oVal;
		}
		
		int decimalToHex(int dVal) {
			int hVal, pos = 1;
			while (dVal != 0) {
				hVal = (dVal % 16) * pos; 
				dVal = dVal/16;
				pos *= 10;//move pos
			}
			return hVal;
		}
};

int main() {
	Solution sol;
	
	struct stBitVariables {
		unsigned int mode : 4;
		unsigned int freq : 4;
	};
		
	int inVal = 0xFF, pos = 4;
	sol.printBinary(inVal);

	sol.setBit(inVal, pos);
	sol.clearBit(inVal, pos);
	sol.readBit(inVal, pos);
	sol.invertBit(inVal, pos);
	
	sol.moveBits (inVal, pos, true);//shift right
	sol.moveBits (inVal, pos, false);//shift left
	
	sol.hexToBinary("x0AF");
	sol.hexToBinary("xF0");
	
	sol.binaryToHex("10001000");
	sol.binaryToDecimal("10001000");
	sol.binaryToOct("10001000");
		
	return 0;
}