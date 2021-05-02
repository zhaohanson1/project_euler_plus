### From single test to batch tests
If we only had one test, we would need to check all sequences that start at i for all i from 1 to N and we would keep track of the longest chain.
Then, suppose we wanted to check N+1 and we had already computed the longest chain starting at any number up to N.  
Compute the length of the sequence starting at N+1.  
If the length is less than the longest chain start up to N, then the longest up to N+1 is the same number.   
Otherwise, if the length is greater than or equal to the previous longest chains, the longest chain up to N+1 starts at N+1.   
Thus, as we iterate through all starting numbers, we can linearly update the starting number that produces the longest chain and memoize the values in an array.

Then, when we answer each test case, we can simply look up the answer in constant time.

### Efficiently computing length of all Collatz sequences
Clearly, any chain or subchain that starts with some number always generates the same sequence.  
So, we finish generating a sequence, we can store the length of the first starting number.  
Then, we can go to the next number and the length of this sequence is the length of the previous - 1, and so on.  

For example, the sequence starting at 13 is 
<div align='center'><b>13->40->20->10->5->16->8->4->2->1</b> </div>
and is of length 9.
Then, the starting at 40 is of length 8, starting at 20 is of length 7, ..., etc.  

Also, when generating a sequence, we may encounter a number that we have already generated the Collatz sequence.   
So, we had stored the length of this sequence and we can return the length of our current sequence as 
the length of the sequence we have computed up to plus the length of the reencounter sequence.

For example, suppose we were generating the sequence starting at 21:
<div align='center'><b>21 -> 64 -> 32 -> 16</b> </div>

If we look at the sequence 13, we have already seen sequence 16 which is of length 4.  
So, sequence 21 is of length 3 + 4 = 7.

### Putting the ideas together
We want to compute the lengths of all the Collatz sequence up to our constraint, 5 x 10^6.
As we compute, we can keep track of the length of the longest chain.
Then, for each test, we can check our memoization structure to find our answers.

### Very large terms
Sometimes, our terms may get very large such that the values exceed our size of our memoization structures. 
A possible solution is increasing the size of our structures, but this will use a lot more memory.

A hacky solution is to ignore trying to store or look up any values that exceed our constraint. 
The trade off is that we will always try to compute the sequence of any term larger than our constraint. 

##

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/014%20-%20Longest%20Collatz%20sequence/solution.cpp)
