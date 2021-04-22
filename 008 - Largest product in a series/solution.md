## Naive
For each digit as the starting sequence, compute the product of the following k digits and keep track of the maximum.

## Improvements
The above algorithm runs in quadratic time. We can utilize the sliding window technique to achieve linear time instead

#### Sliding window
Instead of computing the product for each sequence, notice that adjacent subseqences share the same terms. 
In fact, two adjacent subsequences only differ in the first and last term.
When computing the product of a sequence, we can drop the last value of the previous sequence by dividng, 
then add the first value of the next sequence by multiplying.

However, if our sequence contains 0, then our product will be 0 and if the next sequence contains all non-zero terms, the product should be nonzero, 
but dividing from and multiplying with 0 results in 0.

#### Zero Product
To remedy this, we can keep track of the number of zeros in our current sequence.
When we have zeros in our sequence, we treat our current product as zero, but keep track of the product of the other values.
When we have no more zeros, then we can treat our product as nonzero and compare it to the current maximum.


[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/008%20-%20Largest%20product%20in%20a%20series/solution.cpp)
