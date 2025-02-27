#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //max

using namespace std;

class Solution {
	public:
		
		void print_vector(vector<int>& nums1) {
			for (int i = 0; i < nums1.size(); i++) {
				cout << nums1[i] << endl;
			}
			cout << " ----- " << endl;
		}
		
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			
			print_vector(nums1);
			
			int insert_index =  (m + n) - 1;
			int j = n - 1, i = m -1;
			
			while ( j >= 0 ) {
				if(i >= 0 && nums1[i] > nums2[j] ) {
					nums1[insert_index--] = nums1[i--];						
				} else {
					nums1[insert_index--] = nums2[j--];
				}			
			}			
			print_vector(nums1);			
		}
		
		void mergeStringAlternatively(string word1, string word2) {
			cout << word1 << " : " << word2 << endl;
			string out = "";
			int n = 0, m = 0;
			int insert_index = 0;//m + n -1;
			
			//if m is longer
			while (m <= word1.length() -1) {
				out += word1[m++];
				cout << "adding word1 out : " << out << endl;
				if(n <= word2.length() -1) {
					out += word2[n++];
					cout << "adding word2 out : " << out << endl;					
				}
			}
			
			//if n is longer
			while (n <= word2.length() -1) {
				out += word2[n++];
				cout << "adding word2 out : " << out << endl;
			}
			cout << "out : " << out << endl;
			return;
		}	
};

int main() {
	Solution sol;
	sol.helloworld();
	
	vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
	int m = 3,n = 3; //Output: [1,2,2,3,5,6]
	sol.merge(nums1, m, nums2, n);
	
	nums1 = {1}, nums2 = {};
	m = 1, n = 0; //Output: [1]
	sol.merge(nums1, m, nums2, n);
	
	nums1 = {0}, nums2 = {1};
	m = 0, n = 1; //Ostring [1]
	sol.merge(nums1, m, nums2, n);
	
	
	string word1 = "ab", word2 = "pqrs"; //Output: "apbqrs"
	sol.mergeStringAlternatively(word1, word2);
	
	return 0;
}