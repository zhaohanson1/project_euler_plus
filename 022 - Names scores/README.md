# Plus

## Project Euler #22: Names scores

[Solution](https://github.com/zhaohanson1/project_euler_plus/blob/master/022%20-%20Names%20scores/solution.md)

You are given around five-thousand first names, begin by sorting it into alphabetical order. 
Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list in sample is sorted into alphabetical order, PAMELA, 
which is worth **16 + 1 + 13 + 5 + 12 + 1 = 48**, is the  name in the list. 
So, PAMELA would obtain a score of **5 x 48 = 240**.

You are given **Q** queries, each query is a name, you have to print the score.

### Input Format

The first line contains an integer **N**, i.e., number of names.  
Next **N**  lines will contain a Name.  
Followed by integer **Q** followed by **Q** lines each having a word.

### Constraints
- 1 &le; N &le; 5200
- length of each word will be less than 12
- 1 &le; Q &le; 100

### Output Format

Print the values corresponding to each test case.

### Sample Input

```
5
ALEX
LUIS
JAMES
BRIAN
PAMELA
1
PAMELA
```

### Sample Output

```
240
```

### Explanation

Explained in statement.


# Classic

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. 
Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, 
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
