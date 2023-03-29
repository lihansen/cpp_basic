#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, Test1) {
    std::vector <int> v1 = {1,4,5,6,10};
    SinglyLinkedList sll = SinglyLinkedList(v1);

    //empty
    EXPECT_EQ(sll.empty(), false);

    //size
    EXPECT_EQ(sll.size(), v1.size());
    EXPECT_EQ(sll.convert_to_vector(), v1);

    //head
    ListNode *p = sll.head();
    EXPECT_EQ(p->val, 1);

    // push_back
    sll.push_back(9);
    v1.push_back(9);
    EXPECT_EQ(sll.convert_to_vector(), v1);

    //pop_back
    EXPECT_EQ(sll.pop_back(), true);
    v1.pop_back();
    EXPECT_EQ(sll.convert_to_vector(), v1);

    // getBackPointer
    ListNode *b = sll.GetBackPointer();
    EXPECT_EQ(b->val, v1[v1.size()-1]);

    //getIthPointer
    EXPECT_EQ(sll.GetIthPointer(100), nullptr );
    EXPECT_EQ(sll.GetIthPointer(-100), nullptr );
    EXPECT_EQ(sll.GetIthPointer(3)->val, v1[3]);

    //operator
    EXPECT_EQ(sll[100], -1);
    EXPECT_EQ(sll[-2], -1);
    EXPECT_EQ(sll[1], v1[1]);
    
    //print

    // erase
    sll.erase(4);
    v1.erase(v1.begin()+4);
    EXPECT_EQ(sll.convert_to_vector(), v1);
    sll.erase(0);
    v1.erase(v1.begin()+0);
    EXPECT_EQ(sll.convert_to_vector(), v1);

    // copy constructor
    SinglyLinkedList sll_copy = SinglyLinkedList(sll);
    EXPECT_EQ(sll_copy.convert_to_vector(), v1);

    // remove_duplicates
    sll.push_back(5);
    // sll.push_back(5);
    sll.remove_duplicates();
    EXPECT_EQ(sll.convert_to_vector(), v1);
    
}


TEST(SinglyLinkedList, pop_back){
    std::vector <int> v = {1,2};
    SinglyLinkedList sll = SinglyLinkedList(v);
    EXPECT_EQ(sll.convert_to_vector(), v);

    EXPECT_EQ(sll.pop_back(), true);
    v.pop_back();
    EXPECT_EQ(sll.convert_to_vector(), v);

    EXPECT_EQ(sll.pop_back(), true);
    v.pop_back();
    EXPECT_EQ(sll.convert_to_vector(), v);

    EXPECT_EQ(sll.pop_back(), false);
}

TEST(SinglyLinkedList, back){
    std::vector <int> v = {1};
    SinglyLinkedList sll = SinglyLinkedList(v);
    EXPECT_EQ(sll.convert_to_vector(), v);
    
    EXPECT_EQ(sll.back(), 1);

    sll.pop_back();
    v.pop_back();

    EXPECT_EQ(sll.back(), -1);
}

