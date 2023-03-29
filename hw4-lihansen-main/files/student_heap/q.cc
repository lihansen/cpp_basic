#include "q.h"

#include <iostream>
#include <vector>
Student::Student(std::string name, int grade){
    this->name = name;
    this->grade = grade;
}

Student::Student(){
    this->name = "NO_NAME";
    this->grade = INT8_MIN;
}

Student::Student(const Student& rhs){
    this->name = rhs.name;
    this->grade = rhs.grade;
}


// The following operators are overloaded. They only compare the grade part of
// the class with other objects.

// Returns true if grade is less than the grade of other Student objects and
// false otherwise.
bool Student::operator<(const Student& rhs) const{
    return (this->grade < rhs.get_grade());

}

// Returns true if grade is greater than the grade of other Student objects
// and false otherwise.
bool Student::operator>(const Student& rhs) const{
    return  (this->grade >  rhs.get_grade());

}

// Returns true if grade is equal to the grade of other Student objects and
// false otherwise.
bool Student::operator==(const Student& rhs) const{
    return this->grade == rhs.get_grade();
}




//*********************StudentMaxHeap Implementation*************************



// Parameterized constructor: creates a max heap from the given input.
StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input){
    this->data_ = input;
    ConvertToHeap(input);
}

// Returns the parent of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetParent(int i){
    if (i <= 0 or i >= this->size())return Student(); 
    return this->data_[(i-1) / 2];
}

// Returns the left child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetLeft(int i){
    if (i < 0 or 2*i + 1 >= this->size()) return Student();
    return this->data_[2*i + 1];
}

// Returns the right child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetRight(int i){
    if (i < 0 or 2*i + 2 >= this->size()) return Student();
    return this->data_[2*i + 2];
}

// Returns the index of the parent of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetParentIndex(int i){
    if (i <= 0 or i >= this->size()) return INT8_MAX;
    return (i-1) / 2;
}

// Returns the index of the left child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLeftIndex(int i){
    int left = 2*i +1;
    if (i >= 0 and left < this->size()) return left;
    return INT8_MAX;
}

// Returns the index of the right child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetRightIndex(int i){
    int right = 2*i + 2;
    if (i >= 0 and right < this->size()) return right;
    return INT8_MAX;
}

// Returns the index of the largest child of a node given its index in the
// tree. Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLargestChildIndex(int i){
    if (i<0 or i >= this->size())return INT8_MAX; // i out of range

    int left = 2*i + 1;
    int right = left +1;
    if (left >= this->size()){ // childs not exist
        return INT8_MAX;
    }else{
        if (right >= this->size()){ // only left child exists
            return left;
        }else{
            Student l_child = this->data_[2*i +1];
            Student r_child = this->data_[2*i +2];
            if (l_child < r_child){
                return right;
            }else{
                return left;
            }
        }
    }
}

// Returns the top of the heap. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::top(){
    if (this->size() == 0){
        return Student();
    }else{
        return data_[0];
    }
}

// Adds a new Student to the heap.
void StudentMaxHeap::push(const Student& student){
    data_.push_back(student);
    TrickleUp(data_.size()-1);  
}

// Removes the top. Returns
// true if successful and false otherwise.
bool StudentMaxHeap::pop(){
    if (this->size() == 0){
        return false;
    }else{
        data_.erase(data_.begin());
        return true;
    }
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleUp(int i){
    while (i != 0 and this->GetParent(i) < data_[i]){
        Student temp = data_[i];
        data_[i] = data_[GetParentIndex(i)];
        data_[GetParentIndex(i)] = temp;
        i = GetParentIndex(i);

    }
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleDown(int i){
    if(GetLeftIndex(i) >= size() and GetRightIndex(i) >= size()) return;
    int largest_child_index = GetLargestChildIndex(i);

    if (data_[i] < data_[largest_child_index]){
        // swap
        Student temp = data_[i];
        data_[i] = data_[largest_child_index];
        data_[largest_child_index] = data_[i];

        TrickleDown(largest_child_index);
    }
}

// Converts the given input into a max heap and stores that into data_.
void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input){
    for(int i=data_.size()/2 -1; i >=0; i--){
        TrickleDown(i);
    }
}


// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades.
void HeapSort(std::vector<Student>& input){
    
    // create heap
    int end = input.size() -1;
    for (int i=input.size()/2 -1; i >= 0; i --){

        int father = i;
        int child = 2*father +1;
        while (child <= end){
            // child = max(left_child, right_child) if right child exist
            if (child + 1 <= end and input[child] < input[child + 1]){
                child ++;
            }
            if (input[father] > input[child]){
                break;
            }else{
                Student temp = input[father];
                input[father] = input[child];
                input[child] = temp;

                father = child;
                child = father * 2 +1;
            }
        }
    }
    

    // move max head to tail, then recreate the heap

    for (int i = end; i >= 1; i--){
        Student temp = input[0];
        input[0] = input[i];
        input[i] = temp;
        int end = i-1;
        int father = 0;
        int child = 2*father +1;
        while(child <= end ){
            if (child +1 <= end and input[child] < input[child + 1]){
                child ++;
            }
            if (input[father] > input[child]){
                break;
            }else{
                Student temp = input[father];
                input[father] = input[child];
                input[child] = temp;
                father = child;
                child = 2*father + 1;
            }
        }
    }



}