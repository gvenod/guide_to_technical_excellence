#include <iostream>
using namespace std;

/* logic:
    handle conditions n<0 then convert input_value to 1 / input_value 
    for n times multiple input_value to generate output_value
*/
class Solution {
    public:
        double myPow(double x, int n) {
            double out = 1, in = x;
            if (n < 0) {
                 in= 1 / in;
            }
            for (auto i = 0; i < abs(n); i++) {
                out *= in;
                cout << out << endl;
            }
            
            return out;
        }
    };

int main() {
    Solution s;
    cout << s.myPow(2, 10) << endl;
    cout << s.myPow(2.1, 3) << endl;
    cout << s.myPow(2, -2) << endl;
    cout << s.myPow(-2, 2) << endl;
    cout << s.myPow(-2, 3) << endl;
    return 0;
}