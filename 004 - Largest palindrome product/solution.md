Generate all palindromes using all possible products of two 3-digit numbers. This can be done with 2 for-loops and a palindrome check function.
This would usually be O(n2<sup>2n</sup>) with respect to number of bits per integer, but our search space is limited to 3-digit numbers and the largest palindrome that can be formed has at most a length of 6.

Sort the palindrome list so we can easily search through the list. 
Instead of linearly searching for our candidate number, we can perform binary search on our palindrome list and return the largest number less than or equal to N.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/004%20-%20Largest%20palindrome%20product/solution.py)
