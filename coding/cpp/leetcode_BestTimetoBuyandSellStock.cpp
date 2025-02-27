#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //max

using namespace std;

class Solution {
	public:	
		
		/*121. Best Time to Buy and Sell Stock*/
		int maxProfit(vector<int>& prices) {
			//{7,1,5,3,6,4}
			/*logic:
			 - sliding window
			 - 2 ptrs; move 2nd ptr */
			
			int lPtr = 0, rPtr = 1;
			int max_profit = 0;//prices[rPtr] - prices[lPtr];
						
			while(rPtr < prices.size()) {
				cout << prices[rPtr] << " = right : left = " << prices[lPtr] << endl;
				if(prices[rPtr] < prices[lPtr]) {
					lPtr = rPtr;//move left and right
					rPtr++;
				} else {
					max_profit = max(max_profit, prices[rPtr] - prices[lPtr]);
					cout << "max_profit" << max_profit << endl;
					rPtr++;//move right
				}
			}

			return max_profit;
		}	
};

int main() {
	Solution sol;
	
	vector<int> prices = {7,1,5,3,6,4}; //Output: 5
	cout << "max profit = " << sol.maxProfit(prices) << endl;
	
	prices = {7,6,4,3,1}; //output: 0
	cout << "max profit = " << sol.maxProfit(prices) << endl;
	
	return 0;
}