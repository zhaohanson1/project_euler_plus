We want to add all the multiples of 3 plus all the multiples of 5 and then subtract the multiples of 15 since these are counted twice.

For integer k, if we wish to add the multiples of k up to N, this sum is 
   <div align="center">
    <img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_white&space;k&space;&plus;&space;2k&plus;3k&plus;\ldots&plus;a_{n-1}k&space;&plus;&space;a_nk" title="k + 2k+3k+\ldots+a_{n-1}k + a_nk" />
   </div>
 where a<sub>n</sub>k is the largest multiple of k less than or equal to N.
Notice we can factor out k from the summation, so our sum is
  <div align="center">
    <img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_white&space;k&space;(1&space;&plus;&space;2&space;&plus;&space;3&plus;&space;\ldots&space;&plus;&space;a_{n-1}k&space;&plus;&space;a_nk)" title="k (1 + 2 + 3+ \ldots + a_{n-1}k + a_nk)" />
  </div>
To compute a<sub>n</sub>, we can compute the floor of N/k using floor division.

To sum up to a<sub>n</sub>, we can compute this in O(1) time using Gauss' Formula,
  <div align="center">
    <img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_white&space;\frac{n(n&plus;1)}{2}" title="\frac{n(n+1)}{2}" />
  </div>
 which leads us to the answer to our final algorithm:
 
 
 Let <img src="https://latex.codecogs.com/gif.latex?\inline&space;\bg_white&space;\small&space;a&space;=&space;\left&space;\lfloor&space;N/3&space;\right&space;\rfloor,&space;b&space;=&space;\left&space;\lfloor&space;N/5&space;\right&space;\rfloor,&space;c&space;=&space;\left&space;\lfloor&space;N/15&space;\right&space;\rfloor" title="\small a = \left \lfloor N/3 \right \rfloor, b = \left \lfloor N/5 \right \rfloor, c = \left \lfloor N/15 \right \rfloor" />,
 
 Compute
 <div align="center">
  <img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_white&space;\frac{a(a&plus;1)}{2}&space;&plus;&space;\frac{b(b&plus;1)}{2}&space;-&space;\frac{c(c&plus;1)}{2}" title="\frac{a(a+1)}{2} + \frac{b(b+1)}{2} - \frac{c(c+1)}{2}" />
 </div>
 
