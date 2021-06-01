# Project Euler #18: Maximum path sum I

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/018%20-%20Maximum%20path%20sum%20I/solution.md)

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is **23**. 
The path is denoted by numbers in bold.
    
&nbsp; &nbsp; &nbsp; &nbsp;**3**   
&nbsp; &nbsp; &nbsp; **7** 4   
&nbsp; &nbsp; 2 **4** 6   
&nbsp; 8 5 **9** 3   

That is, **3 + 7 + 4 + 9 = 23**.

Find the maximum total from top to bottom of the triangle given in input.

### Input Format

The first line contains an integer **T**, i.e., number of test cases.   
Each testcase will contain two lines    
Y<sub>1</sub> M<sub>1</sub> D<sub>1</sub> on first line denoting starting date.   
Y<sub>2</sub> M<sub>2</sub> D<sub>2</sub> on second line denoting ending date.    

### Constraints
- 1 &le; T &le; 100
- 1900 &le; Y<sub>1</sub> &le; 10<sup>16</sup>
- Y<sub>1</sub> &le; Y<sub>2</sub> &le; (Y<sub>1</sub> + 1000)
- 1 &le; M<sub>1</sub>, M<sub>2</sub> &le; 12
- 1 &le; D<sub>1</sub>, D<sub>2</sub> &le; 31

### Output Format

Print the values corresponding to each test case.

### Sample Input

```
2
1900 1 1
1910 1 1
2000 1 1
2020 1 1
```

### Sample Output

```
18
35
```

### Explanation

For testcase 1, we have the following sundays :-

```
1 April 1900
1 July 1900
1 September 1901
1 December 1901
1 June 1902
1 February 1903
1 March 1903
1 November 1903
1 May 1904
1 January 1905
1 October 1905
1 April 1906
1 July 1906
1 September 1907 
1 December 1907
1 March 1908
1 November 1908
1 August 1909
```
