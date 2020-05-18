#include <iostream>
#include <string>

using namespace std;

/**
 *  Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 *  Note:
 *    1. The length of num is less than 10002 and will be ≥ k.
 *    2. The given num does not contain any leading zero.
 */

/**
 *  The solution class
 */
class Solution {
public:

  /**
   *  The approach is to construct a result string (a new number)
   *  with the smallest number in the initial number string while we can still
   *  remove the biggest number from the result (k > 0)
   *
   *  For example, if num = 1432219 and k = 3
   *  1. result = ""; num[0] = 1, add to result
   *  2. result = "1"; num[1] = 4, 1 < 4, therefore add to result
   *  3. result = "14"; num[2] = 3, 4 > 3, remove 4 from result and add the 3
   *    - Decrement k because we removed 1 char, k = 2
   *  4. result = "13"; num[3] = 2, 3 > 2, remove 3 from result and add the 2
   *    - Decrement k, k = 1
   *  5. result = "12"; num[4] = 2, 2 = 2, add 2 to result
   *  6. result = "122"; num[5] = 1, 2 > 1, remove 2 from result and add the 1
   *    - decrement k, k = 0
   *    - we can remove the second "2" from "12", but since k is already 0 (from the first "2" removal), we can't remove another number
   *  7. result = "121"; num[6] = 9, since k is already 0, append the final number "9" to result
   *  8. answer is 1219
   */
  string removeKdigits(string num, int k) {
    string res = "";
    for (char c : num) {
      while (res.length() && res.back() > c && k) {
        res.pop_back();
        k--;
      }
      if (res.length() || c != '0') res += c;
    }

    while (res.length() && k > 0) {
      res.pop_back();
      k--;
    }

    return res.length() == 0 ? "0" : res;
  }
};

int main() {
  string st;
  int k;
  cin >> st >> k;

  Solution *s = new Solution();
  cout << s->removeKdigits(st, k) << endl;

  return 0;
}