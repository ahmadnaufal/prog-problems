#include <bits/stdc++.h>

using namespace std;

/**
 *  You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
 *  represents the coordinate of a point.
 *  Check if these points make a straight line in the XY plane.
 */

/**
 *  The solution class
 */
class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    if (coordinates.size() == 2) return true;

    float firstSlope = slope(coordinates[0], coordinates[1]);
    for (int i = 1; i < coordinates.size()-1; ++i)
      if (firstSlope != slope(coordinates[i], coordinates[i+1]))
        return false;

    return true;
  }

  float slope(vector<int> p1, vector<int> p2) {
    if (p1[0] == p2[0]) return 0;
    return (float) (p2[1] - p1[1]) / (p2[0] - p1[0]);
  }
};


int main() {
  int n;
  cin >> n;

  vector<vector<int>> coordinates;
  while (n--) {
    vector<int> point(2);
    cin >> point[0] >> point[1];
    coordinates.push_back(point);
  }

  Solution *solution = new Solution();
  cout << solution->checkStraightLine(coordinates) << endl;

  return 0;
}