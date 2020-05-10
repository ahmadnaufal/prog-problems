#include <bits/stdc++.h>

using namespace std;

/**
 *  In a town, there are N people labelled from 1 to N.
 *  There is a rumor that one of these people is secretly the town judge.
 *
 *  If the town judge exists, then:
 *    1. The town judge trusts nobody.
 *    2. Everybody (except for the town judge) trusts the town judge.
 *    3. There is exactly one person that satisfies properties 1 and 2.
 *
 *  You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
 *  If the town judge exists and can be identified, return the label of the town judge. Otherwise, return -1.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  Approach:
   *  For each person i, store a pair of values:
   *    1. Num of person i trusts other people, and
   *    2. Num of other people trusts person i
   *  person i is a judge if value 1) is 0 and value 2) is N-1
   */
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<pair<int, int>> res(N+1,{0,0});
    for (vector<int> el : trust) {
      res[el[0]].first++;
      res[el[1]].second++;
    }

    for (int i = 1; i <= N; ++i)
      if (res[i].first == 0 && res[i].second == N-1)
        return i;

    return -1;
  }
};

int main() {
  int n, t;
  cin >> n >> t;

  vector<vector<int>> trust;
  while (t--) {
    vector<int> tr(2);
    cin >> tr[0] >> tr[1];
    trust.push_back(tr);
  }

  Solution *solution = new Solution();
  cout << solution->findJudge(n, trust) << endl;

  return 0;
}