The main issue with the problem is dealing with large integers that will not fit in standard number types.  
We will use our CustomInt class to deal with this. We only need addition, which we already implemented, 
and the length of a number, which can be found by taking the size of the data structure that holds our digits.

We want to generate Fibonacci numbers until we reach our upper bound constraint of 5000 digits.

### Querying

For each query, we return the order of the first term with N digits. 
So, when generating Fibonacci numbers, we want to keep track of the first time the number of digits exceeds the current number of digits.  

(Note that we can only increase by at most 1 digit. If we could increase by more than 1 digit, then we must have carried over at least 10 in the addition algorithm,
but we only carry at most 1.)

As we generate and check the Fibonacci numbers, we store the order in a seperate array.   
We start with "1" in the 0th idx, then "7" in the 1st idx (because F_7 = 13), and so on.  
We see that the (n-1)th index contains the order of the first term with n digits.   
Thus, the time complexity for each query is O(1).


[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/025%20-%20N-digit%20Fibonacci%20number/solution.cpp)
