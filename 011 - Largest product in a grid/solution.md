
This problem involves figuring out how to traverse all possible sequences of length 4 of adjacent numbers.

Using a 5x5 grid, we must traverse:

##### In each row:

__10 11 12 13__ 14  
15 16 17 18 19  
20 21 22 23 24  
25 26 27 28 29  
30 31 32 33 34  

10 11 12 13 14  
15 **16 17 18 19**  
20 21 22 23 24  
25 26 27 28 29  
30 31 32 33 34  

##### In each col:

10 **11** 12 13 14  
15 **16** 17 18 19  
20 **21** 22 23 24  
25 **26** 27 28 29  
30 **31** 32 33 34  

10 11 12 13 14  
15 16 17 **18** 19  
20 21 22 **23** 24  
25 26 27 **28** 29  
30 31 32 **33** 34  

##### Every down-sloped facing diagonal:

10 11 12 13 14  
15 **16** 17 18 19  
20 21 **22** 23 24  
25 26 27 **28** 29  
30 31 32 33 **34**  

10 **11** 12 13 14  
15 16 **17** 18 19  
20 21 22 **23** 24  
25 26 27 28 **29**  
30 31 32 33 34  

##### Every up-sloped diagonal:

10 11 12 13 14  
15 16 17 **18** 19  
20 21 **22** 23 24  
25 **26** 27 28 29  
**30** 31 32 33 34  

10 11 12 13 14  
15 16 17 18 **19**  
20 21 22 **23** 24  
25 26 **27** 28 29  
30 **31** 32 33 34  


Traverse by row and column should be straightforward.

For traversing every diagonal, we have a starting row or column. 
Then, for a downward slope, we advance down a row and right a column until we reach a boundary. 
For an upward slope, we advance down a row and and left a column until we reach a boundary.


To compute the product of a sequence, this is similar to Problem 8 
where we using a sliding window technique to move our sequence 
and keep track of the number of zeros in our current window to know when our product is non-zero.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/11%20-%20Largest%20product%20in%20a%20grid/solution.py)

[Solution Code Annotated](https://github.com/zhaohanson1/project_euler_plus/blob/master/11%20-%20Largest%20product%20in%20a%20grid/solution_annotated.py)
