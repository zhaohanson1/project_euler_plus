# Plus

The problem requires us to decide if a given number can be expressed as a sum of two abundant numbers. 
We can view this as a variant of the Two Sum problem, where our query is the target and the abundant numbers are our set of numbers.

### Generating Abundant Numbers

An abundant number is a number that is larger than the sum of its proper divisors. 
We already have a method of finding the sum of proper divisors from 
[021](https://github.com/zhaohanson1/project_euler_plus/blob/master/021%20-%20Amicable%20Numbers/solution.md#sum-of-proper-divisors).
Note that "all integers greater than 28123 can be written as the sum of two abundant numbers", so we only need to generate numbers up to 28123.

### Sum of Two Abundant Numbers

Using ideas from Two Sum, if we store our abundant numbers in a set, for a given target number x,
we can iterate through all the abundant numbers a, and check if the complement x-a is in the set in constant time.

The overall runtime for a query is O(n), where n is the number of abundant numbers (less than 28123).

If a number is greater than 28123, we can immediately say that this number can be expressed as a sum of two.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/023%20-%20Non-abundant%20sums/solution.cpp)

# Classic

We can modify the solution from plus: instead of taking queries, we iterate through all numbers up to 28123. If the number isn't abundant, we add to the sum.

[Solution Classic](https://github.com/zhaohanson1/project_euler_plus/blob/master/023%20-%20Non-abundant%20sums/solution-classic.cpp)
