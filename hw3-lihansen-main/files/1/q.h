#include <iostream>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------
// Implement your own vector class called MyVector!
//-----------------------------------------------------------------------------
enum class ErrorCode {
  kNoError,
  kPopFromEmptyVector,
  // If there is an attempt to access an invalid index
  kIndexError,
  kNotFound
};
//-----------------------------------------------------------------------------
// All functions must set the error_ to an appropriate value.
// TODO: Implement these functions in q.cc.
class MyVector {
 public:
  // Creates an empty vector.
  MyVector();

  // Creates a vector of the given size.
  MyVector(int size);

  // Copy constructor.
  MyVector(const MyVector& rhs);

  // Destructor.
  ~MyVector();

  // Inserts the given value at the back of the vector.
  void push_back(int value);

  // Removes and returns a value from the backs of the vector.
  int pop_back();

  // Inserts the given value at the front of the vector.
  void push_front(int value);

  // Removes and returns a value from the front of the vector.
  int pop_front();

  // Inserts the given value after the given index.
  void insert(int value, int index);

  // Returns item at the given index.
  int at(int index);

  // Returns the first index of the given item in the vector. Returns -1 if not
  // found.
  int find(int item);

  // Returns the value of error_
  ErrorCode get_error() const;

  // Returns the value of size_
  int size() const;

  // Converst to std::vector. Used for testing.
  std::vector<int> ConvertToStdVector();

  // get data for const
  int get_data(int i) const;
  void check_alloc_mem();

 private:
  int* data_;
  int size_;
  int capacity_;
  const int increasement_ = 10;
  ErrorCode error_;


};
