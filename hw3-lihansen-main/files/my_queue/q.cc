#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.


//copy constructor
Queue::Queue(const Queue & rhs){
    this->v_ = std::vector <int> {rhs.get_data()}; 
}

// insert back
bool Queue::Enqueue(int value){
    this->v_.push_back(value);
}

// remove front
bool Queue::Dequeue(){
    if (this->v_.size()==0){
        return false;
    }
    
    int res = this->v_[0];
    for(int i = 0; i< this->v_.size()-1;i++){
        this->v_[i] = this->v_[i+1];
    }
    this->v_.pop_back();
    return true;
}


// is empty
bool Queue::IsEmpty(){
    return (this->v_.size() == 0);
}


//return the first elem val
int Queue::Front(){
    if (this->v_.size() == 0)
    return -1;

    return this->v_[0];
}

// get data
std::vector <int> Queue::get_data() const{
    return this->v_;
}