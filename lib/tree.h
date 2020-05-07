#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Construct a binary tree from an array of string
TreeNode* construct(vector<string>& arr, TreeNode* root, int i, int n) {
  if (i < n) {
    if (arr[i] == "null") return NULL;

    root = new TreeNode(stoi(arr[i]));
    root->left = construct(arr, root->left, 2*i+1, n);
    root->right = construct(arr, root->right, 2*i+2, n);
  }

  return root;
}