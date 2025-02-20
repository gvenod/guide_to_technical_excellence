#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool validWordAbbreviation(string word, string abbr) {
            //logic: compare characters in both strings. if abbr has a number, add that many characters to the count
            cout << "validWordAbbreviation = " << word << ":" <<  abbr << endl;

            int word_len = word.length(), abbr_len = abbr.length();
            int word_char_ptr = 0;
            bool doLeadingZeroCheck = true;
            int number = 0, number_counter = 0;
        
            //for each char in abbr string; handle rules; increment word index; compare char with word index
            for (int j = 0; j < abbr_len; j++) {
                char c = abbr[j];
                cout << "char = " << c << endl;

                if(isdigit(c)) {                    

                   int i = (int) c - '0';
                   cout << "digit = " << i << endl;

                   if(i > word_len) {
                        return false;
                   } else if(doLeadingZeroCheck == true && i == 0) {
                        return false;
                   } /*else if( j == 0 && i == 0) {
                        return false;//first letter cannot be number
                   }*/

                   number = (number * 10) + i;
                   cout << "number = " << number << endl;
                   number_counter++;
                   doLeadingZeroCheck = false;

                   continue;
    
                } else {

                    /*if(word[abbr_count] != abbr[j]) {
                        return false;
                    }*/
                    cout << "entry word_char_ptr : " << word_char_ptr << endl;

                    cout << "number = " << number << endl;
                    if(number != 0) {
                        word_char_ptr += number;
                    }
                    cout << "new word_char_ptr : " << word_char_ptr << endl;
            
                 
                    cout << "compare : " << word [word_char_ptr] << " with " << abbr[j] << endl;
                    
                    if(word[word_char_ptr] != abbr[j]) {
                        cout << "not matching return false" << endl;
                        return false;
                    }

                    
                    //reset again if found a char
                    doLeadingZeroCheck = true;
                    number_counter = 0;
                    number = 0;

                    word_char_ptr++;
                    cout << "exit word_char_ptr : " << word_char_ptr << endl;

                }
            }
            if(number != 0) {
                word_char_ptr += number;
            }

            if(word_len != word_char_ptr) {
                cout << "word_len != word_char_ptr" << endl;
                return false;
            }
   
                return true;
            }        
    };

int main() {
    Solution sol;

    //false
    cout << "apple - a2e : result = " << sol.validWordAbbreviation("apple", "a2e") << endl;
    cout << "substitution - s55n : result =  " << sol.validWordAbbreviation("substitution", "s55n") << endl;//the replaced substrings are adjacent
    cout << "substitution - s010n : result =  " << sol.validWordAbbreviation("substitution", "s010n") << endl;//has leading zeros
    cout << "substitution - s0ubstitution : result =  " << sol.validWordAbbreviation("substitution", "s0ubstitution") << endl;//replaces an empty substring

    //true
    cout << "internationalization - i12iz4n : result = " << sol.validWordAbbreviation("internationalization", "i12iz4n") << endl;
    cout << "substitution - s10n : result =  " << sol.validWordAbbreviation("substitution", "s10n") << endl;
    cout << "substitution - sub4u4 : result = " << sol.validWordAbbreviation("substitution", "sub4u4") << endl;
    cout << "substitution - su3i1u2on : result = " << sol.validWordAbbreviation("substitution", "su3i1u2on") << endl;
    cout << "substitution - substitution : result = " << sol.validWordAbbreviation("substitution", "substitution") << endl;
    cout << "substitution - 12 : result = " << sol.validWordAbbreviation("substitution", "12") << endl;

    return 0;
}