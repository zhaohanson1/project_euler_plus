The idea is to divide out all the other primes factors from N and we will be left with the largest prime factor.

### Naive
Iterate from 1 to N, check if our current number is prime by checking all possible factors 2 to N-1. 

If the current number is prime, if the remaining factor is equal, then this must be the largest factor.

Otherwise, try to divide out all this factor from N.

```
number = N
for i := 1 to N, do
  for j := 2 to i-1:
    if i % j == 0:
      continue
  if number == i:
    output number
  else:
    while number % i:
      number /= i
```

### Improvement
We can generate primes faster using the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes). This algorithm is as follows,

```
Create a list of integers from 2 to N.
for i := 2 to N:
  If i is marked as prime, continue
  Else, iterate through all multiples of i and mark as them as composite
All unmarked numbers are prime
```

However, our largest value for N is 10<sup>12</sup>, and generating all primes up to this number will take up a lot of memory. 

> (Note, we only need to generate primes up to floor(sqrt(10<sup>12</sup>)) + 1, since no factor of any number smaller than 10<sup>12</sup> will be larger than this number, but this still takes quite a bit of memory.)

We can use the [segmented version of the sieve](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Segmented_sieve) instead which reduces the memory required by will still generate all primes up to some number. 

[Solution code](https://github.com/zhaohanson1/project_euler_plus/blob/master/003%20-%20Largest%20prime%20factor/solution.cpp)
