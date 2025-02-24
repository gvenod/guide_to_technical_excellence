#include <iostream>
#include <vector>

using namespace std;

/*
    logic: sliding window technic -  2 ptrs 
    - move left ptr one by one - when it reaches the end move right ptr by one. repeat.
    - for every move take sum and modules of sum and given k. if modules is 0 return true 
 */

class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            //sliding windows
            int ptr_r = 0, ptr_l = ptr_r + 1, len = nums.size() - 1;
            int sum = 0;
            while (ptr_r < len) 
            {
                sum += nums[ptr_r];
                while( ptr_l < len) { //reached end
                    cout << "sliding windows  = " << ptr_r << "," << ptr_l << endl;
                    sum += nums[ptr_l];
                    cout << "sum = " << sum << endl;

                    if(sum % k == 0) {
                        cout << " sum multiple of k " << sum << endl;
                        return true;
                    }
                    
                    ptr_l++;
                }

                ptr_r++;
                sum = 0; 
                ptr_l = ptr_r + 1;
            }

            return false;
        }
    };

int main() {
    Solution sol;

    vector<int> input_nums = {23,2,4,6,7};
    int k = 6; // Output: true
    //Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
    
    cout << "result : "  << sol.checkSubarraySum(input_nums, k) << endl;

    return 0;
}