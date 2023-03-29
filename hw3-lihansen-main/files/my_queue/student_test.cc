#include <iostream>
#include <string>


#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(Queue, all_functions) {
    Queue q = Queue();
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    std::vector <int> expect_vec1 = {1,2,3};
    EXPECT_EQ(q.get_data(), expect_vec1);

    EXPECT_EQ(q.Dequeue(), true);
    std::vector <int> expect_vec2 = {2,3};
    EXPECT_EQ(q.get_data(), expect_vec2);

    EXPECT_EQ(2, q.Front());

    EXPECT_EQ(q.IsEmpty(), false);

    Queue copy_q = Queue(q);
    EXPECT_EQ(copy_q.get_data(), expect_vec2);
}


TEST(Queue, empty) {
    Queue q = Queue();
    
    EXPECT_EQ(q.IsEmpty(), true);

    EXPECT_EQ(q.Dequeue(), false);

    EXPECT_EQ(q.Front(), -1);

    std::vector <int> expect_vec1 = {};
    EXPECT_EQ(q.get_data(), expect_vec1);

}