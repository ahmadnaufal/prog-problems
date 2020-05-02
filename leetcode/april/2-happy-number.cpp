#include <bits/stdc++.h>

using namespace std;

/**
 *  Write an algorithm to determine if a number n is "happy".
 * 
 *  A happy number is a number defined by the following process:
 *  Starting with any positive integer, replace the number by the sum of the squares of its digits,
 *  and repeat the process until the number equals 1 (where it will stay),
 *  or it loops endlessly in a cycle which does not include 1.
 *  Those numbers for which this process ends in 1 are happy numbers.
 * 
 *  Return True if n is a happy number, and False if not.
 */

/**
 *  The solution class
 */ 
class Solution {
public:
  /**
   *  Do this the straightforward way:
   *  1. Calculate the sum of squares of the number's digits
   *  2. Check if the number is already calculated by looking at a set
   *    a. if already calculated, return false
   *  3. if not calculated yet, add to set
   *  4. repeat 2-3 until the number is 1 -> return true
   */

  int countRes(int n) {
    int res = 0;
    while (n > 0) {
      res += (int) pow(n % 10, 2);
      n /= 10;
    }

    return res;
  }

  bool isHappy(int n) {
    set<int> memr;
    do {
      n = countRes(n);
      if (memr.find(n) != memr.end())
        return false;
    
      memr.insert(n);
    } while (n > 1);

    return true;
  }
};

int main() {
  int n;
  cin >> n;

  Solution *s = new Solution();
  cout << s->isHappy(n) << endl;

  return 0;
}
