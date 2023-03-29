
# HW3 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, March 1st by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 28 |
| 2  | 15 |
| 3  | 30 |
| 4  | 32 |
| 5  | 30 |


- Total: 135 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

**output:**   
---------------------------------------------------------------  

Q1  
Non-parameterized constructor  **//create MyClass calls the o1 constructor function**  

o1.v_.size(): 0  **//after creating o1, its member v_ initialized but no assignment, so the size is 0.**  
Destructor  **//o1 is a local varibale in the '{ }' area, so it should be destroyed out of this area, the destructor called.**  
---------------------------------------------------------------  
Q2  
Non-parameterized constructor **//o1 constructor**  
Parameterized constructor **//o1 parameterized constructor**  
Copy constructor **//copy constructor called, line #46**  
Destructor **//after '{ }', the local variables:o1,o2,o3 destroyed.**  
Destructor  
Destructor  
---------------------------------------------------------------
Q3  
Non-parameterized constructor **//o created by the non-para constructor, line #22**  
Copy constructor  **//because o was used as the parameter of the function ‘DoSomthing1', the value of o transfer into the function, so the copy constructor called**  
Something 1. **//the output of function 'DoSomething1'**  
Destructor **//when the function ends, the copy of o will be destroyed**
Destructor **//life of o ends after '{}' destroyed**  
---------------------------------------------------------------
Q4  
Non-parameterized constructor **//o created**  
Something 2. **// the output from 'DoSomething2' because the parameter of 'DoSomething2' is a reference & type, so o transfer into the function directly without any copy.**  
Destructor  **// variable o destroyed after the '{}' area.**  
---------------------------------------------------------------
Q5  
Non-parameterized constructor  **//o created**    
Something 3. **// the output from 'DoSomething3'. because the parameter of 'DoSomething3' is a reference & type, so o transfer into the function directly without any copy.**  
Destructorr  **// variable o destroyed after the '{}' area.**     
---------------------------------------------------------------
Q6  
Non-parameterized constructor **//o created**    
Copy constructor **// in the function 'DoSomething4', the parameter of the function is reference type, there is a new local variable o2 created by copy the value of o, so copy constructor of o2 called.**    
Something 4. **//output of function**    
Destructor **//destroy o2 after leaving the funciton dosomething4.**    
Destructor **//destroy o after leaving the '{}' area.**    
---------------------------------------------------------------
Q7  
Parameterized constructor **//'MyClass(1,2)' constructor**    
Copy constructor **//the std::pair internally copy the object 'MyClass(1,2)' when assign the value.**   
Destructor **//'MyClass(1,2)' destroyed after using**    
p1.first.v_.size(): 0 **//the size of the first elem in p1, because the v_ has never assigned, the size equals to 0**    
p1.second: 0 **//the value of the second elem of p1 is 0**   
Copy constructor **// the first elem of p2 copied from the first elem of p1, so the copy constructor called**    
p2.first.v_.size(): **// no assignments, so the lenth of v_ is 0**     
p2.second: 0 **// the same value with the second elem of p1**    
Destructor **//the life of p1 ends when leaving the {} area.**  
Destructor **// the life of p2 ends when leaving the {}**    
---------------------------------------------------------------
Q8  
Parameterized constructor **//initialized 'MyClass(1,2)'**    
Copy constructor **//the std::pair internally copy the object 'MyClass(1,2)' when assign the value**  
Destructor **//'MyClass(1,2)' destroyed after using for assigning value**    
Something 2. **//the for loop run 3 iterations because the second elem of p init with the value of 0 and ends at the value of 3**     
Something 2.  
Something 2.  
Destructor **//local variable p was destroyed after for loop**  
---------------------------------------------------------------
Q9  
Parameterized constructor **//constructor of the 'new MyClass(1,2)'**    
**// the destructor is not called because there is a pointer o points to 'MyClass(1,2)', but the pointer destroyed after using. it is a problem called memory leak.**    
---------------------------------------------------------------
Q10  
Parameterized constructor **//'MyClass(1,2)**    
Destructor **//the destructor is called because we manually use 'delete' to free the mem that o points to.**    
---------------------------------------------------------------
Q11  
Non-parameterized constructor **//'MyClass()'.**  
Copy constructor   **//copy 'MyClass()' when init the pair '{0, MyClass()}'**   
Parameterized constructor **//'MyClass(1,2)'**    
Copy constructor      **//copy 'MyClass(1,2)' when init the pair '{0, MyClass(1,2)}'**    
Parameterized constructor **//'MyClass(3,4)'**     
Copy constructor  **//copy 'MyClass(3,4)' when init the pair '{0, MyClass(3,4)}'**     
Copy constructor  **//std::map internally copy each value of  when assign the value**    
Copy constructor **//std::map internally copy 'MyClass(1,2)' when assign the value**    
Copy constructor **//std::map internally copy 'MyClass(1,2)' when assign the value**    
Destructor **//destroy each temprary variables above after assigning my_map**  
Destructor    
Destructor  
Destructor  
Destructor  
Destructor  
Copy constructor **// copy e from may_map in one loop**    
Destructor **// destroy e after using in one loop**     
Copy constructor **//iter2**    
Destructor    
Copy constructor **//iter3**    
Destructor    
Destructor **//destroy local variable in insert function**   
Destructor    
Destructor    
---------------------------------------------------------------
Q12  
Non-parameterized constructor **// 'MyClass()'**   
Copy constructor **//copy and assign into the pair '{0, MyClass()}'**    
Parameterized constructor **//'Myclass(1,2)'**    
Copy constructor  **//copy for {3, myclass}**    
Parameterized constructor **// 'myclass(3,4)'**    
Copy constructor **//copy for {5, myclass(3,4)}**     
Copy constructor **//copy when insert into my_set in one loop**  
Copy constructor  
Copy constructor  
Destructor **//reference &e, no copy constructors needed**   
Destructor **//destroy local varibale in my_set.insert function**    
Destructor    
Destructor  
Destructor  
Destructor  
Destructor    
Destructor    
Destructor    
---------------------------------------------------------------
Q13  
Parameterized constructor **//constructor of 'MyClass(1,2)**  
Destructor **//destroy when delete o, because o was assign to point to MyClass(1,2)**   
---------------------------------------------------------------
Q14  
Parameterized constructor **//'MyClass o(100000000)'**  
Operation took: 1600 milliseconds **//duration of creating 'MyClass o(100000000)'**  
Copy constructor **//two times for loop, copy o as the value of o2**  
Copy constructor **// copy o2's value as the parameter of dosomething1 function**  
Something 1. **// output of the function**  
Destructor  **// local variable dies after using in dosomething1 function**  
o2.v_.size(): 100000000  **//cout**  
Destructor **//local variable o2 destroyed**  
Copy constructor **//loop 2, same as 1 above**  
Copy constructor  
Something 1.  
Destructor  
o2.v_.size(): 100000000  
Destructor  
Operation took: 1167 milliseconds **//duration of two times loop**  
Destructor **// life of o(100000000) ends**  
---------------------------------------------------------------
Q15  
Parameterized constructor
Operation took: 1689 milliseconds
Copy constructor **//most are the same with the Q14 above, but the function dosomething2 uses reference type parameters, so there are less calling of copy constructors.** 
Something 2. 
o2.v_.size(): 100000000
Destructor
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Operation took: 593 milliseconds **// because of using reference as the parameter in the function, the time consuming is much lower than the one calling copy constructors.**    
Destructor
---------------------------------------------------------------
Q16  
Parameterized constructor **//initial MyClass for assigning values to my_vector**  
Parameterized constructor  
Parameterized constructor  
Parameterized constructor  
Parameterized constructor  
Parameterized constructor  
Parameterized constructor  
Copy constructor  **// copy for assiging my_vector**  
Copy constructor  
Copy constructor  
Copy constructor  
Copy constructor  
Copy constructor  
Copy constructor  
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
Operation took: 5628 milliseconds **//time cost of init my_vector**  
Copy constructor  **//copy one elem of my_vector as e in one loop**  
e.v_.size(): 10000000  
Destructor  
Copy constructor  
e.v_.size(): 20000000  
Destructor  
Copy constructor  
e.v_.size(): 30000000  
Destructor  
Copy constructor  
e.v_.size(): 40000000  
Destructor  
Copy constructor  
e.v_.size(): 50000000  
Destructor  
Copy constructor  
e.v_.size(): 60000000  
Destructor  
Copy constructor  
e.v_.size(): 70000000  
Destructor  
Operation took: 900 milliseconds  **//time cost of the for loop above**  
e.v_.size(): 10000000   
e.v_.size(): 20000000  
e.v_.size(): 30000000  
e.v_.size(): 40000000  
e.v_.size(): 50000000  
e.v_.size(): 60000000  
e.v_.size(): 70000000  
Operation took: 0 milliseconds  **// because using the reference of e in this for loop, no local variable created by copy constructor, so the the cost of time is approaching 0, which is much faster than the previous one.**   
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
Destructor  
---------------------------------------------------------------
Done!