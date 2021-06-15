* Generating/Finding Amicable Numbers (up to 10^5)
  * sum of proper divisors
  * traversal and checking if d(a)=b, d(b)=a
  * lookup

### Generating Amicable Numbers


#### Sum of Proper Divisors
##### Sum of Divisors is Product of Sum of Divisors of Prime Powers
Example: S(18) = S(2) * S(3^2) = (1+2) * (1+3+9) = (1+3+9+2+6+18) = (1+2+3+6+9+18)
##### Sum of Divisiors of Prime Powers

The divisors of a prime power, p<sup>k</sup>, are the powers of the prime up to k. That is,
<div align="center">
  <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\sigma_1(p^k)&space;=&space;1&space;&plus;&space;p&space;&plus;&space;p^2&space;&plus;&space;\ldots&space;&plus;&space;p^k&space;=&space;\sum_{n=0}^k&space;p^n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\sigma_1(p^k)&space;=&space;1&space;&plus;&space;p&space;&plus;&space;p^2&space;&plus;&space;\ldots&space;&plus;&space;p^k&space;=&space;\sum_{n=0}^k&space;p^n" title="\sigma_1(p^k) = 1 + p + p^2 + \ldots + p^k = \sum_{n=0}^k p^n" /></a>
</div>

As we can see, this is a geometric progression, so we can use the geometric series equation, 
<div align="center">
  <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\begin{align*}&space;\sum_{n=0}^{k}&space;p^n&space;&=&space;\sum_{n=0}^{k&plus;1}&space;p^{n-1}&space;\\&space;&=&space;\frac{1-p^{k&plus;1}}{1-p}&space;\\&space;&=&space;\frac{-1(p^{k&plus;1}-1)}{-1(p-1)}&space;\\&space;&=&space;\frac{p^{k&plus;1}-1}{p-1}&space;\end{align*}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\begin{align*}&space;\sum_{n=0}^{k}&space;p^n&space;&=&space;\sum_{n=0}^{k&plus;1}&space;p^{n-1}&space;\\&space;&=&space;\frac{1-p^{k&plus;1}}{1-p}&space;\\&space;&=&space;\frac{-1(p^{k&plus;1}-1)}{-1(p-1)}&space;\\&space;&=&space;\frac{p^{k&plus;1}-1}{p-1}&space;\end{align*}" title="\begin{align*} \sum_{n=0}^{k} p^n &= \sum_{n=0}^{k+1} p^{n-1} \\ &= \frac{1-p^{k+1}}{1-p} \\ &= \frac{-1(p^{k+1}-1)}{-1(p-1)} \\ &= \frac{p^{k+1}-1}{p-1} \end{align*}" /></a>
 </div>
S(p^k) = (1 + p + p^2 + ... + p^k) = geometric progression

#### Sum of Amicable Numbers

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/021%20-%20Amicable%20Numbers/solution.cpp)


## Further Reading

https://en.wikipedia.org/wiki/Divisor_function

https://en.wikipedia.org/wiki/Geometric_progression
