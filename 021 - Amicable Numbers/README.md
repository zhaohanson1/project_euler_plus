# Project Euler #21: Amicable numbers

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/021%20-%20Amicable%20Numbers/solution.md)

Let **d(n)** be defined as the sum of proper divisors of **n**  (numbers less than **n** which divide evenly into **n**).  
If **d(a) = b** and  **d(b) = a**, where **a &ne; b**, then **a** and **b**  are an amicable pair and each of **a** and **b** are called amicable numbers.  

For example, the proper divisors of **220** are  
**1,2,4,5,10,11,20,22,44,55, and 110** therefore **d(220) = 284**. 
The proper divisors of **284** are **1,2,4,71, and 142** so **d(284) = 220**.

Evaluate the sum of all the amicable numbers under **N**.

### Input Format

The first line contains an integer **T**, i.e., number of test cases.   
Next **T**  lines will contain an integer **N**.

### Constraints
- 1 &le; T &le; 1000
- 1 &le; N &le; 10<sup>5</sup>

### Output Format

Print the values corresponding to each test case.

### Sample Input

```
1
300
```

### Sample Output

```
504
```

### Explanation

Under **300** we only have **220** and **284**, sum is **504**
