
// Define a new C++ enum type called Operation that has members for add,
// subtract, division, multiplication, bitwise AND, bitwise OR, bitwise XOR, shift
// right, and shift left (please use the following names: subtract, division, 
// multiplication, bitwise_AND, bitwise_OR, bitwise_XOR, shift_right, shift_left):
enum class Operation {
  add, subtract, division, multiplication, bitwise_AND, bitwise_OR, bitwise_XOR, shift_right, shift_left

};

class CPPLib {
 public:
  // Given two integers, returns the result of the operation based on the given
  // operator.
  float Calculate(int a, int b, Operation operation);
};
