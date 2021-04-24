### Naive
Generate the triangular numbers and count the divisors. Return the first triangular number that has more than N divisors.

```
current triangular number, X := 0
current triangular term, Y := 1

divisors := 0
while divisors < N do:
  divisors -> 0
  X += Y
  Y += 1
  for i := 1 to X:
    if X % i == 0:
      divisors++
end

output X
```

### Improvements

#### Faster Divisors / Factorization

We can limit our search for divisors down to sqrt(N) since each divisor d has a cofactor N/d and count this as 2 divisors.  
A special case occurs when N is a perfect square and d is the square of N; in this case we only count 1 divisor.  

If N becomes significantly large, this method may become more computationally heavy. Another way to get the number of divisors is with the formula,
 <div align='center'>
 <img src="https://latex.codecogs.com/gif.latex?\bg_white&space;d(n)&space;=&space;\prod_{p_i^{\alpha_i}&space;|&space;n}&space;(\alpha_i&space;&plus;&space;1)" title="d(n) = \prod_{p_i^{\alpha_i} | n} (\alpha_i + 1)" />
  </div>

This formula says that the number of divisors is equal to the product of the powers of the primes that divide n plus 1. 

That is, if we take the prime factorization of n, take the powers of the each prime, add 1, then multiply them all together to get the number of divisors. 

##### Formula Explanation
To give intuition on why this formula works, lets find the divisors of 12.  The prime factorization of 12 is **2, 2, 3**.   
For each prime, list out all possible prime powers given the number of primes available, i.e. 2 gives **(1, 2, 4)** and 3 gives **(1, 3)**.

If we take the product of each factor of one set with all other factors in the other set,
we get (1\*1, 1\*3, 2\*1, 2\*3, 4\*1, 4\*3) which equals (1,3,2,6,4,12) -> (1,2,3,4,6,12), giving us all our factors.   

A divisor of a number consists of all combination of products of the prime powers. So, for each prime power p<sup>a</sup>, we can choose up to include p up to a times, 
plus one more for "not including" p, in which case we choose p<sup>0</sup> = 1.   
So, we have (a<sub>1</sub> + 1) choices for prime power p<sub>1</sub><sup>a<sub>1</sub></sup>, 
times (a<sub>2</sub> + 1) choices for prime power p<sub>2</sub><sup>a<sub>2</sub></sup>, ..., and so on, giving us our final equation.

##### Implementation

To find the prime factors of a number, we can iterate through all the primes and count how many times each prime divides N. 
It is useful to generate all possible primes beforehand to avoid recomputation. 

By the prime number theorem, the number of primes we will iterate through for each test case N is O(n / log n) but since no factor can exceed sqrt(n), a tighter bound would be 
O(sqrt(n) / log sqrt(n)) which is better than O(sqrt(n)).

#### Search
With more test cases, the problem becomes more computationally heavy if we have to iterate through all the triangular numbers each time.
However, notice that we only need to return the ***first*** triangular number that ***has more than N divisors***. i.e.,   
suppose some triangular number has 100 divisors, a larger triangular number has 90 divisors, and we wish to solve for N=90.  
We would return the triangular number with 100 divisors since it occured first.

Therefore, we only need to generate triangular numbers until we reach the first one that has more than our constriant, 1000 divisors.

Then, we can perform a modified binary search where we use number of divisors as key and the associated triangular number as the value. Then, we search for 
the largest number of divisors less than or equal to N and instead of returning this value, we return the value to the right.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/012%20-%20Highly%20divisible%20triangular%20number/solution.cpp)
##
#### Further Reading

https://en.wikipedia.org/wiki/Triangular_number

https://en.wikipedia.org/wiki/Divisor_function

https://en.wikipedia.org/wiki/Integer_factorization

https://cp-algorithms.com/algebra/factorization.html


