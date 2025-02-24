#include <iostream>
#include <vector>
#include <string>
#include <cmath> // pow, sqrt
#include <algorithm> //min

using namespace std;

class Solution {
	public:
	
		/* two circles*/
		bool checkOverlap_two_circles(int radius, int xCenter, int yCenter,int radius2, int xCenter2, int yCenter2) {
			//logic: 
			// - distance between 2 points = sqrt( (x2-x2)^2 + (y2-y1)^2)
			// - if radius1 + radius2 < distance then overlap.
			
			int d = sqrt( pow(xCenter2-xCenter,2) + pow(yCenter2-yCenter, 2) );
			int sum_r = radius + radius2;
			cout << sum_r << " = sum : distance = " << d << endl; 
			if ( sum_r >= d) {
				cout << "overlap" << endl;
				return true;
			}
			cout << "no overlap" << endl;
			return false;			
		}
		
		
		/*two rectangles*/
		bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
			/* logic:
				- check each rect1 corner is within top and bottom boundaries of rect2 and left and right boundries of rect2;
				- if yes the overlapping.
			*/
			int r1Btm = rec1[0], r1Left = rec1[1], r1Top = rec1[2], r1Right = rec1[3];
			int r2Btm = rec2[0], r2Left = rec2[1], r2Top = rec2[2], r2Right = rec2[3];
		
			cout << "r1Left = " << r1Left << " r1Right = " << r1Right << " r2Left = " << r2Left << endl;
			cout << "r1Btm = " << r1Btm << " r1Top = " << r1Top << " r2Top = " << r2Top << endl;
			
			if((r2Top > r1Btm && r2Top < r1Top) && (r2Left > r1Left && r2Left < r1Right)){ cout << "top left is inside." << endl; return true;}
			if((r2Top > r1Btm && r2Top < r1Top) && (r2Right > r1Left && r2Right < r1Right)) { cout << "top right is inside." << endl; return true;}
			if((r2Btm > r1Btm && r2Btm < r1Top) && (r2Left > r1Left && r2Left < r1Right)) { cout << "bottom left is inside." << endl; return true;}
			if((r2Btm > r1Btm && r2Btm < r1Top) && (r2Right > r1Left && r2Right < r1Right)) { cout << "bottom right is inside." << endl; return true;}

			cout << "no overlap found" << endl;
			return false;
		}
		
		/*circle and rectangle*/
		bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
			/*Locate the closest point of the square to the circle, you can then find the distance from this point to the center of the circle and check if this is less than or equal to the radius.*/
			//logic:
			// - calculate min (distance of circle center from rectangle corners) 
			// - if distance > radius then not overlap.
			//int neareast_x = max(x1, min(x2,xCenter));
			//int neareast_y = max(y1, min(y2,yCenter));
			
			int d = 0;
			int d1 = sqrt( pow(x1-xCenter,2) + pow(y1-yCenter, 2) );			
			int d2 = sqrt( pow(x2-xCenter,2) + pow(y2-yCenter, 2) );
			d = min(d1,d2);
			int d3 = sqrt( pow(x1-xCenter,2) + pow(y2-yCenter, 2) );
			d = min(d,d3);
			int d4 = sqrt( pow(x2-xCenter,2) + pow(y1-yCenter, 2) );
			d = min(d,d4);
		
			cout << radius << " = radius : distance = " << d << endl; 
			if ( radius >= d) {
				cout << "overlap" << endl;
				return true;
			}
			cout << "no overlap" << endl;
			return false;	
		}		
};

int main() {
	Solution sol;
	
	vector<int> rec1 = {0,0,2,2}, rec2 = {1,1,3,3};	//Output: true
	cout << sol.isRectangleOverlap(rec1, rec2) << endl;
	
	rec1 = {0,0,1,1}; rec2 = {1,0,2,1}; //Output: false
	cout << sol.isRectangleOverlap(rec1, rec2) << endl;

	rec1 = {0,0,1,1}; rec2 = {2,2,3,3}; //Output: false
	cout << sol.isRectangleOverlap(rec1, rec2) << endl;
	
	
	int radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1; //Output: true
	//Explanation: Circle and rectangle share the point (1,0).
	cout << sol.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2) << endl;
	
	radius = 2, xCenter = 0, yCenter = 0;
	int radius2 = 1, xCenter2 = 5, yCenter2 = 5;
	cout << sol.checkOverlap_two_circles(radius, xCenter, yCenter, radius2, xCenter2, yCenter2) << endl;
	
	return 0;
}