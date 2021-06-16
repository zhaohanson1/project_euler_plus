# Project Euler #25: N-digit Fibonacci number

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/025%20-%20N-digit%20Fibonacci%20number/solution.md)

The Fibonacci sequence is defined by the recurrence relation:
  <div align='center'>
  <a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;F_n&space;=&space;F_{n-1}&plus;F_{n-2},&space;\text{where&space;}F_1=1\text{&space;and&space;}F_2=1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;F_n&space;=&space;F_{n-1}&plus;F_{n-2},&space;\text{where&space;}F_1=1\text{&space;and&space;}F_2=1" title="F_n = F_{n-1}+F_{n-2}, \text{where }F_1=1\text{ and }F_2=1" /></a>
  </div>.

Hence the first 12 terms will be:
  <div align='center'>
<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\begin{align*}&space;F_1&space;&=&space;1&space;\\&space;F_2&space;&=&space;1&space;\\&space;F_3&space;&=&space;2&space;\\&space;F_4&space;&=&space;3&space;\\&space;F_5&space;&=&space;5&space;\\&space;F_6&space;&=&space;8&space;\\&space;F_7&space;&=&space;13&space;\\&space;F_8&space;&=&space;21&space;\\&space;F_9&space;&=&space;34&space;\\&space;F_{10}&space;&=&space;55\\&space;F_{11}&space;&=&space;89\\&space;F_{12}&space;&=&space;144&space;\end{align*}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\begin{align*}&space;F_1&space;&=&space;1&space;\\&space;F_2&space;&=&space;1&space;\\&space;F_3&space;&=&space;2&space;\\&space;F_4&space;&=&space;3&space;\\&space;F_5&space;&=&space;5&space;\\&space;F_6&space;&=&space;8&space;\\&space;F_7&space;&=&space;13&space;\\&space;F_8&space;&=&space;21&space;\\&space;F_9&space;&=&space;34&space;\\&space;F_{10}&space;&=&space;55\\&space;F_{11}&space;&=&space;89\\&space;F_{12}&space;&=&space;144&space;\end{align*}" title="\begin{align*} F_1 &= 1 \\ F_2 &= 1 \\ F_3 &= 2 \\ F_4 &= 3 \\ F_5 &= 5 \\ F_6 &= 8 \\ F_7 &= 13 \\ F_8 &= 21 \\ F_9 &= 34 \\ F_{10} &= 55\\ F_{11} &= 89\\ F_{12} &= 144 \end{align*}" /></a>
  </div>
  
The **12<sup>th</sup>** term, **F<sub>12</sub>**, is the first term to contain three digits.  
What is the first term in the Fibonacci sequence to contain **N** digits?

### Input Format

The first line contains an integer **T**, i.e., number of test cases.   
Next **T**  lines will contain an integer **N**.

### Constraints

1 &le; T &le; 5000  
2 &le; N &le; 5000

### Output Format

Print the values corresponding to each test case.

### Sample Input

```
2
3
4
```

### Sample Output

```
12
17
```
