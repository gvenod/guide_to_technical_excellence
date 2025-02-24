#include <iostream>
#include <vector>
#include <algorithm> //sort

using namespace std;

/* logic: 
    - for each point find distance using a square + b square formula. no need to square root as we just need relatice distance not actual
    - add distance to vector; sort by distance
    - return first k elements
    */

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            vector<vector<int>> out;
            vector <pair <int, pair <int, int>>> temp;

            for (auto point_it : points) {
                int dist = point_it[0] * point_it[0] + point_it[1] * point_it[1];
                cout << "dist = " << dist << endl;
                temp.push_back(make_pair(dist, make_pair(point_it[0], point_it[1])));
            }
            sort(temp.begin(), temp.end()); //can use minheap to save sorting time.
            for (int i = 0; i < k; i++) {
                out.push_back({temp[i].second.first, temp[i].second.second});
            }
            
            return out;
        }
    };


int main() {
    Solution sol;

    vector<vector<int>> input_points = {{1,3}, {-2,2}};
    int k = 1; //Output: [[-2,2]]
    vector<vector<int>> output_points = sol.kClosest(input_points, k);
    for (auto point_it : output_points) {
        cout << "result = " << point_it[0] << "," << point_it[1] << endl;
    }

    input_points = {{3,3},{5,-1},{-2,4}};
    k = 2; //output = [[3,3],[-2,4]]
    output_points = sol.kClosest(input_points, k);
    for (auto point_it : output_points) {
        cout << "result = " << point_it[0] << "," << point_it[1] << endl;
    }

    return 0;
}