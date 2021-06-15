The idea is straightforward: calculate N! and add the digits up.    
There are two main problems to deal with, 
* the time to calculate a factorial
* the number being too large for regular number types


#### Calculating many factorials

Rather than the naive solution of computing factorial for each test case (which is O(NT)), compute all factorials up to our constraint (1000)
and store the sum of the digits of each factorial in an array. 
Then, for each test case, we look up our answer in constant time (giving us O(T) for the entire problem).


#### Large number types

We can use our CustomInt class from previous problem. Then, the problem boils down to writing a multiplication algorithm for our CustomInt. 

My algorithm uses the fact that multiplication is repeated addition.    
That is, for m x n, this is equivalent to adding n m's together.  
Then, we use this in combination with a similar idea to repeated squaring to calculate exponents:
  * Represent the smaller term as a binary number
  * Initialize the "product" as 0
  * For each binary digit from right to left,
      * if the digit is 1, add the first term to the product. Otherwise, do nothing
      * Double the first term by adding the term to itself
      * Repeat

This function only works for integer values and small values of the second term (that can fit in built-in bit-representation number types).   
The runtime of this method is O(len(M) * log(N)). 

There are better methods that can support larger numbers and may be faster, 
but this method is simple implementation-wise, since it reuses the addition method.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/020%20-%20Factorial%20digit%20sum/solution.cpp)
#

https://en.wikipedia.org/wiki/Multiplication_algorithm
https://en.wikipedia.org/wiki/Exponentiation_by_squaring
