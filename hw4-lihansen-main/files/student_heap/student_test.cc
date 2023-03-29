#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

// ################### Student ##################

TEST(MyTest, MyTest_Student_constructor_Test) {
    Student stu1 = Student("s1", 0);
    Student stu2 = Student();

    Student stu1_copy = Student(stu1);

    EXPECT_EQ(stu1, stu1_copy);
    EXPECT_EQ(stu2.grade, INT8_MIN);
    EXPECT_EQ(stu2.name, "NO_NAME");
}

TEST(MyTest, MyTest_Student_operator_Test) {
    Student stu1 = Student("s1", 100);
    Student stu2 = Student("s2", 0);
    Student stu3 = Student("s3", 100);

    EXPECT_EQ(stu1 > stu2, true);
    EXPECT_EQ(stu1 < stu2, false);
    EXPECT_EQ(stu1 == stu2, false);
    EXPECT_EQ(stu1 == stu3, true);


}

// ############### StudentMaxHeap ###############

TEST(MyTest, MyTest_StudentMaxHeap){
    std::vector<Student> input = {
        Student("s", 3),
        Student("s", 2),
        Student("s", 1),
        Student("s", 5),
        Student("s", 0),
    };
    // constructor & convertToHeap & TirckleDown
    StudentMaxHeap stu_max_heap = StudentMaxHeap(input);
    EXPECT_EQ(stu_max_heap.top(), Student("s", 5));

    // getleftindex & getrightindex
    int root = 0;
    auto left_index = stu_max_heap.GetLeftIndex(root);
    auto right_index = stu_max_heap.GetRightIndex(root);
    EXPECT_EQ(left_index, 2*root + 1);
    EXPECT_EQ(right_index, 2*root + 2);

    // getleft & getright
    auto left_child = stu_max_heap.GetLeft(root);
    auto right_child = stu_max_heap.GetRight(root);
    EXPECT_EQ(stu_max_heap.GetData()[root*2+1], left_child);
    EXPECT_EQ(stu_max_heap.GetData()[root*2+2], right_child);

    //getparent
    EXPECT_EQ(stu_max_heap.GetParent(root), Student());
    EXPECT_EQ(stu_max_heap.GetParent(left_index), stu_max_heap.top());
    EXPECT_EQ(stu_max_heap.GetParent(right_index), stu_max_heap.top());

    //getparentindex
    EXPECT_EQ(stu_max_heap.GetParentIndex(left_index), root);
    EXPECT_EQ(stu_max_heap.GetParentIndex(right_index), root);

    // push & trickleup
    Student max_grade = Student("s", 100);
    stu_max_heap.push(max_grade);
    EXPECT_EQ(stu_max_heap.top(), max_grade);

    // pop
    int prev_size = stu_max_heap.size();
    EXPECT_EQ(stu_max_heap.pop(), true);
    EXPECT_EQ(stu_max_heap.size(), prev_size-1);
}


// ################ HeapSort #####################

TEST(MyTest, HeapSort){
    std::vector<Student> input = {
        Student("s", 3),
        Student("s", 2),
        Student("s", 1),
        Student("s", 5),
        Student("s", 0),
    };
    HeapSort(input);

    EXPECT_EQ(input[0], Student("s", 0));
    EXPECT_EQ(input[1], Student("s", 1));
    EXPECT_EQ(input[2], Student("s", 2));
    EXPECT_EQ(input[3], Student("s", 3));
    EXPECT_EQ(input[4], Student("s", 5));


}