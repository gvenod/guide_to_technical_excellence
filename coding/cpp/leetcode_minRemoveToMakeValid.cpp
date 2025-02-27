#include <iostream>
#include <string> // erase
#include <stack>

using namespace std;

class Solution {
	public:
    string minRemoveToMakeValid(string s) {
		cout << s << " - length = " << s.length() << endl;
		stack<int> st;
		for(int i =0; i < s.length(); i++) { //handle unmatched ')'
			cout << "handling char " << s[i] << endl;
			if(s[i] == '(') {
				st.push(i);
				cout << "pushing ( " << i << endl;
			} else if(s[i] == ')') {
				if(st.empty()) {
					cout << "stack empty" << endl;
					s[i] = '*'; //marking index for deletion;
					//s.erase(i, 1); // index pushed into stack changes if we delete here.
					cout << "delete ) at " << i << endl;
				} else {
					st.pop();//remove from stack as match found ()
					cout << "popping ) " << i << endl;
				}			
			}				
		}
		
		while(!st.empty()) { //handle unmatched '('
			int j = st.top();
			s[j] = '*'; //marking index for deletion;
			//s.erase(j, 1);// index pushed into stack changes if we delete here.
			st.pop();
			cout << "delete ( at " << j << endl;
		}
		
		//s.erase(s.begin(), s.end(), '*');
		s.erase(remove(s.begin(), s.end(), '*'), s.end());
		cout << s << endl;
		return s;
    }
};

int main() {
	Solution sol;
	string s = "lee(t(c)o)de)"; //Output: "lee(t(c)o)de"
	sol.minRemoveToMakeValid(s);
	
	s = "a)b(c)d"; //Output: "ab(c)d"
	sol.minRemoveToMakeValid(s);
	
	s = "))(("; //Output: ""
	sol.minRemoveToMakeValid(s);
	
	return 0;
}