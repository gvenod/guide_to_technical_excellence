#include <iostream>
#include <string>

using namespace std;

/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 pseduo code:
   - 2 pointers front and back; compare skip one comparsion if needed.
   - matches return true.
*/

class Solution {
	public:
		/*simple palindrome check*/
		bool isValidPalindrome(string inStr) {
			//cout << "string = " << inStr << endl;
			int rPtr = inStr.length() - 1, lPtr = 0;
			int mid = inStr.length()/2;
			while(rPtr >= mid && lPtr <= mid) {
				if(rPtr == lPtr) { break;}
				cout << "compare : " << inStr[rPtr] << " - " << inStr[lPtr] << endl;
				if(inStr[rPtr] == inStr[lPtr]) {//compare both the ends
					rPtr--;
					lPtr++;
					continue;
				} else {
					return false;
				}
			}
			return true;
		}
		
		/*skip one character if needed*/
		bool isValidPalindrome2(string inStr) {
			//input validation - skipped for now
			//cout << "string = " << inStr << endl;
			int rPtr = inStr.length() - 1, lPtr = 0, skip_counter= 0;
			int mid = inStr.length()/2;
			bool bMatchFailed = false;
			while(rPtr >= mid && lPtr <= mid) {
				if(rPtr == lPtr) { break;}
				cout << "compare : " << inStr[rPtr] << inStr[lPtr] << endl;
				if(inStr[rPtr] == inStr[lPtr]) {//compare both the ends
					rPtr--;
					lPtr++;
					continue;
				} else {
						//cout << "not matching -  check skip" << endl;
						if(skip_counter == 0) {
							skip_counter = 1;							
							if(inStr[rPtr] == inStr[lPtr + 1]) {
								lPtr++;
							} else if(inStr[rPtr - 1] == inStr[lPtr]){
								rPtr--;
							} else {
								cout << "not matching with skip" << endl;
								bMatchFailed = true;
								break;
							}
							cout << "matching with skip" << endl;
							continue;
						}
					bMatchFailed = true;
					cout << "not matching -- skip counter more than 1" << endl;
					break;
				}				
			}
			if(bMatchFailed == true) {
				return false;
			}
			return true;
		}
		
		/*normalize string. (remove non alpha numeric characters like ,#$...)*/
		bool isValidPalindrome_normalized(string inStr) {
			//cout << "string = " << inStr << endl;

			int rPtr = inStr.length() - 1, lPtr = 0;
			int mid = inStr.length()/2;
			while(rPtr >= mid && lPtr <= mid) {
				cout << "compare : " << inStr[rPtr] << " - " << inStr[lPtr] << endl;
				if(rPtr == lPtr) {
					//cout << "reached mid" << endl;
					break;
				}
				if(!((inStr[rPtr] >= '0' && inStr[rPtr] <= '9') || (inStr[rPtr] >= 'a' && inStr[rPtr] <= 'z') || (inStr[rPtr] >= 'A' && inStr[rPtr] <= 'Z') )) {
					//cout << "valid rPtr char" << endl;
				//} else {
					rPtr--;
					//cout << "move rPtr" << endl;
					continue;
				}
				
				if(!((inStr[lPtr] >= '0' && inStr[lPtr] <= '9') || (inStr[lPtr] >= 'a' && inStr[lPtr] <= 'z') || (inStr[lPtr] >= 'A' && inStr[lPtr] <= 'Z') )) {
					//cout << "valid lPtr char" << endl;
				//} else {
					lPtr++;
					//cout << "move lPtr" << endl;
					continue;
				}
				
				//cout << "compare : " << inStr[rPtr] << " - " << inStr[lPtr] << endl;
				if(tolower(inStr[rPtr]) == tolower(inStr[lPtr])) {//compare both the ends
					rPtr--;
					lPtr++;
					continue;
				} else {
					return false;
				}
			}
			return true;
		}
};

int main() {
	
	Solution sol;
	
	cout << "aba : " << sol.isValidPalindrome("aba") << endl;
	cout << "acdca : " << sol.isValidPalindrome("acdca") << endl;
	cout << "acddca : " << sol.isValidPalindrome("acddca") << endl;
	cout << "acda : " << sol.isValidPalindrome("acda") << endl;
	cout << "acdda : " << sol.isValidPalindrome("acdda") << endl;
	
	cout << "aba : " << sol.isValidPalindrome2("aba") << endl;
	cout << "abca : " << sol.isValidPalindrome2("abca") << endl;
	cout << "abcda : " << sol.isValidPalindrome2("abcda") << endl;
	
	cout << "race a car" << sol.isValidPalindrome_normalized("race a car") << endl;
	cout << "A man, a plan, a canal: Panama" << sol.isValidPalindrome_normalized("A man, a plan, a canal: Panama") << endl;
	cout << " " << sol.isValidPalindrome_normalized(" ") << endl;
	
	return 0;
}