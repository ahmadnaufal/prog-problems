#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 *  Implement a trie with insert, search, and startsWith methods.
 */

class Trie {
  class TrieNode {
  public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
      isEnd = false;
      for (int i = 0; i < 26; i++)
        children[i] = NULL;
    }
  };

  TrieNode *root;

public:
  /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *temp = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!temp->children[idx])
        temp->children[idx] = new TrieNode();

      temp = temp->children[idx];
    }

    temp->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *temp = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!temp->children[idx]) return false;

      temp = temp->children[idx];
    }

    return temp != NULL && temp->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *temp = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!temp->children[idx]) return false;

      temp = temp->children[idx];
    }

    return temp != NULL;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  string insts, params;
  getline(cin, insts);
  getline(cin, params);

  vector<string> coms, prms;
  istringstream issc(insts);
  for (string s; issc >> s; )
    coms.push_back(s);

  istringstream issp(params);
  for (string s; issp >> s; )
    prms.push_back(s);

  Trie* obj;
  for (int i = 0; i < coms.size(); ++i) {
    if (coms[i] == "Trie")
      obj = new Trie();
    else if (coms[i] == "insert")
      obj->insert(prms[i]);
    else if (coms[i] == "search")
      cout << obj->search(prms[i]);
    else if (coms[i] == "startsWith")
      cout << obj->startsWith(prms[i]);

    cout << endl;
  }

  return 0;
}