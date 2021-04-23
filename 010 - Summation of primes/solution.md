### Naive
As with previous problems, we want to generate primes. This time, we terminate when our index is greater than N. 
Our answer is in the form of the sum of the previously generated primes, so we should keep track of the sum while generating.

```
sum = 0
for i := 2 to N:
  if i is prime:
    sum += i
return sum
```


### Improvements

So with many test cases, we cannot afford to recompute the primes every single time for each test case. 
The list of primes does not tell us right away which primes our less than some arbitrary N and a naive method would be to perform linear search.
Furthermore, when we find which prime is our bound, we must sum up the previous primes everytime.

#### Prefix sum
We can precompute each sum of primes in linear time by updating the next sum as the sum of the previous sum and the current term.

#### Binary Search
To find which sum is required, we return the largest sum whose last prime is the greatest prime that less than or equal to N.
To do this, we can take our prefix sum list, and have a key that is the last prime in the sum.

Then, we can perform binary search on this list for N where we look for the greatest number that is less than or equal to N.

##
With these two improvements, we reduce the problem from O(N) search for each test case to O(log N).

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/010%20-%20Summation%20of%20primes/solution.cpp)
