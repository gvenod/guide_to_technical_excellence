

# given array of points, find the closest 1 or n/k points to origin [0,0]
use distance calculation formula for each point in the array.
d = sqrt ((x1-x2) power of 2 + (y1 -y2) power of 2 
x1,y1 is the point in array index.
x2, y2 will be zero for origin 0,0
sort all the distance by ascending order
return points of index of least distance.

---

# find if single linked list is circular.
start from root, move/traverse 2 pointers, first by one step and second by 2 steps. when 2nd and 1st meets then list is circular.

---

# Find middle node of single Linked List
start from root, move/traverse 2 pointers, first by one step and second by 2 steps. when 2nd reaches end first one will be at the middle.

---

# Given root, reverse single Linked List
 take 2 nodes; assign 2nd node pointer to temp. assign 1st node pointer to 2nd node pointer; assign temp to 1st node pointer; repeat till end. return new root.

---

# is circles overlapping
 find distance b/w points [center of circles] using formula d = sqrt((x2-x1) power of 2 + (y2 - y1)power of 2); if radius of circle1 + circle 2 < distance then overlapping.

---

# is circle and triangle overlapping
 [revisit logic] find distance between corner of rectangle  and circle center. [all the 4 corners of rect]. take the minimum distance of all the 4. if radius is less than distance then overlapping.

---

# is 2 rectangles overlapping
 check all the 4 corners of a rectangle within boundries of 2 rect.

---

# shortest path in binary matrix/graph
https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
