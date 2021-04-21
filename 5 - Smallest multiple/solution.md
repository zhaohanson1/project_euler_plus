## Naive
Check every number starting from N if it is divisible by all numbers from 1 to N and return the first number that is divisible by all.
```
i = N
while True:
  for j := 1 to N:
    if i is not divisible j:
      i += 1
      continue
  output i
```

## Better
We can see this is just the general defintion of the least common multiple. 

Formally, we want to compute
  <div align='center'>
  <img src="https://latex.codecogs.com/gif.latex?\dpi{100}&space;\bg_white&space;\large&space;lcm(1,2,\ldots,N)" title="\large lcm(1,2,\ldots,N)" />
  </div>
  
This can be computed in many ways, but we will choose a way that allows us to precompute all LCMs up to our constraint, 40.

The LCM can be computed using the GCD using the following formula,
<div align='center'>
  <img src="https://latex.codecogs.com/gif.latex?\dpi{100}&space;\bg_white&space;\large&space;lcm(a,b)&space;=&space;\frac{|a&space;\cdot&space;b|}{gcd(a,b)}" />
</div>

Also, <div align='center'>
<img src="https://latex.codecogs.com/gif.latex?\dpi{100}&space;\bg_white&space;\large&space;lcm(a_1,a_2,\ldots,&space;a_n)&space;=&space;lcm((a_1,a_2,\ldots,a_{n-1}&space;),&space;a_n)" />
</div>

which breaks down recursively to, 
<div align='center'>
<img src="https://latex.codecogs.com/gif.latex?\dpi{100}&space;\bg_white&space;\large&space;lcm(a_1,a_2,\ldots,&space;a_n)&space;=&space;lcm(lcm(\ldots&space;lcm(lcm(a_1,a_2),&space;a_3)\ldots),a_{n-1}&space;),&space;a_n))" title="\large lcm(a_1,a_2,\ldots, a_n) = lcm(lcm(\ldots lcm(lcm(a_1,a_2), a_3)\ldots),a_{n-1} ), a_n))" />
</div>

So, we can compute the LCMs with dynamic programming by refering to the previous LCMs.

Then for each test, we can simply return the nth LCM.


[Solution Code](https://github.com/zhaohanson1/project_euler_plus/edit/master/5%20-%20Smallest%20multiple/solution.py)
