# Project Euler #67: Maximum path sum II

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/067%20-%20Maximum%20path%20sum%20II/solution.md)

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is **23**. 
The path is denoted by numbers in bold.
    
&nbsp; &nbsp; &nbsp; &nbsp;**3**   
&nbsp; &nbsp; &nbsp; **7** 4   
&nbsp; &nbsp; 2 **4** 6   
&nbsp; 8 5 **9** 3   

That is, **3 + 7 + 4 + 9 = 23**.

Find the maximum total from top to bottom of the triangle given in input.

### Input Format

First line contains **T**, the number of testcases. For each testcase:
First line contains **N**, the number of rows in the triangle.
For next **N** lines, **i**'th line contains **i**  numbers.

### Constraints
- 1 &le; T &le; 10
- 1 &le; N &le; 100
- Each element of triangle lies between 0 and100 (both inclusive).


### Output Format

For each testcase, print the required answer in a newline.

### Sample Input

```
2
4
3
7 4
2 4 6
8 5 9 3
4
3
7 4
2 4 6
8 5 9 3
```

### Sample Output

```
23
23
```
