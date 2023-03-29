#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyTest, BST) {
    BinaryTreeNode *root = new BinaryTreeNode(5);
    EXPECT_EQ(IsBST(root), true);
    EXPECT_EQ(IsBST(nullptr), true);
    root->right = new BinaryTreeNode(6);
    root->left = new BinaryTreeNode(4);
    EXPECT_EQ(IsBST(root), true);

    root->right->left = new BinaryTreeNode(7);
    

//      5
//    4   6
//       7



    EXPECT_EQ(IsBST(root), false);
    root->right->left = nullptr;
    root->right->right = new BinaryTreeNode(7);
//      5
//    4   6
//          7
    auto stat = FindStatistics(root);
    EXPECT_EQ(stat[kHeight], 3);
    EXPECT_EQ(stat[kNumberOfLeaves], 2);
    EXPECT_EQ(stat[kMin], 4);
    EXPECT_EQ(stat[kMax], 7);
    EXPECT_EQ(stat[kNumberOfSingleChildNodes], 1);
    EXPECT_EQ(stat[kNumberOfNodes], 4);

}
