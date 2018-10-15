#include <iostream>

using namespace std;

class TreeNode {
private:
  int val;
  TreeNode* left;
  TreeNode* right;
  
public:

  TreeNode(int val) : val(val) {
    left = NULL;
    right = NULL;
  }

  void insert(int n) {
    if (n < val) {
      if (!left) {
	left = new TreeNode(n);
      }
      else {
	left->insert(n);
      }
    }
    else {
      if (!right) {
	right = new TreeNode(n);
      }
      else {
	right->insert(n);
      }
    }
  }

  TreeNode* find(int n) {
    if (val == n) return this;
    else if (n < val) return left ? left->find(n) : NULL;
    else return right ? right->find(n) : NULL;
  }

};
