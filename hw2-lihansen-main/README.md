
# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, Feburary 15th by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 10 |
| 2  | 25 |
| 3  | 20 |
| 4  | 10 |
| 5  | 20 |
| 6  | 25 |
| 7  | 10 |
| 6  | 15 |

- Total: 135 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

#
# Answers:
5. Concatenate two dynamic arrays.  

Question 1: Why did we have to proved size_1, size_2 as an input?  
We have to provided them because they are array. The complier must know the size of array and allocate the memory space when initializing them. 

Question 2: How can we know the size of the output?  
The size of the output is the sum of sizes of two input arrays.  

Question 1: Why didn't we provide the sizes?  
This is because the std::vector object is a pointer which points to an address, and the size of the address allocation is allocated dynamically when using. 

Question 2: We have two functions with the name of Concatenate. Is this ok?  
This is ok because the functions with same name are called function overloading. The compolier distinguishes these function by checking their unique parameter list.  
# 
6.  What is wrong with each piece of code below?  
Q1: line 21: the memory of 'elements[i] did not initialized before input form 'cin'.   
Q2: line 28: 'a' is uninitialized before using.  
Q3: no error  
Q4: line 52, 53: the pointer 'a' and 'b' point to the memory address that has not been allocated before.   
Q5: line 63: modified the variable of loop so that the loop runs forever. 
