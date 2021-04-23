# Project Euler #9: Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, **a < b < c** , for which,
<div align='center'>
  <b>a<sup>2</sup> + b<sup>2</sup> =  c<sup>2</sup></b>
  </div>

For example, **3<sup>2</sup> + 4<sup>2</sup> = 9 + 16 = 25 = 5<sup>2</sup>**

Given **N**, Check if there exists any Pythagorean triplet for which **a + b + c = N**.
Find maximum possible value of **abc** among all such Pythagorean triplets, If there is no such Pythagorean triplet print **-1**.

#### Input Format

The first line contains an integer **T** i.e. number of test cases.
The next **T**  lines will contain an integer **N**.

Constraints
- **1 &le; T &le; 3000**
- **1 &le; N &le; 3000**

#### Output Format

Print the value corresponding to each test case in separate lines.

Sample Input 0
```
2
12
4
```
Sample Output 0
```
60
-1
```
Explanation 0

- For **N = 12**, we have a triplet **{3, 4, 5}** , whose product is **60**.
- For **N = 4**, we don't have any pythagorean triple.
