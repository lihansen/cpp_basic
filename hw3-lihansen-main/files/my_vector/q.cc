#include "q.h"

#include <iostream>
#include <vector>

// Implement each function of `q.h` here.



int MyVector::get_data(int i ) const{
  return this->data_[i];
}

// private
void MyVector::check_alloc_mem(){
  while(this->size_ > this->capacity_){
    this->capacity_ += this->increasement_;
  }
  int * new_data = new int [this->capacity_];
  for(int i = 0; i< this->size_; i++){
    // this->size_++;
    new_data[i] = this->data_[i];
  }
  int *q = this->data_;
  this->data_ = new_data;
  if (*q){
    delete q;
  }
}


//
MyVector::MyVector(){
    this->capacity_ = 0 + this->increasement_;
    this->data_ = new int[this->capacity_];
    this->size_ = 0;
    // this->check_alloc_mem();
    this->error_ = ErrorCode::kNoError;
}


// 
MyVector::MyVector(int size){
  this->capacity_ = 0 + this->increasement_;
  this->data_ = new int[this->capacity_];
  this->check_alloc_mem();
  for (int i = 0; i < size; i++)
  {
    this->data_[i] = 0;
  }
  this->size_ = size;

  this->error_ = ErrorCode::kNoError;
}


// //
MyVector::MyVector(const MyVector& rhs){
  this->capacity_ = 0 + this->increasement_;
  this->data_ = new int[this->capacity_];

  this->check_alloc_mem();

  this->size_ = rhs.size();
  for (int i = 0; i < this->size_; i++)
  {
    /* code */
    data_[i] = rhs.get_data(i);
    // data_[i] = rhs.at(i);
  }
  this->error_ = rhs.get_error();

}


// destructor
MyVector::~MyVector(){
  delete [] this->data_;
  // delete this->size_;
  // delete this->error_;
}


// //
void MyVector::push_back(int value){
  this->size_++;
  this->check_alloc_mem();
  this->data_[this->size_-1] = value; 
}

// //
int MyVector::pop_back(){
  if(this->size_ == 0){
    this->error_ = ErrorCode::kPopFromEmptyVector;
    return -1;
  }
  return this->data_[--this->size_];
}

// //
void MyVector::push_front(int value){
  this->size_++;
  this->check_alloc_mem();
  for (int i = 1; i < this->size_; i++)
  {
    this->data_[i] = this->data_[i-1];
  }

  this->data_[0] = value;
  this->error_ = ErrorCode::kNoError;
}


// //
int MyVector::pop_front(){
  if (this->size_ == 0){
    this->error_ = ErrorCode::kIndexError;
  }

  
  int res = this->data_[0];
  for (int i = 1; i < this->size_; i++)
  {
    this->data_[i-1] = this->data_[i];
  }
  this->size_--;
  this->error_ = ErrorCode::kNoError;
  return res;
  
}

// 
void MyVector::insert(int value, int index){

  if (index < 0 or index >= this->size_){
    this->error_ = ErrorCode::kIndexError;
    return;
  }
  this->size_++;
  this->check_alloc_mem();

  for (int i = index; i < this->size_; i++)
  {
    this->data_[i+1] = this->data_[i];
  }
  this->data_[index] = value;
  this->error_ = ErrorCode::kNoError;

}

// //
int MyVector::at(int index){
  if (index >= this->size_ or index < 0){
    this->error_ = ErrorCode::kIndexError;
    return -1; 
  }

  this->error_ = ErrorCode::kNoError;
  return this->data_[index];

}

// //
int MyVector::find(int item){
  for (int i = 0; i < this->size_; i++)
  {
    /* code */
    if(this->at(i) == item){
      this->error_ = ErrorCode::kNoError;
      return i;
    }
  }
  this->error_ = ErrorCode::kNotFound;
  return -1;
  
}

//
ErrorCode MyVector::get_error() const{
  return this->error_;
}

// size
int MyVector::size() const{
  return this->size_;
}

// //
std::vector<int> MyVector::ConvertToStdVector(){
  std::vector<int> stdvec = {};
  for (int i = 0; i < this->size_; i++)
  {
    stdvec.push_back(this->data_[i]);
  }
  this->error_ = ErrorCode::kNoError;
  return stdvec;
}