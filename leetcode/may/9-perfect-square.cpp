#include <bits/stdc++.h>

using namespace std;

/**
 *  Given a positive integer num, write a function which returns True if num is a perfect square, else False.
 *  Note: Do not use any built-in library function such as sqrt.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Approach:
   *  1. from i = 1; increment by 1 until i * i >= num. Then, return true if i * i == num.
   *  2. do binary search with initial boundaries: 1 to num/2. Check if mid is the perfect square root (below)
   *  3. babylonian square root estimation method:
   *    a. find initial value of x = num / 2
   *    b. while x * x != num, calculate new x = (x + (num / x)) / 2
   *    c. if new x result is already seen before, return false
   *    b. x * x == num, return true
   */
  bool isPerfectSquare(int num) {
    if (num == 1) return true;

    int begin = 1, end = num/2;
    while (begin <= end) {
      double mid = begin + (end - begin) / 2;
      if (mid == num/mid) return true;
      if (mid < num/mid) begin = mid+1;
      else end = mid-1;
    }

    return false;
  }
};

int main() {
  int n;
  cin >> n;

  Solution *solution = new Solution();
  cout << solution->isPerfectSquare(n) << endl;

  return 0;
}