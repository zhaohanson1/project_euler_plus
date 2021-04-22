### Naive

Brute Force
```
for each test T:
  compute a = (1+2+...+N)^2
  compute b = (1^2 + 2^2 + ...+N^2)
  output a - b
```

#### Possible improvements
Compute the first term using Gauss' formula, then squaring the result.

Precompute all possible sum of squares by in linear time with **F(n) = F(n-1) + n<sup>2</sup>**.

The problem with this method is both terms may become very large as n increases, causing integer overflow.

### Better
Rearrange the terms of the equation into a recurrence relation. 
<div>
  <img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\bg_white&space;\begin{align*}&space;F(k)&space;&=&space;(1&plus;2&plus;\dots&plus;k)^2&space;-&space;(1^2&space;&plus;2^2&space;&plus;&space;\ldots&space;&plus;&space;k^2)&space;\\&space;&=&space;(\sum_{n=1}^k&space;n)^2&space;-&space;\sum_{n=1}^k&space;n^2\\&space;&=&space;((\sum_{n=1}^{k-1}&space;n)&space;&plus;&space;k)^2&space;-&space;((\sum_{n=1}^{k-1}&space;n^2)&space;&plus;&space;k^2)&space;&\text{(Group&space;in&space;terms&space;of&space;previous&space;terms)}\\&space;&=&space;(\sum_{n=1}^{k-1}&space;n)^2&space;&plus;&space;2k(\sum_{n=1}^{k-1}&space;n)&space;&plus;&space;k^2&space;-&space;(\sum_{n=1}^{k-1}&space;n^2)&space;-&space;k^2&space;&\text{(Binomial&space;expansion)}\\&space;&=&space;\[(\sum_{n=1}^{k-1}&space;n)^2&space;-&space;(\sum_{n=1}^{k-1}&space;n^2)\]&space;&plus;&space;2k(\sum_{n=1}^{k-1}&space;n)&space;&plus;&space;(k^2&space;-k^2)&space;&\text{(Group&space;like&space;terms)}\\&space;&=&space;[F(k-1)]&space;&plus;&space;2k&space;(\sum_{n=1}^{k-1}&space;n)\\&space;&=&space;[F(k-1)]&space;&plus;&space;\frac{2(k-1)k^2}{2}&space;&\text{(Gauss'&space;Formula)}\\&space;&=&space;[F(k-1)]&space;&plus;&space;(k-1)k^2&space;\end{align*}" title="\begin{align*} F(k) &= (1+2+\dots+k)^2 - (1^2 +2^2 + \ldots + k^2) \\ &= (\sum_{n=1}^k n)^2 - \sum_{n=1}^k n^2\\ &= ((\sum_{n=1}^{k-1} n) + k)^2 - ((\sum_{n=1}^{k-1} n^2) + k^2) &\text{(Group terms in terms of previous terms)}\\ &= (\sum_{n=1}^{k-1} n)^2 + 2k(\sum_{n=1}^{k-1} n) + k^2 - (\sum_{n=1}^{k-1} n^2) - k^2 &\text{(Binomial expansion)}\\ &= \[(\sum_{n=1}^{k-1} n)^2 - (\sum_{n=1}^{k-1} n^2)\] + 2k(\sum_{n=1}^{k-1} n) + (k^2 -k^2) &\text{(Group like terms)}\\ &= [F(k-1)] + 2k (\sum_{n=1}^{k-1} n)\\ &= [F(k-1)] + \frac{2(k-1)k^2}{2} &\text{(Gauss' Formula)}\\ &= [F(k-1)] + (k-1)k^2 \end{align*}" />
</div>
Then, we can precompute all sum square differences in linear time.


Compared to the previous method, we compute a relatively smaller number.

[Solution Code](https://github.com/zhaohanson1/project_euler_plus/blob/master/6%20-%20Sum%20square%20difference/solution.py)
