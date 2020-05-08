#include <bits/stdc++.h>

using namespace std;

/**
 *  Say you have an array prices for which the ith element is the price of a given stock on day i.
 *  Design an algorithm to find the maximum profit.
 *  You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *  Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 *  Input: [7,1,5,3,6,4]
 *  Output: 7
 *  Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 */

/**
 *  The solution class
 */
class Solution {
public:
  /**
   *  we can simply go on crawling over the slope and keep on adding the profit obtained from every consecutive transaction.
   *  In the end,we will be using the peaks and valleys effectively, but we need not track the costs corresponding to the peaks
   *  and valleys along with the maximum profit, but we can directly keep on adding the difference between the consecutive
   *  numbers of the array if the second number is larger than the first one, and at the total sum we obtain will be the maximum profit.
   *  This approach will simplify the solution.
   */
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
      if (prices[i] > prices[i-1])
        profit += prices[i] - prices[i-1];

    return profit;
  }
};

int main() {
  string s;
  getline(cin, s);

  vector<string> raw;
  istringstream iss(s);
  for (string s; iss >> s; )
    raw.push_back(s);

  vector<int> nums;
  for (string s : raw)
    nums.push_back(stoi(s));

  Solution *solution = new Solution();;
  cout << solution->maxProfit(nums) << endl;

  return 0;
}
