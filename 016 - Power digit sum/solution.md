### Memoization

In order to avoid recomputing a term, we will compute all powers of 2, from N = 1 to N = 1000, and store the sum of the digits of each term.
This is because 2<sup>N</sup> = 2 * 2<sup>N-1</sup>. Then, for each test case, we can simply lookup the corresponding result.

### Large terms

Like the previous problems involving large numbers, large powers of 2 will not fit in standard number types.
We can use our previous implementation of large numbers from [Large Sum](https://github.com/zhaohanson1/project_euler_plus/tree/master/013%20-%20Large%20Sum).
Then, when computing powers of 2, to get the next term, we can simply add the current term with itself, avoiding having to create any new operation functions. 
Then, getting the sum of digits is simply adding up the digits of the term.

#

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/016%20-%20Power%20digit%20sum/solution.cpp)
