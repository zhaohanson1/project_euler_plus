### 0 - 10
We can simply "call" the word for the corresponding number.

### 11 - 19
These numbers are a special case that do not follow the "-ty X" pattern, so we need to "call" these as well. 

### 20 - 99
These numbers follow the patter "-ty X" where the digit in the tens place determines the suffix of "-ty".
and the digit in the ones is simply appended.

### 100 - 999
The digit is hundreds place is called as a single digit, then "hundred" is appended.
The last 2 digits follow the same patterns as if they were by themselves and are appended to the current word. 

### 1000 and up
English numerals are split into powers of 1000, so we should split our input into groups of 3 digits.
Within each group, we form the number into words as we usually would, 
then we append the corresponding segment the group belongs to, i.e. Thousand, Million, Billion, Trillion.

### Algorithm:
We will partition the number into groups of size 3 by getting the last 3 digits with N % 1000, then getting the next 3 with floor(N/1000). 
This requires our base case to be when N == 0, so we have a special conditional check in the beginning for when N=0.

We preload each of the required strings for each segment word, each "X-ty" word, and each single digit word and the special cases up to 19.

For each group, we check if there is a digit in the hundreds place and index the words accordingly. 
Then, we check the last two digits. If the number is larger than 19, then we follow the "-ty" pattern and index for both digits. Otherwise, we index for single and special cases.

For numbers than have 0s in some digit places, make sure the corresponding words are ignored, e.g. 1,010,000 should not be One Million Zero Hundred Ten Thousand Zero.

We join all the words together and get our final result.

# 

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/017%20-%20Number%20to%20Words/solution-plus.py)
