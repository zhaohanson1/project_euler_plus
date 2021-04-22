# Project Euler #6: Sum square difference
[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/006%20-%20Sum%20square%20difference/solution.md)

The sum of the squares of the first ten natural numbers is, **1<sup>2</sup> + 2<sup>2</sup> + ... + 10<sup>2</sup> = 385**. 

The square of the sum of the first ten natural numbers is, **(1 + 2 + ... + 10)<sup>2</sup> = 55<sup>2</sup> = 3025**. 

Hence the absolute difference between the sum of the squares of the first ten natural numbers and the square of the sum is **3025 - 385 = 2640**.

Find the absolute difference between the sum of the squares of the first **N** natural numbers and the square of the sum.

**Input Format**

First line contains **T** that denotes the number of test cases. This is followed by **T** lines, each containing an integer, **N** .

**Constraints**
* 1 &le; T &le; 10<sup>4</sup>
* 1 &le; N &le; 10<sup>4</sup>

**Output Format**

Print the required answer for each test case.

**Sample Input 0**
```
2
3
10
```

**Sample Output 0**
```
22
2640
```

**Explanation 0**
- For **N=3, (1 + 2 + 3)<sup>2</sup> - (1<sup>2</sup> + 2<sup>2</sup> + 3<sup>2</sup>) = 22**
- For **N=10, (1 + 2 + ... + 10)<sup>2</sup> + (1<sup>2</sup> + 2<sup>2</sup> + ... + 10<sup>2</sup>) = 2640**
