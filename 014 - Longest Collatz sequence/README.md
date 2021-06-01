# Project Euler #14: Longest Collatz sequence

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/014%20-%20Longest%20Collatz%20sequence/solution.md)

The following iterative sequence is defined for the set of positive integers:
<div align="center">
  <a href="https://www.codecogs.com/eqnedit.php?latex=\inline&space;\bg_white&space;\begin{align*}&space;n&space;&\rightarrow&space;\frac{n}{2}&space;&\text{n&space;is&space;even}&space;\\&space;n&space;&\rightarrow&space;3n&space;&plus;&space;1&space;&\text{n&space;is&space;odd}&space;\\&space;\end{align*}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\inline&space;\bg_white&space;\begin{align*}&space;n&space;&\rightarrow&space;\frac{n}{2}&space;&\text{n&space;is&space;even}&space;\\&space;n&space;&\rightarrow&space;3n&space;&plus;&space;1&space;&\text{n&space;is&space;odd}&space;\\&space;\end{align*}" title="\begin{align*} n &\rightarrow \frac{n}{2} &\text{n is even} \\ n &\rightarrow 3n + 1 &\text{n is odd} \\ \end{align*}" /></a>
 </div>

Using the rule above and starting with 13, we generate the following sequence:
<div align="center">
13 &rarr; 40 &rarr; 20 &rarr; 10 &rarr; 5 &rarr; 16 &rarr; 8 &rarr; 4 &rarr; 2 &rarr; 1
  </div>
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, &le; **N** produces the longest chain? If many possible such numbers are there print the maximum one.

Note: Once the chain starts the terms are allowed to go above **N**.

**Input Format**

The first line contains an integer **T** , i.e., number of test cases.
Next **T**  lines will contain an integers **N**.

**Constraints**
* 1 &le; T &le; 10<sup>4</sup>
* 1 &le; N &le; 5 x 10<sup>6</sup>

**Output Format**

Print the values corresponding to each test case.

**Sample Input**
```
3
10 
15
20
```

**Sample Output**
```
9
9
19
```

**Explanation**

Collatz sequence for **n = 9** is,
<div align="center">
  9 &rarr; 28 &rarr; 14 &rarr; 7 &rarr; 22 &rarr; 11 &rarr; 34 &rarr; 17 &rarr; 52 &rarr; 26 &rarr; 13 &rarr; 40 &rarr; 20 &rarr; 10 &rarr; 5 &rarr; 16 &rarr; 8 &rarr; 4 &rarr; 2 &rarr; 1
</div>

containing **19** steps and is the longest for **n** &le; **10**
