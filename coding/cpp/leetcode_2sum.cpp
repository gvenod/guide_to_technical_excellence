#include <iostream>
#include <vector>
#include <unordered_map> //hash map

using namespace std;

class Solution {
	public:
		
		vector<int> twoSum(vector<int>& nums, int target) {
			
			vector<int> out;
			std::unordered_map<int, int> temp; //to store (target - value), index
			
			for (int index = 0; index < nums.size(); index++) {				
				std::unordered_map<int, int>::iterator it = temp.find(nums[index]);
				if(it == temp.end()) {
					int lookforNo = target - nums[index]; //possible 2nd value.
					temp[lookforNo] = index;//add to map
					cout << "adding : " << lookforNo << " at " << index << endl;
				} else {
					out.push_back(index);
					out.push_back(it->second);
					cout << "found indexes : " << it->second << " and " << index << endl;
					break;
				}
			}
			for(int j = 0; j < out.size(); j++) {
				cout << out[j] << endl;
			}
			return out;
			
		}
	
};

int main() {
	Solution sol;
	
	vector<int> nums = {2,7,11,15};
	int target = 9; //Output: [0,1]
	sol.twoSum(nums, target);


	return 0;
}