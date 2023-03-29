#include <iostream>
#include <map>
#include <string>

// Suppose the following class represents a node in a binary tree:
struct BinaryTreeNode {
  int val;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  BinaryTreeNode(int x, BinaryTreeNode *left_ptr, BinaryTreeNode *right_ptr)
      : val(x), left(left_ptr), right(right_ptr) {}
};
// Write a function that determines whether a given binary tree  is in fact a
// valid BST (i.e. it conforms to the BST definition). An empty binary tree is
// considered a valid BST.
//
// Implement this in .cc file
bool IsBST(BinaryTreeNode *root);
// BinaryTreeNode* cbt(const std::vector<int> &v);

//-----------------------------------------------------------------------------
// Given the root of a binary tree, we would like to find some statistical data
// about the tree. First, define a new enum type called Statistics that
// represents the following:

// kHeight: The height of the given tree.
// kNumberOfLeaves: Number of leaves.
// kMin: The minimum value in the tree.
// kMax: The maximum value in the tree.
// kNumberOfSingleChildNodes: Number of nodes with a single child.
// kNumberOfNodes: Number of nodes in the tree.

// Define this enum in this file (.h file).

enum Statistics{
  kHeight,
  kNumberOfLeaves,
  kMin,
  kMax,
  kNumberOfSingleChildNodes,
  kNumberOfNodes,
};

//-----------------------------------------------------------------------------
// Implement the following functions in the .cc file.
// Using the Statistics enum type, we would like to find the statistics about a
// given binary tree.

// In your implementation, each node in the tree should be visited exactly once.

// Returns the statistics for the given tree. The result map has one entry for
// each possible type of the Statistics enum type. This function is not
// recursive. Instead, it calls FindStatistics_Helper. 👉 Hint: Implement it
// using the following steps:
// 1. Define an object of type std::map<Statistics, int>. Call it result, and
// initialize it with appropriate values.
// 2. Call FindStatistics_Helper with appropriate parameters including the
// result parameter.
// 3. Return the result variable.
std::map<Statistics, int> FindStatistics(BinaryTreeNode *root);

// A helper function used by FindStatistics. It takes the root and statistics as
// inputs, and fills out the entries for statistics.
// 👉 Hint: This is a recursive function.
// current_level represents the level of the node that is currently being
// visited in the original binary tree and should be updated to the correct
// value each time we call this function. In your implementation, each node in
// the tree should be visited exactly once.
void FindStatistics_Helper(BinaryTreeNode *root, int current_level,
                           std::map<Statistics, int> &statistics);


