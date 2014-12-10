/*********************
 LeetCode  Max Points on a Line 

  Given n points on a 2D plane, find the maximum number of points 
  that lie on the same straight line.

  Brute-force search along the points, use a hash-map to record the slopwe of 
  two points. if the slope is same, update the count of points.

  time complexity O(n^2),space complexity O(n)

***********************/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) return points.size();
        
        int result = 0;
        unordered_map<double, int> slope_table;
        for (int i=0; i<points.size()-1; i++) {
            slope_table.clear();
            int nSamePoint = 0;
            int nMaxPoint = 1;
            
            for(int j=i+1; j<points.size(); j++) {
                double slope;
                if (points[j].x == points[i].x) {
                    slope = std::numeric_limits<double>::infinity();
                    if (points[j].y == points[i].y) {
                        ++ nSamePoint;
                        continue;
                    }
                } else {
                    slope = 1.0*(points[i].y - points[j].y)/
                              (points[i].x - points[j].x);
                }
                int count = 0;
                if (slope_table.find(slope) != slope_table.end()) {
                        count = slope_table[slope] + 1;
                } else {
                    count = 2;
                }
                slope_table[slope] = count;
                if (nMaxPoint < count) nMaxPoint = count;
            }
            result = max(result, nMaxPoint + nSamePoint);
        }
        return result;
    }
};
