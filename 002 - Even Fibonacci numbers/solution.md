# Naive
For each N, we can generate all Fibonacci numbers up to N. 

While generating, check which numbers are even and keep a total sum. 

```
for each test T:
  a, b := 1, 1
  sum = 0
  while b <= N, do:
    c := a + b
    a := b
    b := c
    if c is even:
      sum += c
   output sum
```

# Improvements

### Generate only the even Fibonacci Numbers
If we look at the sequence of the first few even Fibonacci numbers,
  <div align='center'><b>2, 8, 34, 144, ...</b></div>
 Notice the nth even Fibonacci number is 4 times the n-1th term plus the n-2th term.

```
0 + 4 * 2 = 8
2 + 4 * 8 = 34
8 + 4 * 34 = 144
```
### Caching the sum and binary search
Instead of recomputing the sum everytime, we can store the partial sum along with the maximum even Fibonacci number it is associated with.
<div align='center'> <b> <2, 2>, <8, 10>, <34, 44>, ... </b> </div>

Searching for the correct term naively would still take linear time, but we can use binary search with the maximum term as our key 
and find the largest term that is smaller than or equal to N.

Doing so reduces our summation operation time from O(n) to a search operation of O(log n).

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/002%20-%20Even%20Fibonacci%20numbers/solution.py)
