#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    logic:
     - sort the intervals by x
        - if the next interval's x is less than the current interval's y, merge them 
        - two loops 0 to n; and 1 to n; if more than 1 overlap then increment first loop by nOverlapCounter
        - if no overlap then add the interval to out_interval
*/

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) 
        {
            int len = intervals.size();
            cout << "len = " << len << endl;

            /*cout << "unsorted intervals" << endl;
            for (auto interval_it : intervals) {
                cout << interval_it[0] << " " << interval_it[1] << endl;
            }*/

            sort(intervals.begin(), intervals.end());

            /*cout << "sorted intervals" << endl;
            for (auto interval_it : intervals) {
                cout << interval_it[0] << " " << interval_it[1] << endl;
            }*/
            vector<vector<int>> out_interval; 

            for (int i =0; i < len; i++) {

                int nOverlapCounter = 0;
                int y = 0;
                bool bRequireMerge = false;

                cout << "-----" << intervals[i][0] << " " << intervals[i][1] << endl;
                for (int j = i + 1; j < len; j++) {
                    cout << "****" << intervals[j][0] << " " << intervals[j][1] << endl;
                    if (intervals[i][1] >= intervals[j][0]) {
                        cout << "overlapping" << endl;
                        y = max(intervals[i][1], intervals[j][1]);//keep track of max 2nd element or is it sorted?
                        cout << "y = " << y << endl;
                        nOverlapCounter++; //check the next j.
                        cout << j << " " << len << endl;
                        if(j + 1 < len) {
                            cout << "j < len" << endl;
                            continue; //if last item then push it to out_interval results else continue to next j    
                        }            
                    } 

                    if(nOverlapCounter > 0) {
                        cout << "merging overlap" << intervals[i][0] << y <<endl;
                        out_interval.push_back({intervals[i][0], y});
                        i += nOverlapCounter;//skip i
                        bRequireMerge = true;                        
                        break; //inner loop  - go to next element.
                    } else {
                        cout << "adding as no overlapping" << endl;
                        //out_interval.push_back({intervals[i][0], intervals[i][1]});
                        break; //inner loop  - go to next element.
                    }
                }

                if(bRequireMerge == false) {
                    out_interval.push_back({intervals[i][0], intervals[i][1]});
                }
                bRequireMerge = false;//reset
            }
            
            return out_interval;    
        }
    };

    int main() {
        Solution s;

        vector<vector<int>> input_intervals = {{1,3},{2,6},{8,10},{15,18}}; //output : {{1,6},{8,10},{15,18}};
        //Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
        vector<vector<int>> out_intervals = s.merge(input_intervals);
        cout << "out intervals" << endl;
        for (auto interval_it : out_intervals) {
            cout << interval_it[0] << " " << interval_it[1] << endl;
        }


        input_intervals = {{1,4},{4,5}}; //output : {{1,5}}; 
        //Explanation: Intervals [1,4] and [4,5] are considered overlapping.
        out_intervals = s.merge(input_intervals);
        cout << "out intervals" << endl;
        for (auto interval_it : out_intervals) {
            cout << interval_it[0] << " " << interval_it[1] << endl;
        }

        return 0;
    }

