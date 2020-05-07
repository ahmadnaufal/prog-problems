#include <bits/stdc++.h>
#include "../../lib/tree.h"

using namespace std;

/**
 *  Given an array of size n, find the majority element.
 *  The majority element is the element that appears more than floor(n/2) times.
 *  You may assume that the array is non-empty and the majority element always exist in the array.
 */

/**
 *  The solution class
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  int dx, dy;
  int px, py;
public:
  bool isSibling(TreeNode* root, int x, int y) {
    if (root == NULL) return false;

    if (root->left != NULL && root->right != NULL)
      return (root->left->val == x && root->right->val == y) ||
              (root->right->val == x && root->left->val == y) ||
              (isSibling(root->left, x, y) || isSibling(root->right, x, y));

    return (isSibling(root->left, x, y) || isSibling(root->right, x, y));
  }

  int level(TreeNode* root, int x) {
    if (root == NULL) return 0;
    if (root->val == x) return 1;

    int res = level(root->left, x);
    if (res != 0) return res+1;

    res = level(root->right, x);
    return res != 0 ? res+1 : 0;
  }

  void traverseAndFind(TreeNode* root, int x, int y, int depth, int parent) {
    if (root == NULL) return;

    depth++;
    if (root->val == x) {
      dx = depth;
      px = parent;
    }
    if (root->val == y) {
      dy = depth;
      py = parent;
    }

    traverseAndFind(root->left, x, y, depth, root->val);
    traverseAndFind(root->right, x, y, depth, root->val);
  }

  /**
   *  Solved by two approach:
   *  1. Check the levels for both keys & if they match, check if they are not siblings
   *     by checking if they come from same parents -> level(x) == level(y) and not isSibling(x, y)
   *  2. Do tree traversal, keep track of current node and its parent. If key found, save the level
   *     and save the node's parents. Finally, check if x and y are at the same depth & have different parents
   */
  bool isCousins(TreeNode* root, int x, int y) {
    // return (level(root, x) == level(root, y) && !isSibling(root, x, y));
    traverseAndFind(root, x, y, 0, -1);
    return dx == dy && px != py;
  }
};

int main() {
  string s;
  getline(cin, s);

  vector<string> raw;
  istringstream iss(s);
  for (string s; iss >> s; )
    raw.push_back(s);

  TreeNode* root = construct(raw, NULL, 0, raw.size());

  int x, y;
  cin >> x >> y;

  Solution *solution = new Solution();
  cout << solution->isCousins(root, x, y) << endl;
}