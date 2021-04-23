This problem involves generating primes. 
Our algorithm is similar to Problem 3 but instead of terminating when we encounter our first prime that is divides N, we terminate when we encounter our Nth prime.

As with problem 3, we can generate primes with a segmented Sieve of Eranotheses. 

We can precompute all primes up to our constriant and then for each test case, we simply lookup the required prime.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/007%20-%2010001st%20Prime/solution.cpp)
