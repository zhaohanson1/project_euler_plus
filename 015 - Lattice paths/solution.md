## Explanation 
Instead of generating all possible paths, notice that a path consists of moves to the right and down. 
A path always of length **N+M** and consists of exactly **N** moves down and **M** moves right.
The difference between the paths is the order of down moves and right moves.

Let there be a **2 x 2** grid as with the example. Then all paths must be of length 4.
<div align='center'><b>_ _ _ _</b></div>
Let's choose where to put our 2 right moves:
<div align='center'><b>_ R R _</b></div>
We see that our remaining spots must be down moves
<div align='center'><b>D R R D</b></div>

This reduces to a combinatorial problem; we simple need to compute modulo **(10<sup>9</sup> + 7)**
<div align='center'>
  <img src="https://latex.codecogs.com/gif.latex?\binom{N&plus;M}{N}&space;\mod{10^9&plus;7}" title="\binom{N+M}{N} \mod{10^9+7}" />
</div>

(Note choosing the down moves first and computing <img src="https://latex.codecogs.com/gif.latex?\inline&space;\binom{N&plus;M}{M}" title="\binom{N+M}{M}" /> also works.)

For the **2x2** example, we can list out all the paths and verify our solution matches.
<div align='center'><b>R R D D</b></div>
<div align='center'><b>R D R D</b></div>
<div align='center'><b>R D D R</b></div>
<div align='center'><b>D R R D</b></div>
<div align='center'><b>D R D R</b></div>
<div align='center'><b>D D R R</b></div>
<div align='center'><img src="https://latex.codecogs.com/gif.latex?\binom{4}{2}&space;=&space;6" title="\binom{4}{2} = 6" /></div>

## Computing binomial coefficients
The formula for binomial coefficients is 
<div align='center'>
<img src="https://latex.codecogs.com/gif.latex?\binom{n}{k}&space;=&space;\frac{n!}{k!(n-k)!}" title="\binom{n}{k} = \frac{n!}{k!(n-k)!}" />
  </div>


However, computing large factorials may cause integer overflow. 

Instead, use the fact that we are computing modulo and our modulo is prime.
Division in modulo is defined as multiplying the numerator with the multiplicative modular inverse of the denominator. 

So, 

<img src="https://latex.codecogs.com/gif.latex?\binom{n}{k}&space;\equiv&space;\frac{n!}{k!(n-k)!}&space;\equiv&space;n!&space;\cdot&space;(k!)^{-1}&space;\cdot&space;((n-k)!)^{-1}&space;\mod(10^9&space;&plus;&space;7)" title="\binom{n}{k} \equiv \frac{n!}{k!(n-k)!} \equiv n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1} \mod(10^9 + 7)" />

To compute the inverse, we can use Fermat's Little Theorem which states given a prime number p, for any integer a
  <div align='center'>
  <img src="https://latex.codecogs.com/gif.latex?a^p&space;\equiv&space;a&space;\mod{p}" title="a^p \equiv a \mod{p}" />
  </div>
 
If a is not divisible by p, we can multiple both sides by a<sup>-2</sup> to get 
<div align='center'>
<img src="https://latex.codecogs.com/gif.latex?a^{p-2}&space;\equiv&space;a^{-1}&space;\mod{p}" title="a^{p-2} \equiv a^{-1} \mod{p}" />
</div>
So, to get the modular inverse of an integer a, we can raise a to the p-2 power. We can improve the runtime of this computation with repeated squaring.

Multiplying factorials together may cause overflow before we can compute the modulo of the product, but we can use the property that 
<div align='center'>
<img src="https://latex.codecogs.com/gif.latex?ab&space;\mod{m}&space;\equiv&space;[(a&space;\mod&space;m)&space;(b&space;\mod&space;m)]&space;\mod&space;m" title="ab \mod{m} \equiv [(a \mod m) (b \mod m)] \mod m" />
</div>

For numbers that are still quite large, we may still encounter integer overflow, but we can use fact that multiplication is repeated addition:
  <div align='center'>
  <b>ab = a + a + a + ... </b> (b times)
  </div>
and the property:
<div align='center'>
<img src="https://latex.codecogs.com/gif.latex?(a&space;&plus;&space;b)&space;\mod&space;m&space;=&space;[(a&space;\mod&space;m)(b&space;\mod&space;m)]&space;\mod&space;m" title="(a + b) \mod m = [(a \mod m)(b \mod m)] \mod m" />
  </div>

We can precompute our factorials (modulo m) up to (500+500)!=1000! to avoid recomputing for every test case.

So, our final equation to compute is 
<div align='center'>
  <img src="https://latex.codecogs.com/gif.latex?[(n!&space;\mod&space;m)&space;\cdot&space;((k!)^{-1}&space;\mod&space;m)&space;\cdot&space;(((n-k)!)^{-1}&space;\mod&space;m)]&space;\mod&space;m" title="[(n! \mod m) \cdot ((k!)^{-1} \mod m) \cdot (((n-k)!)^{-1} \mod m)] \mod m" />
  </div>
  
 [Solution code](https://github.com/zhaohanson1/project_euler_plus/blob/master/015%20-%20Lattice%20paths/solution.cpp)


### Additional Sources
https://cp-algorithms.com/combinatorics/binomial-coefficients.html#toc-tgt-9

https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
