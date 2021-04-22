# Project Euler #8: Largest product in a series
[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/008%20-%20Largest%20product%20in%20a%20series/solution.md)

Find the greatest product of **K** consecutive digits in the **N** digit number.

**Input Format**

First line contains **T** that denotes the number of test cases. 

First line of each test case will contain two integers **N & K**.

Second line of each test case will contain a **N** digit integer.

**Constraints**
* 1 &le; T &le; 100
* 1 &le; K &le; 7
* K &le; N &le; 1000

**Output Format**

Print the required answer for each test case.

**Sample Input 0**
```
2
10 5
3675356291
10 5
2709360626
```

**Sample Output 0**
```
3150
0
```

**Explanation 0**
- For **3675356291** and selecting **K=5** consequetive digits, we have **36753, 67535, 75356, 53562, 35629 and 56291.** Where **6 x 7 x 5 x 3 x 5** gives maximum product as **3150**.
- For **2709360626**, **0** lies in all selection of **5**  consequetive digits hence maximum product remains **0**.
