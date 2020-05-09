#include <bits/stdc++.h>

using namespace std;

/**
 *  You are a product manager and currently leading a team to develop a new product.
 *  Unfortunately, the latest version of your product fails the quality check.
 *  Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 *  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *  You are given an API bool isBadVersion(version) which will return whether version is bad.
 *
 *  Implement a function to find the first bad version.
 *  You should minimize the number of calls to the API.
 */

// Global variable to be used in isBadVersion
int badVersion;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// in the real problem, the implementation is hidden from user
bool isBadVersion(int version) { return version >= badVersion; }

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Hint:
   *  1. utilize binary search
   *  2. check if middle version is a bad version
   *    a. if middle version is a bad version
   *      i. if middle-1 version is good, then middle is the first bad version; return it
   *      ii. else, bad version must be in the left side
   *    b. else, bad version must be in the right side
   *  3. repeat until found
   */
  int firstBadVersion(int n) {
    int begin = 1, end = n;
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;

      bool badMid = isBadVersion(mid);
      if (badMid) {
        if (mid == 0 || !isBadVersion(mid-1))
          return mid;
        else
          end = mid-1;
      } else {
        begin = mid+1;
      }
    }

    return 0;
  }
};

int main() {
  int n;
  cin >> n;
  cin >> badVersion;

  Solution *s = new Solution();
  int knownBadVersion = s->firstBadVersion(n);
  cout << knownBadVersion << endl;

  return 0;
}
