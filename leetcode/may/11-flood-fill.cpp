#include <vector>
#include <iostream>

using namespace std;

/**
 *  An image is represented by a 2-D array of integers, each integer representing
 *  the pixel value of the image (from 0 to 65535).
 *  Given a coordinate (sr, sc) representing the starting pixel (row and column)
 *  of the flood fill, and a pixel value newColor, "flood fill" the image.
 *
 *  To perform a "flood fill", consider the starting pixel, plus any pixels connected
 *  4-directionally to the starting pixel of the same color as the starting pixel,
 *  plus any pixels connected 4-directionally to those pixels (also with the same
 *  color as the starting pixel), and so on.
 *
 *  Replace the color of all of the aforementioned pixels with the newColor.
 *  At the end, return the modified image.
 */

/**
 *  The solution class
 */
class Solution {
public:
  void fill(vector<vector<int>>& image, int x, int y, int newColor) {
    if (image[x][y] == newColor) return;

    int old = image[x][y];
    image[x][y] = newColor;

    if (x-1 >= 0 && image[x-1][y] == old) fill(image, x-1, y, newColor);
    if (x+1 < image.size() && image[x+1][y] == old) fill(image, x+1, y, newColor);
    if (y-1 >= 0 && image[x][y-1] == old) fill(image, x, y-1, newColor);
    if (y+1 < image[0].size() && image[x][y+1] == old) fill(image, x, y+1, newColor);
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    fill(image, sr, sc, newColor);
    return image;
  }
};

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> image;
  while (m--) {
    int c = n;
    vector<int> row;
    while (c--) {
      int x;
      cin >> x;
      row.push_back(x);
    }

    image.push_back(row);
  }

  int sr, sc, newColor;
  cin >> sr >> sc >> newColor;

  Solution *solution = new Solution();
  vector<vector<int>> res = solution->floodFill(image, sr, sc, newColor);

  // output matrix
  for (vector<int> row : image) {
    for (int el : row)
      cout << el << " ";
    cout << endl;
  }

  return 0;
}
