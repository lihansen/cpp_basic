#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyVector, Test1) {
    //empty vector constructor
    MyVector mv1 = MyVector();
    // get_error
    EXPECT_EQ(ErrorCode::kNoError, mv1.get_error());
    // size 
    EXPECT_EQ(0, mv1.size());
    
    
    // constructor given size
    MyVector mv2= MyVector(3);
    std::vector <int> v2 = {0,0,0};
    // ConvertToStdVector
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);

    // copy constructor
    MyVector *mvp = new MyVector(mv2);
    // destructor
    delete mvp;

    //pushback
    mv2.push_back(5);
    v2.push_back(5);
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);

    //popback
    auto res1 = mv2.pop_back();
    v2.pop_back();
    auto res2 = mv1.pop_back(); //empty vector
    EXPECT_EQ(res1, 5);
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);
    EXPECT_EQ(res2, -1);


    //push_front
    mv2.push_front(5);
    v2.insert(v2.begin(), 5);
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);

    //pop_front
    auto res3 = mv2.pop_front();
    EXPECT_EQ(res3, 5);
    v2.erase(v2.begin());
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);

    // insert
    mv2.insert(9,2);
    v2.insert(v2.begin()+2, 9);
    EXPECT_EQ(mv2.ConvertToStdVector(), v2);

    mv2.insert(9,9);
    EXPECT_EQ(mv2.get_error(), ErrorCode::kIndexError);

    // at
    EXPECT_EQ(mv2.at(2), v2[2]);
    EXPECT_EQ(mv2.at(1000), -1);
    EXPECT_EQ(mv2.get_error(), ErrorCode::kIndexError);

    //find
    EXPECT_EQ(mv2.find(9), 2);
    EXPECT_EQ(mv2.find(8888), -1);
    EXPECT_EQ(mv2.get_error(), ErrorCode::kNotFound);
}
