#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// Suppose the following class represents a node in a binary tree:


bool IsBST(BinaryTreeNode *root){
  if (root == nullptr) return true;
  if (root->left != nullptr and root->left->val > root->val) return false;
  if (root->right != nullptr and root->right->val < root->val) return false;
  return IsBST(root->left) and IsBST(root->right);
}


std::map<Statistics, int> FindStatistics(BinaryTreeNode *root){
  std::map<Statistics, int> result={
    std::pair<Statistics, int>(kHeight, 0),
    std::pair<Statistics, int>(kNumberOfLeaves, 0),
    std::pair<Statistics, int>(kMin, INT32_MAX),
    std::pair<Statistics, int>(kMax, INT32_MIN),
    std::pair<Statistics, int>(kNumberOfSingleChildNodes, 0),
    std::pair<Statistics, int>(kNumberOfNodes, 0)
  };
  FindStatistics_Helper(root, 1, result);
  return result;
}

// A helper function used by FindStatistics. It takes the root and statistics as
// inputs, and fills out the entries for statistics.
// 👉 Hint: This is a recursive function.
// current_level represents the level of the node that is currently being
// visited in the original binary tree and should be updated to the correct
// value each time we call this function. In your implementation, each node in
// the tree should be visited exactly once.
void FindStatistics_Helper(BinaryTreeNode *root, int current_level,
                           std::map<Statistics, int> &statistics){
                             statistics[kMin] = statistics[kMin] < root->val ? statistics[kMin] : root->val;
                             statistics[kMax] = statistics[kMax] > root->val ? statistics[kMax] : root->val;
                             statistics[kHeight] = std::max(statistics[kHeight], current_level);
                             statistics[kNumberOfNodes]++;
                             // leave nodes
                             if (root->left == nullptr and root->right == nullptr){
                               statistics[kNumberOfLeaves]++;
                             }else if (root->left == nullptr and root->right != nullptr)
                             {
                               statistics[kNumberOfSingleChildNodes] ++;
                               FindStatistics_Helper(root->right, current_level+1, statistics);
                             }else if (root->left != nullptr and root->right == nullptr){
                               statistics[kNumberOfSingleChildNodes] ++;
                               FindStatistics_Helper(root->left, current_level+1, statistics);
                             }else{
                               FindStatistics_Helper(root->left, current_level+1, statistics);
                               FindStatistics_Helper(root->right, current_level+1, statistics);
                             }
                           }