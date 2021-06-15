### Generating Amicable Numbers

We can iterate through all numbers up to our constraint and test which are amicable. 

Let S(n) = the sum of the proper divisors of n.
For the current number a, we find S(a) = b, make sure a &ne; b, then we compute S(b) to see if it is equal to a.  
We can store our numbers that are amicable so that we can skip the complement when we encounter them.

#### Sum of Proper Divisors

The sum of proper divisors of n is the sum of divisors minus the number n. 

The method of summing divisors uses a method similar to something used in [013](https://github.com/zhaohanson1/project_euler_plus/blob/master/012%20-%20Highly%20divisible%20triangular%20number/solution.md#faster-divisors--factorization). 

##### Sum of Divisiors of Prime Powers

The sum of the divisors of a prime power, p<sup>k</sup>, is the sum the powers of the prime up to k. That is,
<div align="center">
  <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\sigma_1(p^k)&space;=&space;1&space;&plus;&space;p&space;&plus;&space;p^2&space;&plus;&space;\ldots&space;&plus;&space;p^k&space;=&space;\sum_{n=0}^k&space;p^n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\sigma_1(p^k)&space;=&space;1&space;&plus;&space;p&space;&plus;&space;p^2&space;&plus;&space;\ldots&space;&plus;&space;p^k&space;=&space;\sum_{n=0}^k&space;p^n" title="\sigma_1(p^k) = 1 + p + p^2 + \ldots + p^k = \sum_{n=0}^k p^n" /></a>
</div>

As we can see, this is a geometric progression, so we can use the geometric series equation, 
<div align="center">
  <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\begin{align*}&space;\sum_{n=0}^{k}&space;p^n&space;&=&space;\sum_{n=0}^{k&plus;1}&space;p^{n-1}&space;\\&space;&=&space;\frac{1-p^{k&plus;1}}{1-p}&space;\\&space;&=&space;\frac{-1(p^{k&plus;1}-1)}{-1(p-1)}&space;\\&space;&=&space;\frac{p^{k&plus;1}-1}{p-1}&space;\end{align*}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\begin{align*}&space;\sum_{n=0}^{k}&space;p^n&space;&=&space;\sum_{n=0}^{k&plus;1}&space;p^{n-1}&space;\\&space;&=&space;\frac{1-p^{k&plus;1}}{1-p}&space;\\&space;&=&space;\frac{-1(p^{k&plus;1}-1)}{-1(p-1)}&space;\\&space;&=&space;\frac{p^{k&plus;1}-1}{p-1}&space;\end{align*}" title="\begin{align*} \sum_{n=0}^{k} p^n &= \sum_{n=0}^{k+1} p^{n-1} \\ &= \frac{1-p^{k+1}}{1-p} \\ &= \frac{-1(p^{k+1}-1)}{-1(p-1)} \\ &= \frac{p^{k+1}-1}{p-1} \end{align*}" /></a>
 </div>

##### Sum of Divisors is Product of the Sum of Divisors of Prime Powers

Example: S(12) = S(2<sup>2</sup>) * S(3) = (1+2+4) * (1+3) = (1+3+2+6+4+12) = (1+2+3+4+6+12)

More generally, suppose we have the sum of each prime factor power of N, S(p1^k1), S(p2^k2), ...

Each divisor of N is made of some product of the prime factors to some power. 
We can treat the sum as a list of the powers of the prime if we expand out the terms (as seen in the example).
Then, we can any divisor by taking the product of some term from each list. 
This can be seen when we take the product of the sums. 
When distributing each term, we generate all divisors that is divisible by that term, and continuing lets us generate all divisors.

##### Finding the Divisors

We can generate prime numbers and iterate through the primes to get the factor and multiplicity of each number.

### Finding the sum of Amicable Numbers under N

When finding the amicable numbers, keep track of the order. Then, we can take the prefix sum of the numbers, and binary search for the largest number below N.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/021%20-%20Amicable%20Numbers/solution.cpp)


## Further Reading

https://en.wikipedia.org/wiki/Divisor_function

https://en.wikipedia.org/wiki/Geometric_progression
