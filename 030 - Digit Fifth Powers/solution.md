Brute force but constrained.

We can check every number from 10 to 9<sup>N+1</sup>. Why? The number line which grow much faster than the sum of powers of its digits.

For powers of 4s, notice that 9<sup>4</sup>=6561. Multiple this by 5 and you get 32805. This represents 99999 which already exceeds the sum, so any number larger cannot satisfy our condition.


### Psuedocode
Generate all digit's powers of N to precompute them.

Check numbers from 10 to 10<sup>N+2</sup> to see if the sum of powers of the digits equals itself.

Then, sum up the numbers you found.
